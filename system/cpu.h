#ifndef GOODBOY_CPU_H
#define GOODBOY_CPU_H

#include "types.h"
#include "registers.h"
#include "memory.h"
#include "gpu.h"
#include "timers.h"

/**
 * Description
 * The GameBoy uses a chip that's a cross between the Intel 8080 and the Zilog Z80. The chip is the Sharp LR35902.
 *
 * Information about the CPU
 *     - Number of instructions: 500
 *     - Registers
 *         - 8-bit: A, B, C, D, E, F, H, L
 *         - 16-bit: AF, BC, DE, HL, SP, PC
 *     - Clock speed: 4194304 Hz (4.19 MHz)
 *
 * A few notes on the CPU:
 *     - Official Nintendo documents refer to "machine cycles" when describing instructions.
 *     - One machine cycle equals four CPU clock cycles.
 *     - The numerical value of a machine cycle is 1048576 Hz (1.05 MHz)
 *
 * A few notes on the registers:
 *     - The F register is indirectly accessible by the programmer, and is used to store the results of various math operations.
 *     - The PC register points to the next instruction to be executed in memory.
 *     - The SP register points to the current stack position.
 *     - The F register consists of the following:
 *         - Zero flag (Z, 7th bit): This bit is set when the result of a math operation is zero or two values match when using the CP instruction.
 *         - Subtract flag (N, 6th bit): This bit is set if a subtraction was performed in the last math instruction regardless of result..
 *         - Half carry flag (H, 5th bit): This bit is set if a carry occurred from the lower nibble in the last math operation.
 *         - Carry flag (C, 4th bit): This bit is set when an operation results in carrying from or borrowing to the 7th bit.
 *     
 *     - On power up, the PC is initialized to 0x00 and the boot rom is started.
 *     - Once the boot rom finishes the PC is 0x100 and the instruction at that location in the ROM is executed.
 *     - From here on the PC is controlled indirectly by the instructions themselves that were generated by the programmer of the ROM cart.
 *     
 *     - The SP is used to keep track of the top of the stack.
 *         - The Stack is used for saving variables, saving return addressed, passing arguments to subroutines and various other uses.
 *         - The instructions CALL, PUSH and RST all put information onto the stack.
 *         - The instructions POP, RET and RETI all take information off of the stack.
 *         - Interrupts put a return address on the stack and remove it at the completion as well.
 *         - As information is put onto the stack, the stack grows DOWNWARD in RAM. As a result SP should always be initialized at the highest location of RAM space that has been allocated for use by the stack.
 *             - For example, if a programmer wants to locate the SP at the top of low RAM space (0xC000 - 0xDFFF) he would set SP to 0xE000 using LD SP,0xE000.
 *             - The SP automatically decrements BEFORE it puts something onto the stack, so it is perfectly acceptable to assign it a value which points to a memory address which is one location past the end of available RAM.
 *             - The SP is initialized to 0xFFFE on power up, but a programmer should not rely on this setting and should explicitly set its value.
 */
class CPU {
private:
    Memory* memory;
    GPU* gpu;
    Timers* timers;

    void writeByte(int address, int value);
    byte readByte(int address);
    void synchronize();
    void sleep(unsigned long long duration);
    void incrementCycles(int n);
    void checkInterrupts();
    void decode(byte opCode);
    void decodeCB(byte opCode);
    void doMiscOperation(int y, int z, int q, int p);
    void doLoadOperation(int y, int z);
    void doMathOperation(int y, int z);
    void doJumpOperation(int y, int z, int q, int p);
    void doLogicOperation(int y);
    void jumpRelative(signed char op);
    void call();
    byte getByte();
    word getWord();
    word combineBytes(byte high, byte low);
    byte getIF();
    byte getIE();

    byte increment(byte value);
    byte decrement(byte value);
    byte add8Bit(byte num1, byte num2);
    word add16Bit(word num1, word num2);
    byte adc(byte num1, byte num2);
    byte sub(byte num1, byte num2);
    byte sbc(byte num1, byte num2);
    byte rlc(byte value);
    void rlca();
    byte rrc(byte value);
    void rrca();
    byte rl(byte value);
    void rla();
    byte rr(byte value);
    void rra();
    byte sla(byte value);
    byte sra(byte value);
    byte swap(byte value);
    byte srl(byte value);
    void daa();
    void cpl();
    void scf();
    void ccf();
    void bit(int position, byte value);
    byte res(int position, byte value);
    byte set(int position, byte value);
    byte bitwiseAnd(byte num1, byte num2);
    byte bitwiseXor(byte num1, byte num2);
    byte bitwiseOr(byte num1, byte num2);
    void cp(byte num1, byte num2);
    void rst(word address);
    void stop();
    void halt();

public:
    Registers registers;

    bool isRunning = false;

    bool ime = false;
    bool pendingEnableIME = false;
    
    bool isStopped = false;

    bool isHalted = false;
    bool haltBug = false;
    bool haltSkip = false;
    bool justHalted = false;

    unsigned long long cycles = 0;
    unsigned long long cyclesSinceLastSync = 0;
    unsigned long long lastSyncTime = 0;

    CPU(Memory* memory, GPU* gpu, Timers* timers);

    void reset();
    void tick();
    void run();
    void setFlags(int flags);
    void resetFlags(int flags);
};

#endif
