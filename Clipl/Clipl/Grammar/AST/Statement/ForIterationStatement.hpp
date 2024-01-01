#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Statement/IterationStatement.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>

namespace ast {

class ForIterationStatement: public IterationStatement {
public:
    ForIterationStatement(std::shared_ptr<Statement> statement,
                          std::shared_ptr<Expression> initExpression,
                          std::shared_ptr<Expression> condExpression,
                          std::shared_ptr<Expression> loopExpression = nullptr)
        : m_InitExpression(initExpression),
          m_CondExpression(condExpression),
          m_LoopExpression(loopExpression),
          m_Statement(statement) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<Expression> m_InitExpression;
    std::shared_ptr<Expression> m_CondExpression;
    std::shared_ptr<Expression> m_LoopExpression;
    std::shared_ptr<Statement> m_Statement;
};

}  // namespace ast
