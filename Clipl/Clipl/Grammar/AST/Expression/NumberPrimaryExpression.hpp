#pragma once

#include <Clipl/Grammar/AST/Expression/PrimaryExpression.hpp>


namespace ast {

class NumberPrimaryExpression: public PrimaryExpression {
public:
    NumberPrimaryExpression(int number)
        : m_Number(number) {}

    // void accept(Visitor *visitor) override;

private:
    int m_Number;
};

}  // namespace ast
