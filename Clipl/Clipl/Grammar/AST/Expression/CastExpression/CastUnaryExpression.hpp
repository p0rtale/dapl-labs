#pragma once

#include <Clipl/Grammar/AST/Expression/CastExpression/CastExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryExpression/UnaryExpression.hpp>


namespace ast {

class CastUnaryExpression: public CastExpression {
public:
    CastUnaryExpression(RefT<UnaryExpression> unaryExpression)
        : m_UnaryExpression(unaryExpression) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<UnaryExpression> m_UnaryExpression;
};

}  // namespace ast
