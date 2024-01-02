#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/Declarator/Declarator.hpp>


namespace ast {

class StructDeclarator: public ASTNode {
public:
    StructDeclarator(RefT<Declarator> declarator)
        : m_Declarator(declarator) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<Declarator> GetDeclarator() const {
        return m_Declarator;
    }

private:
    RefT<Declarator> m_Declarator;
};

}  // namespace ast
