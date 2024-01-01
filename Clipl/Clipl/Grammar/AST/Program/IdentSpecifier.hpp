#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class IdentSpecifier: public ASTNode {
public:
    IdentSpecifier(std::string identifier)
        : m_Identifier(std::move(identifier)) {}

    // void accept(Visitor *visitor) override;

private:
    std::string m_Identifier;
};

}  // namespace ast
