#pragma once

#include <StackMachine/Machine/Memory.hpp>
#include <StackMachine/Machine/Stack.hpp>
#include <StackMachine/Machine/Registers.hpp>
#include <StackMachine/Machine/Instruction.hpp>

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

    Word getHaltResult();

private:
    void executeAdd(); void executeFAdd(); void executeUAdd();
    void executeSub(); void executeFSub(); void executeUSub();
    void executeDiv(); void executeFDiv(); void executeUDiv();
    void executeMod(); void executeUMod();
    void executeMul(); void executeFMul(); void executeUMul();
    void executeNeg(); void executeFNeg();

    void executeAnd();
    void executeOr();
    void executeNot();

    void executeS2F();
    void executeF2S();
    void executeU2F();
    void executeF2U();

    void executeDup();
    void executeDrop();
    void executeSwap();
    void executeRot();
    void executeOver();
    void executeDropn();
    void executePushn();

    void executeRead();
    void executeWrite();

    void executeCmp(); void executeFCmp(); void executeUCmp();
    void executeJmp();
    void executeJlt();
    void executeJgt();
    void executeJeq();
    void executeJle();
    void executeJge();
    void executeJne();
    void executeCall();
    void executeRetn();
    void executeHalt();

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

    bool isHalted = false;

    Memory& m_memory;
    Stack& m_stack;
    Registers& m_registers;

    std::istream& m_input;
    std::ostream& m_output;
};

}  // namespace stack_machine
