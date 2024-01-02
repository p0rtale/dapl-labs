#pragma once

#include <Clipl/Grammar/AST/Program/Declarator/Declarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectDeclarator/DirectDeclarator.hpp>


namespace ast {

class NestedDirectDeclarator: public DirectDeclarator {
public:
    NestedDirectDeclarator(RefT<Declarator> declarator)
        : m_Declarator(declarator) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<Declarator> m_Declarator;
};

}  // namespace ast
