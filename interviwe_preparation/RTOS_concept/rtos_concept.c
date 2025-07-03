/*
 * Real-Time Operating System (RTOS) - Senior-Level Concepts
 *
 * Definition:
 * An RTOS is an operating system designed for real-time applications that require
 * deterministic timing and precise task execution.
 *
 * Key RTOS Concepts:
 * 1. **Task Scheduling**:
 *    - Preemptive Scheduling: Higher-priority tasks interrupt lower-priority tasks.
 *    - Round-Robin Scheduling: Equal time slices for tasks.
 *    - Rate Monotonic Scheduling (RMS): Fixed priority based on task frequency.
 *    - Earliest Deadline First (EDF): Dynamic priority based on deadlines.
 *
 *  * Context Switching in Operating Systems - Detailed Explanation
 *
 * Definition:
 * Context switching is the process of saving the execution state of a running process 
 * and restoring the state of another process, allowing multitasking and efficient CPU usage.
 *
 * How Context Switching Works:
 * 1. **Saving the State** - The OS stores the current process's registers, program counter, and stack.
 * 2. **Loading the State** - The OS retrieves the saved state of the next process scheduled to run.
 * 3. **Execution** - The CPU resumes execution of the new process from where it left off.
 *
 * Context Switching Block:
 * A **context switch block** stores the execution state of a process during switching.
 * The main components of this block include:
 *
 * struct context_switch_block {
 *     uint32_t registers[16];   // General-purpose registers (R0-R15)
 *     uint32_t program_counter; // Address of the next instruction
 *     uint32_t stack_pointer;   // Stack position during switch
 *     uint32_t status_register; // Flags and system state
 *     uint32_t process_id;      // ID of the current process
 * };
 *
 * Triggers for Context Switching:
 * - **Multitasking**: The scheduler switches processes to share CPU time.
 * - **Interrupt Handling**: Hardware interrupts trigger a switch to handle events.
 * - **User-Kernel Mode Switching**: A transition between user mode and kernel mode requires a context switch.
 *
 * Context Switching Overhead:
 * - **Time Delay**: The CPU spends time saving and restoring process states.
 * - **Memory Usage**: Each process requires storage for its execution context.
 * - **Performance Impact**: Excessive switching can slow down system performance.
 *
 * Summary:
 * - Context switching ensures efficient CPU utilization and multitasking.
 * - It involves saving process states, switching execution, and restoring states.
 * - Overhead from switching can impact performance but enables multi-process execution.
 * - This example demonstrates a **simple user-level context switch simulation**.
 *
 * 
 * 
 * Difference Between Mutex, Semaphore, and Flags in RTOS
 *
 * 1. Mutex (Mutual Exclusion):
 *    - Definition: A locking mechanism that ensures only one task accesses a shared resource at a time.
 *    - Usage: Used for **exclusive access** to prevent race conditions.
 *    - Behavior: Only the task that locks the mutex can unlock it.
 *    - Example: Used in **critical sections** where only one thread should modify data.
 *    - Limitation: Can lead to **priority inversion** if not handled properly.
 *
 * 2. Semaphore:
 *    - Definition: A signaling mechanism that allows multiple tasks to synchronize access to shared resources.
 *    - Types:
 *      - **Binary Semaphore**: Works like a mutex but does not enforce ownership.
 *      - **Counting Semaphore**: Allows multiple tasks to access a resource up to a defined limit.
 *    - Usage: Used for **task synchronization** and **resource management**.
 *    - Example: Used in **producer-consumer problems** where multiple tasks wait for an event.
 *    - Limitation: Does not prevent **race conditions** like a mutex.
 *
 * 3. Event Flags:
 *    - Definition: A mechanism for **event-driven task synchronization** using bit flags.
 *    - Usage: Used for **task notifications** when multiple events need to be tracked.
 *    - Behavior: Tasks wait for specific flag conditions before execution.
 *    - Example: Used in **interrupt-driven systems** where tasks wait for hardware events.
 *    - Limitation: Requires **proper flag management** to avoid incorrect event handling.
 *
 * Key Differences:
 * - **Mutex** ensures exclusive access to a resource.
 * - **Semaphore** allows multiple tasks to synchronize access.
 * - **Flags** provide event-driven task execution.
 *
/*
 * Kernel Modes in Operating Systems - Detailed Explanation
 *
 * Definition:
 * The operating system kernel operates in two primary modes to manage system resources 
 * and ensure secure execution: **User Mode** and **Kernel Mode**.
 *
 * 1. **User Mode**:
 *    - Restricted access to system resources.
 *    - Applications run in this mode to ensure security.
 *    - Cannot directly access hardware or memory.
 *    - Requires system calls to interact with the kernel.
 *    - If an application crashes, it does not affect the entire system.
 *
 * 2. **Kernel Mode**:
 *    - Full access to system resources.
 *    - Executes privileged operations like memory management and process control.
 *    - Handles system calls from user-mode applications.
 *    - Direct access to system hardware, I/O devices, and memory.
 *    - Any crash in kernel mode can lead to a system failure.
 *
 * Kernel Mode Operations:
 * - Process Scheduling
 * - Memory Management
 * - Interrupt Handling
 * - System Calls Execution
 * - Device Driver Communication
 *
 * Example - Mode Switching:
 */

// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <unistd.h>

// void user_mode() {
//     printf("Running in User Mode: Restricted access\n");
//     printf("Performing system call to switch to Kernel Mode...\n");

//     // System call to enter kernel mode (simplified representation)
//     int result = system("ls");  // Example system call
//     if (result == -1) {
//         printf("System call failed!\n");
//     }
// }

// int main() {
//     printf("Starting User Mode Process...\n");
//     user_mode();
//     printf("Back in User Mode after Kernel Mode execution.\n");
//     return 0;
// }

/*
 * Summary:
 * - The OS switches between User Mode and Kernel Mode for efficient task execution.
 * - User Mode ensures security by restricting direct access to hardware.
 * - Kernel Mode allows privileged operations required for system functionality.
 * - Proper mode handling prevents security breaches and system crashes.

 *
 * 4. **Interrupt Handling**:
 *    - ISR (Interrupt Service Routine) execution.
 *    - Nested Interrupts and Priority Levels.
 *    - Deferred Interrupt Processing using Task Notifications.
 *
 * 5. **Memory Management**:
 *    - Static vs. Dynamic Memory Allocation.
 *    - Heap Fragmentation and Memory Pools.
 *    - Stack Overflow Detection and Protection.
 *
 * 6. **RTOS Kernel Services**:
 *    - Task Creation and Deletion.
 *    - Timer Services for periodic execution.
 *    - Watchdog Timers for system reliability.
 *
 * 7. **Latency and Determinism**:
 *    - Worst-case execution time (WCET) analysis.
 *    - Jitter minimization for precise timing.
 *    - Real-time constraints in embedded systems.
 *
 * 8. **Power Management in RTOS**:
 *    - Tickless Mode for low-power operation.
 *    - Dynamic Voltage and Frequency Scaling (DVFS).
 *    - Sleep Modes and Wake-up Mechanisms.
 *
 * Summary:
 * - RTOS ensures deterministic task execution with minimal latency.
 * - Proper scheduling, IPC, and memory management are critical for efficiency.
 * - Understanding RTOS internals is essential for senior-level embedded development.
 */
