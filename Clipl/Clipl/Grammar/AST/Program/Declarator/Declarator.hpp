#pragma once

#include <Clipl/Grammar/AST/Program/Declarator/BaseDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/Pointer.hpp>
#include <Clipl/Grammar/AST/Program/DirectDeclarator/DirectDeclarator.hpp>

namespace ast {

class Declarator: public BaseDeclarator {
public:
    Declarator(RefT<DirectDeclarator> directDeclarator,
               RefT<Pointer> pointer = nullptr)
        : m_Pointer(pointer),
          m_DirectDeclarator(directDeclarator) {};

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    RefT<Pointer> m_Pointer;
    RefT<DirectDeclarator> m_DirectDeclarator;
};

}  // namespace ast
