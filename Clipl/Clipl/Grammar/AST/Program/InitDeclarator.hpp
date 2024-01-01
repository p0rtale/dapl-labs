#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/Declarator.hpp>
#include <Clipl/Grammar/AST/Program/Initializer.hpp>


namespace ast {

class InitDeclarator: public ASTNode {
public:
    InitDeclarator(std::shared_ptr<Declarator> declarator,
                   std::shared_ptr<Initializer> initializer = nullptr)
        : m_Declarator(declarator),
          m_Initializer(initializer) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<Declarator> m_Declarator;
    std::shared_ptr<Initializer> m_Initializer;
};

}  // namespace ast
