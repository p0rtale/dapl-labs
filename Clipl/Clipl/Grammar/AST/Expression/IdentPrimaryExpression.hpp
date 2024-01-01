#pragma once

#include <string>

#include <Clipl/Grammar/AST/Expression/PrimaryExpression.hpp>


namespace ast {

class IdentPrimaryExpression: public PrimaryExpression {
public:
    IdentPrimaryExpression(std::string identifier)
        : m_Identifier(std::move(identifier)) {}

    // void accept(Visitor *visitor) override;

private:
    std::string m_Identifier;
};

}  // namespace ast
