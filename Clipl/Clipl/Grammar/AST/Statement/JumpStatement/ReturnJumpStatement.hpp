#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Statement/JumpStatement/JumpStatement.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>


namespace ast {

class ReturnJumpStatement: public JumpStatement {
public:
    ReturnJumpStatement(std::shared_ptr<Expression> expression = nullptr)
        : m_Expression(expression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<Expression> m_Expression;
};

}  // namespace ast
