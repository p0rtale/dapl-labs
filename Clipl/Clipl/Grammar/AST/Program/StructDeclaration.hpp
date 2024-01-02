#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/SpecifierQualifierList.hpp>
#include <Clipl/Grammar/AST/Program/StructDeclarator.hpp>


namespace ast {

class StructDeclaration: public ASTNode {
public:
    StructDeclaration(RefT<SpecifierQualifierList> specifierQualifierList,
                      std::vector<RefT<StructDeclarator>> structDeclaratorList)
        : m_SpecifierQualifierList(specifierQualifierList),
          m_StructDeclaratorList(structDeclaratorList) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<SpecifierQualifierList> m_SpecifierQualifierList;
    std::vector<RefT<StructDeclarator>> m_StructDeclaratorList;
};

}  // namespace ast
