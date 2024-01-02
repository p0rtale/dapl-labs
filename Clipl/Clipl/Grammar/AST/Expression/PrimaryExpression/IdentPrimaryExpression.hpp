#pragma once

#include <string>

#include <Clipl/Grammar/AST/Expression/PrimaryExpression/PrimaryExpression.hpp>


namespace ast {

class IdentPrimaryExpression: public PrimaryExpression {
public:
    IdentPrimaryExpression(std::string identifier)
        : m_Identifier(std::move(identifier)) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetIdentifier() const {
        return m_Identifier;
    }

private:
    std::string m_Identifier;
};

}  // namespace ast
