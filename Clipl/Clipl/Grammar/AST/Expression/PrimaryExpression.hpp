#pragma once

#include <Clipl/Grammar/AST/Expression/PostfixExpression.hpp>


namespace ast {

class PrimaryExpression: public PostfixExpression {
public:
    PrimaryExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
