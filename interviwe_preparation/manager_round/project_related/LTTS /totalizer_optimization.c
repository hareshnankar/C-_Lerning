/**
 * @file totalizer_optimization.c
 * @brief Documentation of Totalizer Logic Improvements for Interview Preparation
 * 
 * 1. How to Explain the Project
 * "I optimized the data logging mechanism of a 32-parameter totalizer system. 
 * Originally, the system backed up cumulative data from RAM to Flash memory every 3 hours 
 * using a software-based counter. I re-engineered this to a 30-minute interval to 
 * minimize data loss during power failures. I replaced the manual software counters 
 * with standard Time APIs for better precision and synchronized the time-stamping logic 
 * with the totalizer reset function. This ensured that the Modbus registers and 
 * physical storage remained consistent and accurate."
 *
 * 2. Key Technical Questions & Answers
 * 
 * Q1: Why did you reduce the interval from 3 hours to 30 minutes?
 * Answer: The primary reason was Data Loss Mitigation. If a power failure occurred 
 * at 2 hours and 50 minutes, the system would lose nearly 3 hours of totalized data 
 * because it hadn't been committed to Flash yet. By moving to a 30-minute interval, 
 * we reduced the maximum potential data loss by 83%, ensuring higher data integrity 
 * for the user.
 * 
 * Q2: Why switch from a software counter to Time APIs?
 * Answer: Software counters (like incrementing a variable in a loop) are prone to 
 * drift if the CPU is under heavy load or if interrupts delay the main loop. 
 * Time APIs (utilizing an RTC or System Tick) provide absolute time tracking. 
 * This makes the 30-minute intervals precise and allows us to align data logs 
 * with actual wall-clock time, which is critical for audit trails.
 * 
 * Q3: Frequent writing to Flash memory can wear it out. How did you handle this?
 * Answer: This is a trade-off. While 30 minutes is more frequent than 3 hours, 
 * most modern Flash chips (like Nor Flash or EEPROM) support 100,000 to 1,000,000 write cycles.
 * Calculation: 48 writes per day (every 30 mins) = ~17,520 writes per year. 
 * The chip will still last 5-10+ years.
 * Follow-up: Mention if you used Wear Leveling or only wrote to Flash if the 
 * totalizer value actually changed.
 * 
 * Q4: How did you handle the "Reset" logic between the App, Hardware, and Flash?
 * Answer: I implemented a synchronization trigger. When a 'Reset' command is received 
 * (via Modbus or Hardware button), the code:
 * - Clears the 32 accumulation variables in RAM.
 * - Resets the Time API reference point.
 * - Immediately performs a "Force Write" to Flash so the stored values are also zeroed out. 
 * This prevents the system from reloading old data if it reboots right after a reset.
 * 
 * Q5: With 32 parameters, how did you ensure Modbus performance wasn't affected?
 * Answer: I used a "shadow buffer" or DMA (Direct Memory Access) approach where the 
 * totalizer calculations happen in the background, and the Modbus registers are 
 * updated only when the values change. This ensures that the Modbus communication 
 * stays fast and doesn't wait for Flash writing processes, which are typically slow.
 * 
 * 3. Practical Tips for the Interview
 * - The "Why": Always start with why the change was needed (e.g., "Customer 
 *   complained about losing data during power outages").
 * - Consistency: Mention that you ensured the Hardware buttons and the Mobile App 
 *   remain in sync using a State Machine—this shows you understand complex 
 *   system architecture.
 * - Edge Cases: Be ready to explain what happens if the power goes out exactly 
 *   while writing to Flash (mentioning "CRC checks" or "Double Buffering" will 
 *   impress them).
 */
