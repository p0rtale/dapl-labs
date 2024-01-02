#pragma once

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
    ShiftExpression(RefT<AdditiveExpression> additiveExpression)
        : m_AdditiveExpression(additiveExpression) {}

    ShiftExpression(RefT<ShiftExpression> shiftExpression,
                    RefT<AdditiveExpression> additiveExpression,
                    Type type)
        : m_Type(type),
          m_ShiftExpression(shiftExpression),
          m_AdditiveExpression(additiveExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    Type m_Type = Type::kBlank;

    RefT<ShiftExpression> m_ShiftExpression;
    RefT<AdditiveExpression> m_AdditiveExpression;
};

}  // namespace ast
