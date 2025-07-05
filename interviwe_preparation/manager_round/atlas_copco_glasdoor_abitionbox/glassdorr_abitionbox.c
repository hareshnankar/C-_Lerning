/******************************************************************************
 * 📘 Atlas Copco – Senior Firmware Engineer Interview Prep (.c format)
 * Round: 2nd (Technical Manager + HR) | Source: AmbitionBox + Glassdoor
 * Structure: Common Questions + Realistic Answers for Practice
 *
 * ✅ Behavioral & Situational Questions

 * 1. Tell me about a time you solved a complex bug under pressure.
 *    // I worked on a device with slow boot (5–6 sec). I had 6 days to fix it.
 *    // Found the code was reading 2000 bytes from EEPROM using byte-by-byte I²C.
 *    // Rewrote logic to use sequential read → reduced boot time by 2–3 sec.
 *    // Solved the issue well before deadline, showing practical debugging and timing analysis.

 * 2. How do you prioritize tasks during overlapping deadlines?
 *    // I list all tasks, break them into small steps, and rank by urgency and impact.
 *    // I focus on high-priority work first and communicate early about blockers.
 *    // If needed, I delegate or discuss with the team to avoid delays.

 * 3. Describe a situation where you disagreed with a teammate.
 *    // In one project, we had different views on error handling in firmware.
 *    // I scheduled a short meeting, we explained our approaches, and chose a solution that balanced both.
 *    // It helped maintain team spirit and code clarity.

 * 4. How do you handle feedback from senior engineers or managers?
 *    // I welcome feedback and treat it as a learning step.
 *    // I listen carefully, ask for clarification if needed, and apply the suggestions.
 *    // It helps improve both code quality and teamwork.

 *
 * ✅ Technical Questions – Firmware Focus

 * 5. What’s your experience with real-time systems?
 *    // I’ve worked with RTOS in embedded systems where timing and task priority matter.
 *    // I use timers, interrupts, and queues to manage data flow and ensure timing accuracy.

 * 6. How do you optimize boot time in embedded devices?
 *    // I review the startup sequence for delays (e.g., slow EEPROM reads or blocking loops).
 *    // I prefer bulk reads, disable unused peripherals, and log time markers to isolate slow parts.

 * 7. What’s the difference between stack and heap in C?
 *    // Stack: stores local variables; fast but limited.
 *    // Heap: used for dynamic allocation; flexible but must be managed manually.

 * 8. How do you handle memory leaks in embedded systems?
 *    // I avoid dynamic memory when possible.
 *    // If heap is used, I monitor allocation/deallocation, use tools to detect leaks,
 *    // and ensure proper cleanup before shutdown or reset.

 *
 * ✅ System Design & Debugging Questions

 * 9. How would you design a fault-tolerant firmware system?
 *    // Use watchdog timers, error logs, retry mechanisms, and safe default states.
 *    // Firmware should recover gracefully and avoid system crashes.

 * 10. What tools do you use for debugging I²C or SPI issues?
 *    // Logic analyzer, oscilloscope, and debug UART are my go-to tools.
 *    // I check signal timing, ACK/NACK flags, and use debug prints during communication steps.

 * 11. How do you handle firmware updates in deployed devices?
 *    // I use a bootloader that checks update flags and verifies checksum.
 *    // Firmware writes to flash only after successful validation to avoid bricking.
 *
 * ✅ Company Fit & HR Questions

 * 12. Why do you want to work at Atlas Copco?
 *    // Atlas Copco is known for advanced engineering and global presence.
 *    // I’m impressed by their values in sustainability, innovation, and employee growth.
 *    // I want to contribute to high-impact products and grow as an engineer.

 * 13. What do you know about our products?
 *    // Compressors, industrial tools, vacuum pumps, and energy-saving solutions.
 *    // Widely used in manufacturing, automotive, and process industries.
 *    // Known for efficiency, durability, and smart automation.

 * 14. Who are Atlas Copco’s competitors?
 *    // Ingersoll Rand, Elgi Equipments, Kirloskar Pneumatic, Sullair.
 *    // Atlas Copco stands out for innovation, global support, and diverse portfolio.

 * 15. What are your salary expectations?
 *    // I expect a fair range based on industry and role level — between ₹X and ₹Y.
 *    // I’m flexible depending on growth opportunity and team culture.

 * 16. Where do you see yourself in 5 years?
 *    // I’d like to take on more technical leadership, mentor juniors,
 *    // and contribute to complex projects that make a difference.

 * 17. What kind of environment helps you perform best?
 *    // Supportive, respectful, and where people share ideas.
 *    // I enjoy working with teams who care about quality and learning.

 *
 * 💡 Tip:
 *    // Practice answers by speaking them out loud.
 *    // Add personal examples where possible.
 *    // End interviews by asking smart questions about the role or team.
 ******************************************************************************/
