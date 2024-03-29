#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/Declarator/BaseDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers/DeclarationSpecifiers.hpp>


namespace ast {

class ParameterDeclaration: public ASTNode {
public:
    ParameterDeclaration(RefT<DeclarationSpecifiers> declarationSpecifiers,
                         RefT<BaseDeclarator> baseDeclarator = nullptr)
        : m_DeclarationSpecifiers(declarationSpecifiers),
          m_BaseDeclarator(baseDeclarator) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<DeclarationSpecifiers> GetDeclarationSpecifiers() const {
        return m_DeclarationSpecifiers;
    }

    RefT<BaseDeclarator> GetBaseDeclarator() const {
        return m_BaseDeclarator;
    }

private:
    RefT<DeclarationSpecifiers> m_DeclarationSpecifiers;
    RefT<BaseDeclarator> m_BaseDeclarator;
};

}  // namespace ast
