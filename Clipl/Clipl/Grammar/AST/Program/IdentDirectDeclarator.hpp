#pragma once

#include <string>

#include <Clipl/Grammar/AST/Program/DirectDeclarator.hpp>


namespace ast {

class IdentDirectDeclarator: public DirectDeclarator {
public:
    IdentDirectDeclarator(std::string identifier)
        : m_Identifier(std::move(identifier)) {};

    // void accept(Visitor *visitor) override;

private:
    std::string m_Identifier;
};

}  // namespace ast
