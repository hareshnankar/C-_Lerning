/*
 * I2C (Inter-Integrated Circuit) Communication Protocol
 * 
 * Overview:
 * I2C is a two-wire serial communication protocol that allows multiple devices 
 * (masters and slaves) to share the same bus. It is commonly used in embedded systems 
 * to connect sensors, EEPROMs, RTCs, and other peripherals.
 *
 * Key Features:
 * - Uses two lines: SDA (Serial Data) and SCL (Serial Clock).
 * - Supports multiple devices with unique addresses (7-bit or 10-bit).
 * - Operates in different speed modes: 
 *   - Standard Mode: 100 kbit/s
 *   - Fast Mode: 400 kbit/s
 *   - High-Speed Mode: 3.4 Mbit/s
 * - Uses ACK/NACK for error detection and data validation.
 *
 * Basic I2C Frame Format:
 * ----------------------------------------------------------------------------
 * | START | ADDRESS | R/W | ACK | DATA BYTE | ACK | DATA BYTE | ACK/NACK | STOP |
 * ----------------------------------------------------------------------------
 * - START condition: Master initiates communication. SDA HIGH TO LOW SCL HIGH 
 * - ADDRESS: Master sends the 7-bit or 10-bit slave address.
 * - R/W bit: Specifies Read (1) or Write (0) operation.
 * - ACK (Acknowledge): Sent by the slave to confirm receipt.
 * - DATA bytes: Transmitted between master and slave.
 * - STOP condition: Master ends communication. SDA LOW TO HIGH SCL HIGH 
 *
 * Clock Stretching:
 * - Some slow slave devices hold the SCL line LOW to delay the master until ready.
 * - This prevents data loss due to timing mismatches.
 *
 * Pull-Up Resistors:
 * - I2C requires pull-up resistors on SDA and SCL lines to ensure proper voltage levels.
 * - Typical values range between 4.7kΩ to 10kΩ.
 *
 * Common Issues and Troubleshooting:
 * - Check pull-up resistors to stabilize voltage levels.
 * - Verify correct slave address for proper device detection.
 * - Use an oscilloscope or logic analyzer to monitor signal integrity.
 * - Implement error handling to prevent bus hang situations.
 * 
 * Example Usage:
 * In embedded systems, I2C is implemented using functions for initializing, reading, 
 * and writing data with the appropriate slave device.
 *
 * Note: Different microcontrollers (e.g., AVR, STM32, ESP32) use specific APIs for I2C.
 ...................................................................................................*/
 /*
 * Definition: Bus Arbitration
 *
 * Bus arbitration is the process of managing access to a shared communication bus
 * when multiple devices request control simultaneously. It ensures orderly access,
 * preventing conflicts and data corruption.
 *
 * I2C Bus Arbitration Example
 *
 * Scenario:
 * Two masters, Master A and Master B, attempt to communicate with a slave device simultaneously.
 *
 * Both Masters Start Transmission:
 * - Master A sends 0x2A (binary: 00101010).
 * - Master B sends 0x2F (binary: 00101111).
 * - Both monitor the SDA (Serial Data Line) while transmitting.
 *
 * Arbitration Process:
 * - Data is transmitted bit by bit.
 * - At the 5th bit:
 *   - Master A sends LOW (0).
 *   - Master B sends HIGH (1).
 *   - Since SDA is LOW, Master B realizes it has lost arbitration.
 *
 * Resolution:
 * - Master A wins arbitration and continues its transmission.
 * - Master B stops transmitting and waits for the bus to become free.
...........................................................................................................
/*
 * Clock Stretching in I2C: Definition and Explanation
 *
 * Definition:
 * Clock stretching is a mechanism where an I2C slave device holds the SCL (Serial Clock Line) LOW
 * to delay the master until it is ready to continue communication.
 *
 * How Clock Stretching Works:
 * 1. The master generates the clock signal to synchronize communication.
 * 2. If the slave needs more time to process data, it pulls the SCL line LOW.
 * 3. The master detects the LOW state and waits until the slave releases the clock.
 * 4. Once the slave releases SCL (goes HIGH), normal communication resumes.
 *
 * Why Clock Stretching is Needed:
 * - Some slow slave devices require extra processing time before responding.
 * - Prevents data loss by ensuring synchronization between master and slave.
 * - Helps devices with limited processing power handle I2C communication properly.
 *
 * Limitations of Clock Stretching:
 * - Reduces overall bus speed, affecting performance.
 * - Some masters do not support clock stretching, leading to communication failures.
 * - Excessive stretching can cause bus timeouts in certain systems.
 *
 * Implementation Considerations:
 * - Ensure master devices support clock stretching before enabling it in firmware.
 * - Use bus timeout mechanisms to prevent infinite wait conditions.
....................................................................................................................
/*
 * Maximum Number of Masters and Slaves in I2C
 *
 * Masters:
 * - I2C supports multiple masters in a multi-master system.
 * - Practical implementations usually use 1 to 4 masters due to arbitration complexities.
 * - Arbitration ensures only one master controls the bus at a time.
 *
 * Slaves:
 * - 7-bit addressing allows up to 128 unique slave addresses (0 to 127).
 * - 10-bit addressing expands this to 1024 slaves (0 to 1023).
 * - Practical limits depend on bus capacitance, pull-up resistor values, and signal integrity.
 *
 * Constraints:
 * - Multiple masters require proper arbitration handling to avoid conflicts.
 * - High slave count may lead to increased bus capacitance, slowing communication.
 * - Pull-up resistor values must be carefully selected for signal integrity.
 .......................................................................................................................

 * Senior-Level I2C Interview Questions and Answers
 *
 * 1. Explain the different speed modes in I2C and how they impact communication efficiency.
 *    - I2C supports various speed modes:
 *      - Standard Mode: 100 kbit/s
 *      - Fast Mode: 400 kbit/s
 *      - High-Speed Mode: 3.4 Mbit/s
 *      - Ultra-Fast Mode: 5 Mbit/s
 *    - Higher speeds reduce transmission delays but require stronger pull-up resistors for stability.
 *
 * 2. What precautions should be taken when designing a PCB for I2C communication to minimize noise?
 *    - Keep SDA and SCL traces short.
 *    - Use proper ground planes to minimize interference.
 *    - Avoid crossing high-speed signal lines.
 *
 * 3. Explain the impact of pull-up resistors on signal integrity and speed in I2C.
 *     - Small resistors (e.g., 1kΩ) improve speed but increase power consumption.
 *     - Large resistors (e.g., 10kΩ) save power but slow down signal transitions.
 *
 *
 * 4. What are the trade-offs between polling vs. interrupt-driven I2C communication?
 *     - Polling constantly checks the bus, consuming CPU resources.
 *     - Interrupt-driven I2C handles events efficiently and improves multitasking.
 *
 * 5. How do you handle slave devices with different voltage levels in an I2C bus?
 *     - Use level shifters to match voltage levels between master and slave devices.
 *
 *
 * 6. Describe a real-world scenario where an I2C bus hangs—how would you diagnose and fix it?
 *     - A stuck slave holding SDA LOW prevents further communication.
 *     - Solution: Toggle SCL manually to release the bus, then reinitialize I2C.
 * 
 * code 
 * #include <stdint.h>
include <stdbool.h>

#define I2C_BASE_ADDRESS   0x40005400   // Example I2C peripheral base address
#define I2C_CLOCK_SPEED    100000       // Standard I2C clock speed (100 kHz)
#define I2C_MASTER_WRITE   0x00
#define I2C_MASTER_READ    0x01

typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t OAR1;
    volatile uint32_t OAR2;
    volatile uint32_t DR;
    volatile uint32_t SR1;
    volatile uint32_t SR2;
    volatile uint32_t CCR;
    volatile uint32_t TRISE;
} I2C_Registers;

#define I2C ((I2C_Registers *) I2C_BASE_ADDRESS)

// **1. Initialize I2C Module**
void I2C_Init() {
    I2C->CR1 |= (1 << 0);  // Enable I2C peripheral
    I2C->CCR = (SystemCoreClock / (2 * I2C_CLOCK_SPEED));
    I2C->TRISE = (SystemCoreClock / I2C_CLOCK_SPEED) + 1;
}

// **2. Start Condition**
void I2C_Start() {
    I2C->CR1 |= (1 << 8); // Generate Start condition
    while (!(I2C->SR1 & (1 << 0))); // Wait for Start condition to be transmitted
}

// **3. Stop Condition**
void I2C_Stop() {
    I2C->CR1 |= (1 << 9); // Generate Stop condition
}

// **4. Write Data to Slave**
void I2C_Write(uint8_t slave_address, uint8_t data) {
    I2C_Start(); // Start condition
    I2C->DR = slave_address & ~I2C_MASTER_READ; // Send slave address with Write bit
    while (!(I2C->SR1 & (1 << 1))); // Wait for address acknowledgment
    I2C->DR = data; // Send data
    while (!(I2C->SR1 & (1 << 2))); // Wait for data transmission to complete
    I2C_Stop(); // Stop condition
}

// **5. Read Data from Slave (Using Repeated Start)**
uint8_t I2C_Read(uint8_t slave_address, uint8_t register_address) {
    uint8_t data;

    I2C_Start(); // Start condition
    I2C->DR = slave_address & ~I2C_MASTER_READ; // Send slave address with Write bit
    while (!(I2C->SR1 & (1 << 1))); // Wait for address acknowledgment
    I2C->DR = register_address; // Send register address
    while (!(I2C->SR1 & (1 << 2))); // Wait for data transmission to complete

    I2C_Start(); // Repeated Start
    I2C->DR = slave_address | I2C_MASTER_READ; // Send slave address with Read bit
    while (!(I2C->SR1 & (1 << 1))); // Wait for acknowledgment
    data = I2C->DR; // Read data from slave
    while (!(I2C->SR1 & (1 << 2))); // Wait for read completion
    I2C_Stop(); // Stop condition

    return data;
}

int main() {
    I2C_Init(); // Initialize I2C
    I2C_Write(0x50, 0x37); // Write data to a slave device
    uint8_t received_data = I2C_Read(0x50, 0x01); // Read data using repeated start

    while (1);
    return 0;
}

 * 
 */

