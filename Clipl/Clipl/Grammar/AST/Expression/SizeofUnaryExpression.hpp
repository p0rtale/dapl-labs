#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Expression/UnaryExpression.hpp>


namespace ast {

class SizeofUnaryExpression: public UnaryExpression {
public:
    SizeofUnaryExpression(std::shared_ptr<UnaryExpression> unaryExpression)
        : m_UnaryExpression(unaryExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<UnaryExpression> m_UnaryExpression;
};

}  // namespace ast
