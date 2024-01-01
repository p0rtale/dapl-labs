#pragma once

#include <memory>

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
    AdditiveExpression(std::shared_ptr<MultiplicativeExpression> multiplicativeExpression)
        : m_MultiplicativeExpression(multiplicativeExpression) {}

    AdditiveExpression(std::shared_ptr<AdditiveExpression> additiveExpression,
                       std::shared_ptr<MultiplicativeExpression> multiplicativeExpression,
                       Type type)
        : m_Type(type),
          m_AdditiveExpression(additiveExpression),
          m_MultiplicativeExpression(multiplicativeExpression) {}

    // void accept(Visitor *visitor) override;

private:
    Type m_Type = Type::kBlank;

    std::shared_ptr<AdditiveExpression> m_AdditiveExpression;
    std::shared_ptr<MultiplicativeExpression> m_MultiplicativeExpression;
};

}  // namespace ast
