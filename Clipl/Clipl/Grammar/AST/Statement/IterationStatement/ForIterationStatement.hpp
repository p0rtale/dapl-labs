#pragma once

#include <Clipl/Grammar/AST/Statement/IterationStatement/IterationStatement.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>
#include <Clipl/Grammar/AST/Statement/ExpressionStatement.hpp>


namespace ast {

class ForIterationStatement: public IterationStatement {
public:
    ForIterationStatement(RefT<Statement> statement,
                          RefT<ExpressionStatement> initExpressionStatement,
                          RefT<ExpressionStatement> condExpressionStatement,
                          RefT<Expression> loopExpression = nullptr)
        : m_InitExpressionStatement(initExpressionStatement),
          m_CondExpressionStatement(condExpressionStatement),
          m_LoopExpression(loopExpression),
          m_Statement(statement) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<ExpressionStatement> GetInitExpressionStatement() const {
        return m_InitExpressionStatement;
    }

    RefT<ExpressionStatement> GetCondExpressionStatement() const {
        return m_CondExpressionStatement;
    }

    RefT<Expression> GetLoopExpression() const {
        return m_LoopExpression;
    }

    RefT<Statement> GetStatement() const {
        return m_Statement;
    }

private:
    RefT<ExpressionStatement> m_InitExpressionStatement;
    RefT<ExpressionStatement> m_CondExpressionStatement;
    RefT<Expression> m_LoopExpression;
    RefT<Statement> m_Statement;
};

}  // namespace ast
