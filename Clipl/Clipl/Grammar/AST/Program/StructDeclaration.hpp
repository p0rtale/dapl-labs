#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers/DeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/StructDeclarator.hpp>


namespace ast {

class StructDeclaration: public ASTNode {
public:
    StructDeclaration(RefT<DeclarationSpecifiers> declarationSpecifiers,
                      std::vector<RefT<StructDeclarator>> structDeclaratorList)
        : m_DeclarationSpecifiers(declarationSpecifiers),
          m_StructDeclaratorList(structDeclaratorList) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<DeclarationSpecifiers> GetDeclarationSpecifiers() const {
        return m_DeclarationSpecifiers;
    }

    std::vector<RefT<StructDeclarator>> GetStructDeclaratorList() const {
        return m_StructDeclaratorList;
    }

private:
    RefT<DeclarationSpecifiers> m_DeclarationSpecifiers;
    std::vector<RefT<StructDeclarator>> m_StructDeclaratorList;
};

}  // namespace ast
