#pragma once

#include <string>

#include <Clipl/Grammar/AST/Expression/PostfixExpression/PostfixExpression.hpp>


namespace ast {

class AccessExpression: public PostfixExpression {
public:
    enum class Type {
        kDot,
        kArrow,
    };

public:
    AccessExpression(RefT<PostfixExpression> postfixExpression,
                     std::string identifier, Type type)
        : m_Type(type),
          m_PostfixExpression(postfixExpression),
          m_Identifier(std::move(identifier)) {}

    // void accept(Visitor *visitor) override;

private:
    Type m_Type;

    RefT<PostfixExpression> m_PostfixExpression;
    std::string m_Identifier;
};

}  // namespace ast
