#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Expression/PrimaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>


namespace ast {

class NestedPrimaryExpression: public PrimaryExpression {
public:
    NestedPrimaryExpression(std::shared_ptr<Expression> expression)
        : m_Expression(expression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<Expression> m_Expression;
};

}  // namespace ast
