#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/Pointer.hpp>
#include <Clipl/Grammar/AST/Program/DirectDeclarator.hpp>

namespace ast {

class Declarator: public ASTNode {
public:
    Declarator(std::shared_ptr<DirectDeclarator> directDeclarator,
               std::shared_ptr<Pointer> pointer = nullptr)
        : m_Pointer(pointer),
          m_DirectDeclarator(directDeclarator) {};

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<Pointer> m_Pointer;
    std::shared_ptr<DirectDeclarator> m_DirectDeclarator;
};

}  // namespace ast
