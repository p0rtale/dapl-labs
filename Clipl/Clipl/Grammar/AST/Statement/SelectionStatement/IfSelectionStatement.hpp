#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Statement/SelectionStatement/SelectionStatement.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class IfSelectionStatement: public SelectionStatement {
public:
    IfSelectionStatement(std::shared_ptr<Expression> expression,
                         std::shared_ptr<Statement> statementTrue,
                         std::shared_ptr<Statement> statementFalse = nullptr)
        : m_Expression(expression),
          m_StatementTrue(statementTrue),
          m_StatementFalse(statementFalse) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<Expression> m_Expression;
    std::shared_ptr<Statement> m_StatementTrue;
    std::shared_ptr<Statement> m_StatementFalse;
};

}  // namespace ast
