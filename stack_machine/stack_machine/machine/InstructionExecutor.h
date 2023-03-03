#pragma once

#include <stack_machine/machine/Memory.h>
#include <stack_machine/machine/Stack.h>
#include <stack_machine/machine/Registers.h>
#include <stack_machine/machine/Instruction.h>

#include <array>

namespace stack_machine {

class InstructionExecutor {
public:
    InstructionExecutor(Instruction instruction, Memory& memory, Registers& registers,
                        std::istream& input, std::ostream& output)
            : m_instruction(instruction), m_memory(memory), m_stack(m_memory.stack()), m_registers(registers),
              m_input(input), m_output(output) {}

    InstructionExecutor(const InstructionExecutor& other) = default;
    InstructionExecutor(InstructionExecutor&& other) = default;

    InstructionExecutor& operator=(const InstructionExecutor& other) = default;
    InstructionExecutor& operator=(InstructionExecutor&& other) = default;

    ~InstructionExecutor() = default;

    void execute() {
        switch (m_instruction) {
            case Instruction::kBlank:
            case Instruction::kAdd: return executeAdd();
            case Instruction::kSub: return executeSub();
            case Instruction::kDiv: return executeDiv();
            case Instruction::kMod: return executeMod();
            case Instruction::kMul: return executeMul();
            case Instruction::kNeg: return executeNeg();

            case Instruction::kBitAnd: return executeAnd();
            case Instruction::kBitOr:  return executeOr();
            case Instruction::kBitNot: return executeNot();

            case Instruction::kDup:   return executeDup();
            case Instruction::kDrop:  return executeDrop();
            case Instruction::kSwap:  return executeSwap();
            case Instruction::kRot:   return executeRot();
            case Instruction::kOver:  return executeOver();
            case Instruction::kDropn: return executeDropn();
            case Instruction::kPushn: return executePushn();

            case Instruction::kRead:  return executeRead();
            case Instruction::kWrite: return executeWrite();

            case Instruction::kCmp:  return executeCmp();
            case Instruction::kJmp:  return executeJmp();
            case Instruction::kJlt:  return executeJlt();
            case Instruction::kJgt:  return executeJgt();
            case Instruction::kJeq:  return executeJeq();
            case Instruction::kJle:  return executeJle();
            case Instruction::kJge:  return executeJge();
            case Instruction::kJne:  return executeJne();
            case Instruction::kCall: return executeCall();
            case Instruction::kRetn: return executeRetn();
            case Instruction::kHalt: return;

            case Instruction::kGetSp: return executeGetSp();
            case Instruction::kSetSp: return executeSetSp();
            case Instruction::kGetBp: return executeGetBp();
            case Instruction::kSetBp: return executeSetBp();
            case Instruction::kGetCp: return executeGetCp();

            case Instruction::kIn:  return executeIn();
            case Instruction::kOut: return executeOut();

            default: return executePush(static_cast<Word>(m_instruction));
        }
    }

private:
    void executeAdd() {
        // std::cout << "ADD\n";
        Word second = m_stack.pop();
        Word first = m_stack.pop();
        m_stack.push(first + second);
    }

    void executeSub() {
        // std::cout << "SUB\n";
        Word second = m_stack.pop();
        Word first = m_stack.pop();
        m_stack.push(first - second);
    }

    void executeDiv() {
        // std::cout << "DIV\n";
        Word second = m_stack.pop();
        Word first = m_stack.pop();
        m_stack.push(first / second);
    }

    void executeMod() {
        // std::cout << "MOD\n";
        Word second = m_stack.pop();
        Word first = m_stack.pop();
        m_stack.push(first % second);
    }

    void executeMul() {
        // std::cout << "MUL\n";
        Word second = m_stack.pop();
        Word first = m_stack.pop();
        m_stack.push(first * second);
    }

    void executeNeg() {
        // std::cout << "NEG\n";
        Word word = m_stack.pop();
        m_stack.push(-word);
    }

    void executeAnd() {
        // std::cout << "AND\n";
        Word second = m_stack.pop();
        Word first = m_stack.pop();
        m_stack.push(first & second);
    }

    void executeOr() {
        // std::cout << "OR\n";
        Word second = m_stack.pop();
        Word first = m_stack.pop();
        m_stack.push(first | second);
    }

    void executeNot() {
        // std::cout << "NOT\n";
        Word word = m_stack.pop();
        m_stack.push(~word);
    }

    void executeDup() {
        // std::cout << "DUP\n";
        Word word = m_stack.pop();
        m_stack.push(word);
        m_stack.push(word);
    }

    void executeDrop() {
        // std::cout << "DROP\n";
        m_stack.pop();
    }

    void executeSwap() {
        // std::cout << "SWAP\n";
        Word second = m_stack.pop();
        Word first = m_stack.pop();
        m_stack.push(second);
        m_stack.push(first);
    }

    void executeRot() {
        // std::cout << "ROT\n";
        Word third = m_stack.pop();
        Word second = m_stack.pop();
        Word first = m_stack.pop();
        m_stack.push(second);
        m_stack.push(third);
        m_stack.push(first);
    }

    void executeOver() {
        // std::cout << "OVER\n";
        Word second = m_stack.pop();
        Word first = m_stack.pop();
        m_stack.push(first);
        m_stack.push(second);
        m_stack.push(first);
    }

    void executeDropn() {
        // std::cout << "DROPN\n";
        Word number = m_stack.pop();
        for (; number > 0; --number) {
            m_stack.pop();
        }
    }

    void executePushn() {
        // std::cout << "PUSHN\n";
        Word number = m_stack.pop();
        for (; number > 0; --number) {
            m_stack.push(0);
        }
    }

    void executeRead() {
        // std::cout << "READ\n";
        Word address = m_stack.pop();
        Word cell = m_memory.readCell(address);
        m_stack.push(cell);
    }

    void executeWrite() {
        // std::cout << "WRITE\n";
        Word value = m_stack.pop();
        Word address = m_stack.pop();
        m_memory.writeCell(address, value);
    }

    void executeCmp() {
        // std::cout << "CMP\n";
        Word second = m_stack.pop();
        Word first = m_stack.pop();
        
        Word result = 1;
        if (first < second) {
            result = -1;
        } else if (first == second) {
            result = 0;
        }

        m_stack.push(result);       
    }

    void executeJmp() {
        // std::cout << "JMP\n";
        Word address = m_stack.pop();
        m_registers.m_cp = address;
    }

    void executeJlt() {
        // std::cout << "JLT\n";
        Word address = m_stack.pop();
        Word value = m_stack.pop();
        if (value < 0) {
            m_registers.m_cp = address;  
        }
    }

    void executeJgt() {
        // std::cout << "JGT\n";
        Word address = m_stack.pop();
        Word value = m_stack.pop();
        if (value > 0) {
            m_registers.m_cp = address;  
        }
    }

    void executeJeq() {
        // std::cout << "JEQ\n";
        Word address = m_stack.pop();
        Word value = m_stack.pop();
        if (value == 0) {
            m_registers.m_cp = address;  
        }
    }

    void executeJle() {
        // std::cout << "JLE\n";
        Word address = m_stack.pop();
        Word value = m_stack.pop();
        if (value <= 0) {
            m_registers.m_cp = address;  
        }
    }

    void executeJge() {
        // std::cout << "JGE\n";
        Word address = m_stack.pop();
        Word value = m_stack.pop();
        if (value >= 0) {
            m_registers.m_cp = address;  
        }
    }

    void executeJne() {
        // std::cout << "JNE\n";
        Word address = m_stack.pop();
        Word value = m_stack.pop();
        if (value != 0) {
            m_registers.m_cp = address;  
        }
    }

    void executeCall() {
        // std::cout << "CALL";
        Word address = m_stack.pop();
        m_stack.push(m_registers.m_cp);
        // std::cout << " address=" << address << ", current_cp=" << m_registers.m_cp << "\n";
        m_registers.m_cp = address;
    }

    void executeRetn() {
        // std::cout << "RETN\n";
        Word address = m_stack.pop();
        executeDropn();
        m_registers.m_cp = address;
    }

    void executeGetSp() {
        // std::cout << "GETSP\n";
        m_stack.push(m_registers.m_sp);
    }

    void executeSetSp() {
        // std::cout << "SETSP\n";
        m_registers.m_sp = m_stack.pop();
    }

    void executeGetBp() {
        // std::cout << "GETBP\n";
        m_stack.push(m_registers.m_bp);
    }

    void executeSetBp() {
        // std::cout << "SETBP\n";
        m_registers.m_bp = m_stack.pop();
    }

    void executeGetCp() {
        // std::cout << "GETCP\n";
        m_stack.push(m_registers.m_cp);
    }

    void executeIn() {
        // std::cout << "IN\n";
        unsigned int codepoint = 0;

        std::array<unsigned char, 5> bytes = { 0x00, 0x00, 0x00, 0x00 };
        m_input >> bytes[0];

        if ((0x80 & bytes[0]) == 0x00) {
            codepoint = bytes[0];
        } else if ((0xE0 & bytes[0]) == 0xC0) {
            m_input >> bytes[1];
            codepoint += ((bytes[0] & 0x1F) << 6) + (bytes[1] & 0x3F);
        } else if ((0xF0 & bytes[0]) == 0xE0) {
            m_input >> bytes[1] >> bytes[2];
            codepoint += ((bytes[0] & 0x0F) << 12) + ((bytes[1] & 0x3F) << 6) + (bytes[2] & 0x3F);
        } else if ((0xF8 & bytes[0]) == 0xF0 && bytes[0] <= 0xF4) {
            m_input >> bytes[1] >> bytes[2] >> bytes[3];
            codepoint += ((bytes[0] & 0x07) << 18) + ((bytes[1] & 0x3F) << 12) + ((bytes[2] & 0x3F) << 6) + (bytes[3] & 0x3F);
        }

        m_stack.push(codepoint);
    }

    void executeOut() {
        // std::cout << "OUT\n";
        unsigned int codepoint = m_stack.pop();

        std::array<char, 5> bytes = { 0x00, 0x00, 0x00, 0x00, 0x00 };
        if (codepoint <= 0x7F) {
            bytes[0] = codepoint;
        } else if (codepoint <= 0x7FF) {
            bytes[0] = (codepoint >> 6) + 0b11000000;
            bytes[1] = (codepoint & 0b111111) + 0b10000000;
        } else if (codepoint <= 0xFFFF) {
            bytes[0] = (codepoint >> 12) + 0b11100000;
            bytes[1] = ((codepoint >> 6) & 0b111111) + 0b10000000;
            bytes[2] = (codepoint & 0b111111) + 0b10000000;
        } else if (codepoint <= 0x10FFFF) {
            bytes[0] = (codepoint >> 18) + 0b11110000;
            bytes[1] = ((codepoint >> 12) & 0b111111) + 0b10000000;
            bytes[2] = ((codepoint >> 6) & 0b111111) + 0b10000000;
            bytes[3] = (codepoint & 0b111111) + 0b10000000;
        }

        m_output << bytes.data();
    }

    void executePush(Word code) {
        // std::cout << "PUSH\n";
        if (code >= 0) {
            m_stack.push(code);
        }
    }

private:
    Instruction m_instruction;

    Memory& m_memory;
    Stack& m_stack;
    Registers& m_registers;

    std::istream& m_input;
    std::ostream& m_output;
};

}  // namespace stack_machine
