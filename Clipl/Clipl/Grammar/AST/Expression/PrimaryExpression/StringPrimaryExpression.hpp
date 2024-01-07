#pragma once

#include <Clipl/Grammar/AST/Expression/PrimaryExpression/PrimaryExpression.hpp>


namespace ast {

class StringPrimaryExpression: public PrimaryExpression {
public:
    StringPrimaryExpression(std::string stringLiteral) {
        size_t size = stringLiteral.size();
        if (stringLiteral.empty() || stringLiteral[0] == '\"' ||
                stringLiteral[size - 1] == '\"') {
            CLIPL_CRITICAL("ERROR StringPrimaryExpression: invalid string literal (check lexer)");
        }
        m_StringLiteral = std::move(stringLiteral.substr(1, size - 2));
    }

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetStringLiteral() const {
        return m_StringLiteral;
    }

private:
    std::string m_StringLiteral;
};

}  // namespace ast
