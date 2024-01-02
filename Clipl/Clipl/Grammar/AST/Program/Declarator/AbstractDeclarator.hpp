#pragma once

#include <Clipl/Grammar/AST/Program/Declarator/BaseDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/Pointer.hpp>
#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator/DirectAbstractDeclarator.hpp>

namespace ast {

class AbstractDeclarator: public BaseDeclarator {
public:
    AbstractDeclarator(RefT<Pointer> pointer)
        : m_Pointer(pointer) {}

    AbstractDeclarator(RefT<DirectAbstractDeclarator> directAbstractDeclarator,
                       RefT<Pointer> pointer = nullptr)
        : m_Pointer(pointer),
          m_DirectAbstractDeclarator(directAbstractDeclarator) {};

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<Pointer> GetPointer() const {
        return m_Pointer;
    }

    RefT<DirectAbstractDeclarator> GetDirectAbstractDeclarator() const {
        return m_DirectAbstractDeclarator;
    }

private:
    RefT<Pointer> m_Pointer;
    RefT<DirectAbstractDeclarator> m_DirectAbstractDeclarator;
};

}  // namespace ast
