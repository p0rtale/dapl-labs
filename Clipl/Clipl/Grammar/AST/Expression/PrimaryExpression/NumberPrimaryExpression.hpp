#pragma once

#include <Clipl/Grammar/AST/Expression/PrimaryExpression/PrimaryExpression.hpp>


namespace ast {

class NumberPrimaryExpression: public PrimaryExpression {
public:
    NumberPrimaryExpression(int number)
        : m_Number(number) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    int GetNumber() const {
        return m_Number;
    }

private:
    int m_Number;
};

}  // namespace ast
