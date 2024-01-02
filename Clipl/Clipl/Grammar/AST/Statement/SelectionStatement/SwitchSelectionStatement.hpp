#pragma once

#include <Clipl/Grammar/AST/Statement/SelectionStatement/SelectionStatement.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class SwitchSelectionStatement: public SelectionStatement {
public:
    SwitchSelectionStatement(RefT<Expression> expression,
                             RefT<Statement> statement)
        : m_Expression(expression),
          m_Statement(statement) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    RefT<Expression> m_Expression;
    RefT<Statement> m_Statement;
};

}  // namespace ast
