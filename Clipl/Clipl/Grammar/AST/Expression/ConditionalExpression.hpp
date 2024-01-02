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
          m_ConditionalExpression(conditionalExpression) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<LogicalOrExpression> m_Condition;
    RefT<Expression> m_Expression;
    RefT<ConditionalExpression> m_ConditionalExpression;
};

}  // namespace ast
