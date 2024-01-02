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

    // void accept(Visitor *visitor) override;

private:
    RefT<DeclarationSpecifiers> m_DeclarationSpecifiers;
    RefT<BaseDeclarator> m_BaseDeclarator;
};

}  // namespace ast
