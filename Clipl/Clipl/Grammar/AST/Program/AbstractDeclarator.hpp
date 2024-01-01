#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Program/BaseDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/Pointer.hpp>
#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator.hpp>

namespace ast {

class AbstractDeclarator: public BaseDeclarator {
public:
    AbstractDeclarator(std::shared_ptr<Pointer> pointer)
        : m_Pointer(pointer) {}

    AbstractDeclarator(std::shared_ptr<DirectAbstractDeclarator> directAbstractDeclarator,
                       std::shared_ptr<Pointer> pointer = nullptr)
        : m_Pointer(pointer),
          m_DirectAbstractDeclarator(directAbstractDeclarator) {};

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<Pointer> m_Pointer;
    std::shared_ptr<DirectAbstractDeclarator> m_DirectAbstractDeclarator;
};

}  // namespace ast
