#pragma once

#include <string>
#include <memory>

#include <Clipl/Grammar/AST/Expression/PostfixExpression.hpp>


namespace ast {

class AccessExpression: public PostfixExpression {
public:
    enum class Type {
        kDot,
        kArrow,
    };

public:
    AccessExpression(std::shared_ptr<PostfixExpression> postfixExpression,
                     std::string identifier, Type type)
        : m_Type(type),
          m_PostfixExpression(postfixExpression),
          m_Identifier(std::move(identifier)) {}

    // void accept(Visitor *visitor) override;

private:
    Type m_Type;

    std::shared_ptr<PostfixExpression> m_PostfixExpression;
    std::string m_Identifier;
};

}  // namespace ast
