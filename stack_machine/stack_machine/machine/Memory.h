#pragma once

#include <stack_machine/machine/MemoryContainer.h>
#include <stack_machine/machine/Stack.h>
#include <stack_machine/machine/Program.h>
#include <stack_machine/machine/Registers.h>

namespace stack_machine {

class Memory {
public:
    Memory(size_t memorySize, size_t stackSize, Registers& registers)
            : m_memoryCells(memorySize), 
              m_stack(m_memoryCells, stackSize, registers.m_sp),
              m_program(m_memoryCells, registers.m_cp) {}

    Word readCell(Word address) {
        return m_memoryCells.at(address);
    }

    void writeCell(Word address, Word value) {
        m_memoryCells.at(address) = value;
    }

    void loadProgram(const MemoryContainer& programCells) {
        m_program.setup(programCells);
    }

    size_t size() {
        return m_memoryCells.size();
    }

    Program& program() {
        return m_program;
    }

    Stack& stack() {
        return m_stack;
    }

private:
    MemoryContainer m_memoryCells;
    Stack m_stack;
    Program m_program;
};

}  // namespace stack_machine
