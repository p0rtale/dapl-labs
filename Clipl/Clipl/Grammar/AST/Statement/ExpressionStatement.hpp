#pragma once

#include <Clipl/Grammar/AST/Statement/Statement.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>


namespace ast {

class ExpressionStatement: public Statement {
public:
    ExpressionStatement(RefT<Expression> expression)
        : m_Expression(expression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    RefT<Expression> m_Expression;
};

}  // namespace ast
