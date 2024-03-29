#pragma once

#include <Clipl/Grammar/AST/Expression/UnaryExpression/UnaryExpression.hpp>


namespace ast {

class SizeofUnaryExpression: public UnaryExpression {
public:
    SizeofUnaryExpression(RefT<UnaryExpression> unaryExpression)
        : m_UnaryExpression(unaryExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<UnaryExpression> GetUnaryExpression() const {
        return m_UnaryExpression;
    }

private:
    RefT<UnaryExpression> m_UnaryExpression;
};

}  // namespace ast
