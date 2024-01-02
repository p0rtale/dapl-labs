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

    // void accept(Visitor *visitor) override;

private:
    Type m_Type = Type::kBlank;

    RefT<MultiplicativeExpression> m_MultiplicativeExpression;
    RefT<CastExpression> m_CastExpression;
};

}  // namespace ast
