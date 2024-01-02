#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/CastExpression/CastExpression.hpp>


namespace ast {

class MultiplicativeExpression: public ASTNode {
public:
    enum class Type {
        kBlank,
        kMult,
        kDiv,
        kMod,
    };

public:
    MultiplicativeExpression(RefT<CastExpression> castExpression)
        : m_CastExpression(castExpression) {}

    MultiplicativeExpression(RefT<MultiplicativeExpression> multiplicativeExpression,
                             RefT<CastExpression> castExpression,
                             Type type)
        : m_Type(type),
          m_MultiplicativeExpression(multiplicativeExpression),
          m_CastExpression(castExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetTypeStr() const {
        switch (m_Type) {
            case Type::kBlank: return "";
            case Type::kMult:  return "*";
            case Type::kDiv:   return "/";
            case Type::kMod:   return "%";
            default: {
                CLIPL_ERROR("Invalid type in MultiplicativeExpression");
                return "";
            }
        }
    }

    RefT<MultiplicativeExpression> GetMultiplicativeExpression() const {
        return m_MultiplicativeExpression;
    }

    RefT<CastExpression> GetCastExpression() const {
        return m_CastExpression;
    }

private:
    Type m_Type = Type::kBlank;

    RefT<MultiplicativeExpression> m_MultiplicativeExpression;
    RefT<CastExpression> m_CastExpression;
};

}  // namespace ast
