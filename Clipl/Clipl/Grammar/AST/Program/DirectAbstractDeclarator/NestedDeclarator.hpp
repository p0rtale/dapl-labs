#pragma once

#include <Clipl/Grammar/AST/Program/Declarator/AbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator/DirectAbstractDeclarator.hpp>


namespace ast {

class NestedDirectAbstractDeclarator: public DirectAbstractDeclarator {
public:
    NestedDirectAbstractDeclarator(RefT<AbstractDeclarator> abstractDeclarator)
        : m_AbstractDeclarator(abstractDeclarator) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<AbstractDeclarator> m_AbstractDeclarator;
};

}  // namespace ast
