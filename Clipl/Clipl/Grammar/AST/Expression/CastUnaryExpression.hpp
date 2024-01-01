#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Expression/CastExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryExpression.hpp>


namespace ast {

class CastUnaryExpression: public CastExpression {
public:
    CastUnaryExpression(std::shared_ptr<UnaryExpression> unaryExpression)
        : m_UnaryExpression(unaryExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<UnaryExpression> m_UnaryExpression;
};

}  // namespace ast
