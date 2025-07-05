/******************************************************************************
 * 🌐 Phase 2: TCP/IP Setup for Modbus Communication Using C and libmodbus
 ******************************************************************************/

/* 🧰 Step 1: Install libmodbus (Windows Setup)
 *
 * Option A: Using MSYS2 (Recommended)
 * - Install MSYS2: https://www.msys2.org
 * - Inside MSYS2 terminal:
 *     pacman -S git make gcc
 *     git clone https://github.com/stephane/libmodbus.git
 *     cd libmodbus
 *     ./configure
 *     make
 *     make install
 *
 * Option B: Use Visual Studio with prebuilt libmodbus files
 * - You'll need to configure include paths and link against libmodbus.lib
 */

/* 🔧 Step 2: Setup Modbus TCP Client using libmodbus

#include <modbus.h>
#include <stdio.h>

int main() {
    modbus_t *ctx;
    uint16_t regs[5];

    ctx = modbus_new_tcp("127.0.0.1", 502);  // IP & Port of Modbus server
    if (modbus_connect(ctx) == -1) {
        perror("Connection failed");
        modbus_free(ctx);
        return 1;
    }

    int rc = modbus_read_registers(ctx, 0, 5, regs);
    if (rc == -1) {
        perror("Read error");
    } else {
        for (int i = 0; i < rc; i++)
            printf("Register %d: %d\n", i, regs[i]);
    }

    modbus_close(ctx);
    modbus_free(ctx);
    return 0;
}

/* 🔁 You can modify this to create a Server or to write registers/coils as well.
 */

/* 🧪 Step 3: Use Modbus Poll / Modscan
 *
 * Modbus Poll (https://www.modbustools.com/modbus_poll.html)
 * - Windows-based Modbus master simulator
 * - Allows testing register read/write via TCP
 *
 * ModScan32 (https://www.win-tech.com/html/modscan32.htm)
 * - Similar tool for polling and analyzing Modbus TCP data
 *
 * Set server to run locally or use a simulator like ModbusPal or Simply Modbus TCP Server.
 * Configure correct port (usually 502) and IP (e.g., 127.0.0.1 for local)
 */

/* ✅ Tips
 * - Always keep simulator/server running while testing
 * - Use Wireshark to inspect TCP packets (Modbus protocol filter)
 * - Match Unit ID and register address with your server setup
 */

/* 📦 Outcome
 * You'll have a fully working Modbus TCP client in C
 * Tested against Modbus simulators on your Windows PC
 * Ready to connect to real devices when needed
 */
