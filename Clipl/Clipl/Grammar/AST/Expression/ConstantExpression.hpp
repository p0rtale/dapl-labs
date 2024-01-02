#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/ConditionalExpression.hpp>


namespace ast {

class ConstantExpression: public ASTNode {
public:
    ConstantExpression(RefT<ConditionalExpression> conditionalExpression)
        : m_ConditionalExpression(conditionalExpression) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<ConditionalExpression> m_ConditionalExpression;
};

}  // namespace ast
