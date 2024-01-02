#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/RelationalExpression.hpp>


namespace ast {

class EqualityExpression: public ASTNode {
public:
    enum class Type {
        kBlank,
        kEqual,
        kNotEqual,
    };

public:
    EqualityExpression(RefT<RelationalExpression> relationalExpression)
        : m_RelationalExpression(relationalExpression) {}

    EqualityExpression(RefT<EqualityExpression> equalityExpression,
                       RefT<RelationalExpression> relationalExpression,
                       Type type)
        : m_Type(type),
          m_EqualityExpression(equalityExpression),
          m_RelationalExpression(relationalExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetTypeStr() const {
        switch (m_Type) {
            case Type::kBlank:    return "";
            case Type::kEqual:    return "==";
            case Type::kNotEqual: return "!=";
            default: {
                CLIPL_ERROR("Invalid type in EqualityExpression");
                return "";
            }
        }
    }

    RefT<EqualityExpression> GetEqualityExpression() const {
        return m_EqualityExpression;
    }

    RefT<RelationalExpression> GetRelationalExpression() const {
        return m_RelationalExpression;
    }

private:
    Type m_Type = Type::kBlank;

    RefT<EqualityExpression> m_EqualityExpression;
    RefT<RelationalExpression> m_RelationalExpression;
};

}  // namespace ast
