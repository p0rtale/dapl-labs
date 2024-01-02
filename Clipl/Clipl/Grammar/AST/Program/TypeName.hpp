#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/SpecifierQualifierList.hpp>
#include <Clipl/Grammar/AST/Program/AbstractDeclarator.hpp>


namespace ast {

class TypeName: public ASTNode {
public:
    TypeName(std::shared_ptr<SpecifierQualifierList> specifierQualifierList,
             std::shared_ptr<AbstractDeclarator> abstractDeclarator = nullptr)
        : m_SpecifierQualifierList(specifierQualifierList),
          m_AbstractDeclarator(abstractDeclarator) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<SpecifierQualifierList> m_SpecifierQualifierList;
    std::shared_ptr<AbstractDeclarator> m_AbstractDeclarator;
};

}  // namespace ast
