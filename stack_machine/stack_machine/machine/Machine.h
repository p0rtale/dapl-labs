#pragma once

#include <stack_machine/machine/Memory.h>
#include <stack_machine/machine/Registers.h>
#include <stack_machine/machine/Instruction.h>
#include <stack_machine/machine/InstructionExecutor.h>

namespace stack_machine {

class StackMachine {
public:
    StackMachine(size_t memorySize, std::istream& input, std::ostream& output)
        : m_memory(memorySize, memorySize, m_registers), m_input(input), m_output(output) {}

    void run(std::ifstream& file) {
        setupProgram(MemoryContainer{file});
        setupRegisters();
        executeProgram();
    }

private:
    void setupProgram(const MemoryContainer& programMemory) {
        m_memory.loadProgram(programMemory);
    }

    void setupRegisters() {
        m_registers = {
            .m_cp = 0,
            .m_sp = m_memory.size(),
            .m_bp = 0,
        };
    }

    void executeProgram() {
        auto& program = m_memory.program();
        Instruction instruction = Instruction::kBlank;
        while (instruction != Instruction::kHalt) {
            instruction = program.nextInstruction();
            executeInstruction(instruction);
        }
    }

    void executeInstruction(Instruction instruction) {
        auto executor = InstructionExecutor{instruction, m_memory, m_registers, m_input, m_output};
        executor.execute();
    }

private:
    Memory m_memory;
    Registers m_registers;

    std::istream& m_input;
    std::ostream& m_output;
};

}  // namespace stack_machine
