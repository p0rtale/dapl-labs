#pragma once

#include <Clipl/Grammar/AST/Expression/UnaryExpression/UnaryExpression.hpp>


namespace ast {

class IncDecPrefixExpression: public UnaryExpression {
public:
    enum class Type {
        kPlus,
        kMinus,
    };

public:
    IncDecPrefixExpression(RefT<UnaryExpression> unaryExpression,
                           Type type)
        : m_Type(type),
          m_UnaryExpression(unaryExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetTypeStr() const {
        switch (m_Type) {
            case Type::kPlus:  return "++";
            case Type::kMinus: return "--";
            default: {
                CLIPL_ERROR("Invalid type in IncDecPrefixExpression");
                return "";
            }
        }
    }

    RefT<UnaryExpression> GetUnaryExpression() const {
        return m_UnaryExpression;
    }

private:
    Type m_Type;

    RefT<UnaryExpression> m_UnaryExpression;
};

}  // namespace ast
