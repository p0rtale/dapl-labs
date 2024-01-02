#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/ExternalDeclaration/ExternalDeclaration.hpp>

namespace ast {

class Program: public ASTNode {
public:
    Program(std::vector<RefT<ExternalDeclaration>> externalDeclarations)
        : m_ExternalDeclarations(std::move(externalDeclarations)) {} 

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::vector<RefT<ExternalDeclaration>> GetExternalDeclarations() const {
        return m_ExternalDeclarations;
    }

private:
    std::vector<RefT<ExternalDeclaration>> m_ExternalDeclarations;
};

}  // namespace ast
