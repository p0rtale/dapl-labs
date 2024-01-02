#pragma once

#include <Clipl/Grammar/AST/Statement/JumpStatement/JumpStatement.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>


namespace ast {

class ReturnJumpStatement: public JumpStatement {
public:
    ReturnJumpStatement(RefT<Expression> expression = nullptr)
        : m_Expression(expression) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<Expression> m_Expression;
};

}  // namespace ast
