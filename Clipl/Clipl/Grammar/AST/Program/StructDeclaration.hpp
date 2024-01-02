#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/SpecifierQualifierList.hpp>
#include <Clipl/Grammar/AST/Program/StructDeclarator.hpp>


namespace ast {

class StructDeclaration: public ASTNode {
public:
    StructDeclaration(std::shared_ptr<SpecifierQualifierList> specifierQualifierList,
                      std::vector<std::shared_ptr<StructDeclarator>> structDeclaratorList)
        : m_SpecifierQualifierList(specifierQualifierList),
          m_StructDeclaratorList(structDeclaratorList) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<SpecifierQualifierList> m_SpecifierQualifierList;
    std::vector<std::shared_ptr<StructDeclarator>> m_StructDeclaratorList;
};

}  // namespace ast
