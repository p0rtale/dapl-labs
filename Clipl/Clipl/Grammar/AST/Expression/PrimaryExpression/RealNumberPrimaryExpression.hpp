#pragma once

#include <Clipl/Grammar/AST/Expression/PrimaryExpression/PrimaryExpression.hpp>


namespace ast {

class RealNumberPrimaryExpression: public PrimaryExpression {
public:
    RealNumberPrimaryExpression(float real)
        : m_RealNumber(real) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    float GetRealNumber() const {
        return m_RealNumber;
    }

private:
    float m_RealNumber;
};

}  // namespace ast
