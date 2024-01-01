#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Statement/IterationStatement.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>
#include <Clipl/Grammar/AST/Statement/ExpressionStatement.hpp>


namespace ast {

class ForIterationStatement: public IterationStatement {
public:
    ForIterationStatement(std::shared_ptr<Statement> statement,
                          std::shared_ptr<ExpressionStatement> initExpressionStatement,
                          std::shared_ptr<ExpressionStatement> condExpressionStatement,
                          std::shared_ptr<Expression> loopExpression = nullptr)
        : m_InitExpressionStatement(initExpressionStatement),
          m_CondExpressionStatement(condExpressionStatement),
          m_LoopExpression(loopExpression),
          m_Statement(statement) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<ExpressionStatement> m_InitExpressionStatement;
    std::shared_ptr<ExpressionStatement> m_CondExpressionStatement;
    std::shared_ptr<Expression> m_LoopExpression;
    std::shared_ptr<Statement> m_Statement;
};

}  // namespace ast
