#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/SpecifierQualifierList.hpp>
#include <Clipl/Grammar/AST/Program/Declarator/AbstractDeclarator.hpp>


namespace ast {

class TypeName: public ASTNode {
public:
    TypeName(RefT<SpecifierQualifierList> specifierQualifierList,
             RefT<AbstractDeclarator> abstractDeclarator = nullptr)
        : m_SpecifierQualifierList(specifierQualifierList),
          m_AbstractDeclarator(abstractDeclarator) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    RefT<SpecifierQualifierList> m_SpecifierQualifierList;
    RefT<AbstractDeclarator> m_AbstractDeclarator;
};

}  // namespace ast
