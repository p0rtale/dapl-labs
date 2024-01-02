#pragma once

#include <Clipl/Grammar/AST/Statement/IterationStatement/IterationStatement.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>

namespace ast {

class WhileIterationStatement: public IterationStatement {
public:
    WhileIterationStatement(RefT<Expression> expression,
                            RefT<Statement> statement)
        : m_Expression(expression),
          m_Statement(statement) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<Expression> m_Expression;
    RefT<Statement> m_Statement;
};

}  // namespace ast
