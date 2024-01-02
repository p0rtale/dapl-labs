#pragma once

#include <string>

#include <Clipl/Grammar/AST/Expression/PostfixExpression/PostfixExpression.hpp>


namespace ast {

class IncDecPostfixExpression: public PostfixExpression {
public:
    enum class Type {
        kPlus,
        kMinus,
    };

public:
    IncDecPostfixExpression(RefT<PostfixExpression> postfixExpression,
                            Type type)
        : m_Type(type),
          m_PostfixExpression(postfixExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    Type m_Type;

    RefT<PostfixExpression> m_PostfixExpression;
};

}  // namespace ast
