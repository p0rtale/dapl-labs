#pragma once

#include <Clipl/Grammar/AST/Statement/JumpStatement/JumpStatement.hpp>


namespace ast {

class LoopJumpStatement: public JumpStatement {
public:
    enum class Type {
        kContinue,
        kBreak,
    };

public:
    LoopJumpStatement(Type type): m_Type(type) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    Type m_Type;
};

}  // namespace ast
