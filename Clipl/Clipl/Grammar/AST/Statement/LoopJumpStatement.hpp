#pragma once

#include <Clipl/Grammar/AST/Statement/JumpStatement.hpp>


namespace ast {

class LoopJumpStatement: public JumpStatement {
public:
    enum class Type {
        kContinue,
        kBreak,
    };

public:
    LoopJumpStatement(Type type): m_Type(type) {}

    // void accept(Visitor *visitor) override;

private:
    Type m_Type;
};

}  // namespace ast
