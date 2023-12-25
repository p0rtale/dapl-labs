#pragma once

#include <StackMachine/Machine/Memory.hpp>
#include <StackMachine/Machine/Registers.hpp>
#include <StackMachine/Machine/Instruction.hpp>

#include <iostream>

namespace stack_machine {

class StackMachine {
public:
    StackMachine(size_t memorySize, std::istream& input, std::ostream& output);

    Word run(std::ifstream& file);

private:
    void setupProgram(const MemoryContainer& programMemory);
    void setupRegisters();

    Word executeProgram();

private:
    Memory m_memory;
    Registers m_registers;

    std::istream& m_input;
    std::ostream& m_output;
};

}  // namespace stack_machine
