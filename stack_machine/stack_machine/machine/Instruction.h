#pragma once

#include <StackMachine/AsmCompiler/Lexer.h>

namespace stack_machine {

enum class Instruction {
    kBlank = 0,

    kAdd = -1,
    kSub = -2,
    kDiv = -3,
    kMod = -4,
    kMul = -5,
    kNeg = -6,

    kBitAnd = -7,
    kBitOr = -8,
    kBitNot = -9,

    kDup = -10,
    kDrop = -11,
    kSwap = -12,
    kRot = -13,
    kOver = -14,
    kDropn = -35,
    kPushn = -36,

    kRead = -15,
    kWrite = -16,

    kCmp = -17,
    kJmp = -18,
    kJlt = -19,
    kJgt = -20,
    kJeq = -21,
    kJle = -22,
    kJge = -23,
    kJne = -24,
    kCall = -25,
    kRetn = -26,
    kHalt = -32,

    kGetSp = -27,
    kSetSp = -28,
    kGetBp = -29,
    kSetBp = -30,
    kGetCp = -31,

    kIn = -33,
    kOut = -34,
};

}  // namespace stack_machine
