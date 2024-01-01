#pragma once

#include <StackMachine/Machine/MemoryContainer.hpp>
#include <StackMachine/Machine/Instruction.hpp>

#include <vector>

namespace stack_machine {

class Program {
public:
    Program(MemoryContainer& memoryCells, size_t& cp)
        : m_memoryCells(memoryCells), m_cp(cp) {}

    Program(const Program& other) = delete;
    Program(Program&& other) = delete;

    Program& operator=(const Program& other) = delete;
    Program& operator=(Program&& other) = delete;

    ~Program() = default;

    size_t size() const {
        return m_size;
    }

    Instruction nextInstruction() {
        auto word = m_memoryCells[m_cp++];
        return static_cast<Instruction>(word);
    }

    void setup(const MemoryContainer& programCells) {
        auto& memory = m_memoryCells.data();
        const auto& program = programCells.data();
        std::copy(program.begin(), program.end(), memory.begin());
        m_size = program.size();
    }

private:
    MemoryContainer& m_memoryCells;
    size_t& m_cp;

    size_t m_size = 0;
};

}  // namespace stack_machine
