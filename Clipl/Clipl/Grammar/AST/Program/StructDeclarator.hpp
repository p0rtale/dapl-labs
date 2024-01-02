#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/Declarator.hpp>


namespace ast {

class StructDeclarator: public ASTNode {
public:
    StructDeclarator(std::shared_ptr<Declarator> declarator)
        : m_Declarator(declarator) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<Declarator> m_Declarator;
};

}  // namespace ast
