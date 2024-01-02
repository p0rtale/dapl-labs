#pragma once

#include <Clipl/Grammar/AST/Expression/PrimaryExpression/PrimaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>


namespace ast {

class NestedPrimaryExpression: public PrimaryExpression {
public:
    NestedPrimaryExpression(RefT<Expression> expression)
        : m_Expression(expression) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<Expression> m_Expression;
};

}  // namespace ast
