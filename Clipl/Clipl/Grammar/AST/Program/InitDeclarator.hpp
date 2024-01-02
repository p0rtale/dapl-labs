#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/Declarator/Declarator.hpp>
#include <Clipl/Grammar/AST/Program/Initializer/Initializer.hpp>


namespace ast {

class InitDeclarator: public ASTNode {
public:
    InitDeclarator(RefT<Declarator> declarator,
                   RefT<Initializer> initializer = nullptr)
        : m_Declarator(declarator),
          m_Initializer(initializer) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    RefT<Declarator> m_Declarator;
    RefT<Initializer> m_Initializer;
};

}  // namespace ast
