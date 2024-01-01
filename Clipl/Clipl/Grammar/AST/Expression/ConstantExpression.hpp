#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/ConditionalExpression.hpp>


namespace ast {

class ConstantExpression: public ASTNode {
public:
    ConstantExpression(std::shared_ptr<ConditionalExpression> conditionalExpression)
        : m_ConditionalExpression(conditionalExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<ConditionalExpression> m_ConditionalExpression;
};

}  // namespace ast
