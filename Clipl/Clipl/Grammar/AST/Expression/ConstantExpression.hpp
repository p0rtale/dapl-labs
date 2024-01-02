#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/ConditionalExpression.hpp>


namespace ast {

class ConstantExpression: public ASTNode {
public:
    ConstantExpression(RefT<ConditionalExpression> conditionalExpression)
        : m_ConditionalExpression(conditionalExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    RefT<ConditionalExpression> m_ConditionalExpression;
};

}  // namespace ast
