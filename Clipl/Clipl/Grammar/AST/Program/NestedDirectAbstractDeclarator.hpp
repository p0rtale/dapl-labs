#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Program/AbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator.hpp>


namespace ast {

class NestedDirectAbstractDeclarator: public DirectAbstractDeclarator {
public:
    NestedDirectAbstractDeclarator(std::shared_ptr<AbstractDeclarator> abstractDeclarator)
        : m_AbstractDeclarator(abstractDeclarator) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<AbstractDeclarator> m_AbstractDeclarator;
};

}  // namespace ast
