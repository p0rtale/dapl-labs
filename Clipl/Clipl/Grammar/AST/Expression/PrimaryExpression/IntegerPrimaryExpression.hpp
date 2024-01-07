#pragma once

#include <Clipl/Grammar/AST/Expression/PrimaryExpression/PrimaryExpression.hpp>


namespace ast {

class IntegerPrimaryExpression: public PrimaryExpression {
public:
    IntegerPrimaryExpression(int integer)
        : m_Integer(integer) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    int GetInteger() const {
        return m_Integer;
    }

private:
    int m_Integer;
};

}  // namespace ast
