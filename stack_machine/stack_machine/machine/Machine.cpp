#include <stack_machine/machine/Machine.h>

#include <stack_machine/machine/InstructionExecutor.h>

namespace stack_machine {
    
StackMachine::StackMachine(size_t memorySize, std::istream& input, std::ostream& output)
        : m_memory(memorySize, memorySize, m_registers), m_input(input), m_output(output) {}

void StackMachine::run(std::ifstream& file) {
    setupProgram(MemoryContainer{file});
    setupRegisters();
    executeProgram();
}

void StackMachine::setupProgram(const MemoryContainer& programMemory) {
    m_memory.loadProgram(programMemory);
}

void StackMachine::setupRegisters() {
    m_registers = {
        .m_cp = 0,
        .m_sp = m_memory.size(),
        .m_bp = 0,
    };
}

void StackMachine::executeProgram() {
    auto& program = m_memory.program();
    Instruction instruction = Instruction::kBlank;
    while (instruction != Instruction::kHalt) {
        instruction = program.nextInstruction();
        executeInstruction(instruction);
    }
}

void StackMachine::executeInstruction(Instruction instruction) {
    auto executor = InstructionExecutor{instruction, m_memory, m_registers, m_input, m_output};
    executor.execute();
}

}  // namespace stack_machine
