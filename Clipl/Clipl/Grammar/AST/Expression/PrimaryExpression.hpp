#pragma once

#include <Clipl/Grammar/AST/Expression/PostfixExpression.hpp>


namespace ast {

class PrimaryExpression: public PostfixExpression {
public:
    virtual ~PrimaryExpression() = default;

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
