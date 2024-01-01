#pragma once

#include <Clipl/Grammar/AST/Expression/UnaryExpression.hpp>


namespace ast {

class PostfixExpression: public UnaryExpression {
public:
    virtual ~PostfixExpression() = default;

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
