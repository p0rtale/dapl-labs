#pragma once

#include <memory>

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
    MultiplicativeExpression(std::shared_ptr<CastExpression> castExpression)
        : m_CastExpression(castExpression) {}

    MultiplicativeExpression(std::shared_ptr<MultiplicativeExpression> multiplicativeExpression,
                             std::shared_ptr<CastExpression> castExpression,
                             Type type)
        : m_Type(type),
          m_MultiplicativeExpression(multiplicativeExpression),
          m_CastExpression(castExpression) {}

    // void accept(Visitor *visitor) override;

private:
    Type m_Type = Type::kBlank;

    std::shared_ptr<MultiplicativeExpression> m_MultiplicativeExpression;
    std::shared_ptr<CastExpression> m_CastExpression;
};

}  // namespace ast
