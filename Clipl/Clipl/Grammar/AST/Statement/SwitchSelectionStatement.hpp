#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Statement/SelectionStatement.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class SwitchSelectionStatement: public SelectionStatement {
public:
    SwitchSelectionStatement(std::shared_ptr<Expression> expression,
                         std::shared_ptr<Statement> statement)
        : m_Expression(expression),
          m_Statement(statement) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<Expression> m_Expression;
    std::shared_ptr<Statement> m_Statement;
};

}  // namespace ast
