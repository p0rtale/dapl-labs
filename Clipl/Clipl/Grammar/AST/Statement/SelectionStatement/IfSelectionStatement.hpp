#pragma once

#include <Clipl/Grammar/AST/Statement/SelectionStatement/SelectionStatement.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class IfSelectionStatement: public SelectionStatement {
public:
    IfSelectionStatement(RefT<Expression> expression,
                         RefT<Statement> statementTrue,
                         RefT<Statement> statementFalse = nullptr)
        : m_Expression(expression),
          m_StatementTrue(statementTrue),
          m_StatementFalse(statementFalse) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<Expression> GetExpression() const {
        return m_Expression;
    }
     
    RefT<Statement> GetStatementTrue() const {
        return m_StatementTrue;
    }

    RefT<Statement> GetStatementFalse() const {
        return m_StatementFalse;
    }

private:
    RefT<Expression> m_Expression;
    RefT<Statement> m_StatementTrue;
    RefT<Statement> m_StatementFalse;
};

}  // namespace ast
