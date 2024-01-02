#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/MultiplicativeExpression.hpp>


namespace ast {

class AdditiveExpression: public ASTNode {
public:
    enum class Type {
        kBlank,
        kPlus,
        kMinus,
    };

public:
    AdditiveExpression(RefT<MultiplicativeExpression> multiplicativeExpression)
        : m_MultiplicativeExpression(multiplicativeExpression) {}

    AdditiveExpression(RefT<AdditiveExpression> additiveExpression,
                       RefT<MultiplicativeExpression> multiplicativeExpression,
                       Type type)
        : m_Type(type),
          m_AdditiveExpression(additiveExpression),
          m_MultiplicativeExpression(multiplicativeExpression) {}

    // void accept(Visitor *visitor) override;

private:
    Type m_Type = Type::kBlank;

    RefT<AdditiveExpression> m_AdditiveExpression;
    RefT<MultiplicativeExpression> m_MultiplicativeExpression;
};

}  // namespace ast
