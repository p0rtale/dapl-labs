#pragma once

#include <stack_machine/machine/Memory.h>
#include <stack_machine/machine/Registers.h>
#include <stack_machine/machine/Instruction.h>

#include <iostream>

namespace stack_machine {

class StackMachine {
public:
    StackMachine(size_t memorySize, std::istream& input, std::ostream& output);

    void run(std::ifstream& file);

private:
    void setupProgram(const MemoryContainer& programMemory);
    void setupRegisters();

    void executeProgram();
    void executeInstruction(Instruction instruction);

private:
    Memory m_memory;
    Registers m_registers;

    std::istream& m_input;
    std::ostream& m_output;
};

}  // namespace stack_machine
