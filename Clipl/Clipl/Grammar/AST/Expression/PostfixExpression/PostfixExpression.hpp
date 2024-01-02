#pragma once

#include <Clipl/Grammar/AST/Expression/UnaryExpression/UnaryExpression.hpp>


namespace ast {

class PostfixExpression: public UnaryExpression {
public:
    virtual ~PostfixExpression() = default;

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }
};

}  // namespace ast
