#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>
#include <Clipl/Grammar/AST/Expression/LogicalOrExpression.hpp>


namespace ast {

class ConditionalExpression: public ASTNode {
public:
    ConditionalExpression(RefT<LogicalOrExpression> condition)
        : m_Condition(condition) {}

    ConditionalExpression(RefT<LogicalOrExpression> condition,
                          RefT<Expression> expression,
                          RefT<ConditionalExpression> conditionalExpression)
        : m_Condition(condition),
          m_Expression(expression),
          m_ConditionalExpressionFalse(conditionalExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<LogicalOrExpression> GetCondition() const {
        return m_Condition;
    }

    RefT<Expression> GetExpression() const {
        return m_Expression;
    }

    RefT<ConditionalExpression> GetConditionalExpressionFalse() const {
        return m_ConditionalExpressionFalse;
    }

private:
    RefT<LogicalOrExpression> m_Condition;
    RefT<Expression> m_Expression;
    RefT<ConditionalExpression> m_ConditionalExpressionFalse;
};

}  // namespace ast
