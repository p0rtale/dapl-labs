#pragma once

#include <stack_machine/machine/Memory.h>
#include <stack_machine/machine/Stack.h>
#include <stack_machine/machine/Registers.h>
#include <stack_machine/machine/Instruction.h>

#include <iostream>

namespace stack_machine {

class InstructionExecutor {
public:
    InstructionExecutor(Instruction instruction, Memory& memory, Registers& registers,
                        std::istream& input, std::ostream& output);

    InstructionExecutor(const InstructionExecutor& other) = default;
    InstructionExecutor(InstructionExecutor&& other) = default;

    InstructionExecutor& operator=(const InstructionExecutor& other) = default;
    InstructionExecutor& operator=(InstructionExecutor&& other) = default;

    ~InstructionExecutor() = default;

    void execute();

private:
    void executeAdd();
    void executeSub();
    void executeDiv();
    void executeMod();
    void executeMul();
    void executeNeg();

    void executeAnd();
    void executeOr();
    void executeNot();

    void executeDup();
    void executeDrop();
    void executeSwap();
    void executeRot();
    void executeOver();
    void executeDropn();
    void executePushn();

    void executeRead();
    void executeWrite();

    void executeCmp();
    void executeJmp();
    void executeJlt();
    void executeJgt();
    void executeJeq();
    void executeJle();
    void executeJge();
    void executeJne();
    void executeCall();
    void executeRetn();

    void executeGetSp();
    void executeSetSp();
    void executeGetBp();
    void executeSetBp();
    void executeGetCp();

    void executeIn();
    void executeOut();

    void executePush(Word code);

private:
    Instruction m_instruction;

    Memory& m_memory;
    Stack& m_stack;
    Registers& m_registers;

    std::istream& m_input;
    std::ostream& m_output;
};

}  // namespace stack_machine
