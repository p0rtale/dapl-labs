#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>
#include <Clipl/Grammar/AST/Expression/LogicalOrExpression.hpp>


namespace ast {

class ConditionalExpression: public ASTNode {
public:
    ConditionalExpression(std::shared_ptr<LogicalOrExpression> condition)
        : m_Condition(condition) {}

    ConditionalExpression(std::shared_ptr<LogicalOrExpression> condition,
                          std::shared_ptr<Expression> expression,
                          std::shared_ptr<ConditionalExpression> conditionalExpression)
        : m_Condition(condition),
          m_Expression(expression),
          m_ConditionalExpression(conditionalExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<LogicalOrExpression> m_Condition = nullptr;
    std::shared_ptr<Expression> m_Expression = nullptr;
    std::shared_ptr<ConditionalExpression> m_ConditionalExpression = nullptr;
};

}  // namespace ast
