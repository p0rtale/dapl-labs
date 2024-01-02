#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Program/Declarator/BaseDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/Pointer.hpp>
#include <Clipl/Grammar/AST/Program/DirectDeclarator/DirectDeclarator.hpp>

namespace ast {

class Declarator: public BaseDeclarator {
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