#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Expression/UnaryExpression/UnaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryOperator.hpp>
#include <Clipl/Grammar/AST/Expression/CastExpression/CastExpression.hpp>


namespace ast {

class OperatorUnaryExpression: public UnaryExpression {
public:
    OperatorUnaryExpression(std::shared_ptr<UnaryOperator> unaryOperator,
                            std::shared_ptr<CastExpression> castExpression)
        : m_UnaryOperator(unaryOperator),
          m_CastExpression(castExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<UnaryOperator> m_UnaryOperator;
    std::shared_ptr<CastExpression> m_CastExpression;
};

}  // namespace ast
