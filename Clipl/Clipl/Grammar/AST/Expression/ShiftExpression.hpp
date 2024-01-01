#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/AdditiveExpression.hpp>


namespace ast {

class ShiftExpression: public ASTNode {
public:
    enum class Type {
        kBlank,
        kLeft,
        kRight,
    };

public:
    ShiftExpression(std::shared_ptr<AdditiveExpression> additiveExpression)
        : m_AdditiveExpression(additiveExpression) {}

    ShiftExpression(std::shared_ptr<ShiftExpression> shiftExpression,
                    std::shared_ptr<AdditiveExpression> additiveExpression,
                    Type type)
        : m_Type(type),
          m_ShiftExpression(shiftExpression),
          m_AdditiveExpression(additiveExpression) {}

    // void accept(Visitor *visitor) override;

private:
    Type m_Type = Type::kBlank;

    std::shared_ptr<ShiftExpression> m_ShiftExpression;
    std::shared_ptr<AdditiveExpression> m_AdditiveExpression;
};

}  // namespace ast
