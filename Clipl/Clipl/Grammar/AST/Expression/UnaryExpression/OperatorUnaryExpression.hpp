#pragma once

#include <Clipl/Grammar/AST/Expression/UnaryExpression/UnaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryOperator.hpp>
#include <Clipl/Grammar/AST/Expression/CastExpression/CastExpression.hpp>


namespace ast {

class OperatorUnaryExpression: public UnaryExpression {
public:
    OperatorUnaryExpression(RefT<UnaryOperator> unaryOperator,
                            RefT<CastExpression> castExpression)
        : m_UnaryOperator(unaryOperator),
          m_CastExpression(castExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<UnaryOperator> GetUnaryOperator() const {
        return m_UnaryOperator;
    }

    RefT<CastExpression> GetCastExpression() const {
        return m_CastExpression;
    }

private:
    RefT<UnaryOperator> m_UnaryOperator;
    RefT<CastExpression> m_CastExpression;
};

}  // namespace ast
