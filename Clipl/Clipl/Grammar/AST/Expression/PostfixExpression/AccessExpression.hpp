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

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetTypeStr() const {
        switch (m_Type) {
            case Type::kDot:   return ".";
            case Type::kArrow: return "->";
            default: {
                CLIPL_ERROR("Invalid type in AccessExpression");
                return "";
            }
        }
    }

    RefT<PostfixExpression> GetPostfixExpression() const {
        return m_PostfixExpression;;
    }

    std::string GetIdentifier() const {
        return m_Identifier;
    }

private:
    Type m_Type;

    RefT<PostfixExpression> m_PostfixExpression;
    std::string m_Identifier;
};

}  // namespace ast
