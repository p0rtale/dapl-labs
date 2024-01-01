#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/BaseDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers.hpp>


namespace ast {

class ParameterDeclaration: public ASTNode {
public:
    ParameterDeclaration(std::shared_ptr<DeclarationSpecifiers> declarationSpecifiers,
                         std::shared_ptr<BaseDeclarator> baseDeclarator = nullptr)
        : m_DeclarationSpecifiers(declarationSpecifiers),
          m_BaseDeclarator(baseDeclarator) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<DeclarationSpecifiers> m_DeclarationSpecifiers;
    std::shared_ptr<BaseDeclarator> m_BaseDeclarator;
};

}  // namespace ast
