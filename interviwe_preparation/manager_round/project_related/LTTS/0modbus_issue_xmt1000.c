/**
 * @file    modbus_handler.c
 * @brief   Resolution of data corruption in XMT1000 dual-board Modbus architecture.
 * 
 * [ SITUATION ]
 * The XMT1000 utilizes a dual-board system (Main Board and Flow Board). 
 * The Main Board operates in two concurrent Modbus roles:
 *   1. Slave Mode: Responds to high-frequency data requests from a PC (Python Script).
 *   2. Master Mode: Periodically fetches operational data from the Flow Board.
 * 
 * [ TASK / PROBLEM ]
 * During stress testing, polling intervals of 100ms-200ms caused intermittent data 
 * corruption. The system would return "garbage" or mixed bytes to the PC.
 * 
 * [ ACTION / LOGIC ]
 * Identified that 'command_buffer' and 'output_buffer' were defined as GLOBAL variables.
 * In the RTOS environment, this created a non-reentrant scenario:
 *   - While Task A (Slave Response) was reading the buffer to send data to the PC, 
 *     Task B (Master Fetch) or a high-frequency Interrupt could overwrite the 
 *     same global buffer with new data.
 * 
 * I refactored the design to use LOCAL (stack-allocated) buffers within the task 
 * context. By moving buffers to the stack, each task instance obtained its own 
 * private memory space, making the Modbus handling logic "Thread-Safe."
 * 
 * [ RESULT ]
 * The race condition was eliminated. The system successfully passed high-frequency 
 * polling tests (100ms) without a single byte of corruption.
 * 
 * [ INTERVIEWER Q&A SUMMARY ]
 * Q1: Why local buffers? 
 * A1: They ensure reentrancy. Each RTOS task has its own stack; thus, each has its 
 *     own copy of the buffer, preventing cross-task memory overwrites.
 * 
 * Q2: Risks of this approach? 
 * A2: Stack Overflow. I had to increase the RTOS task stack size and verify 
 *     it using stack-watermark functions to ensure the local buffers fit safely.
 * 
 * Q3: Alternative if global buffers were mandatory? 
 * A3: Implement a Mutex or Semaphore to gate-keep access to the shared buffer, 
 *     ensuring only one task can write/read at a time.
 * 
 * Q4: Why did it only fail at 100-200ms? 
 * A4: At lower speeds, the tasks completed before the next one started. High 
 *     frequency increased the probability of "task preemption" occurring exactly 
 *     while the buffer was in use.
 */

/* Code Implementation Example */

// Before: Global buffers caused Race Conditions
// uint8_t g_modbus_buf[256]; 

/**
 * @brief Thread-safe Modbus processing task
 */
void vModbusSlaveTask(void *pvParameters) {
    /* 
     * FIX: Buffer is now allocated on this specific task's stack.
     * Each board transaction is now isolated.
     */
    uint8_t u8LocalCommandBuffer[256];
    uint8_t u8LocalResponseBuffer[256];

    while(1) {
        if (xReceiveModbusQuery(u8LocalCommandBuffer)) {
            vProcessModbusRequest(u8LocalCommandBuffer, u8LocalResponseBuffer);
            vSendModbusResponse(u8LocalResponseBuffer);
        }
    }
}
