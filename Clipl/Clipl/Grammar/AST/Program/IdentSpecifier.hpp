#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class IdentSpecifier: public ASTNode {
public:
    IdentSpecifier(std::string identifier)
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
