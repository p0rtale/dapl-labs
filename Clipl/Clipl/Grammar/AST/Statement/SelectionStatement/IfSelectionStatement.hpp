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

    // void accept(Visitor *visitor) override;

private:
    RefT<Expression> m_Expression;
    RefT<Statement> m_StatementTrue;
    RefT<Statement> m_StatementFalse;
};

}  // namespace ast
