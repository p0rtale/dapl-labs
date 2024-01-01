#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Program/Declarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectDeclarator.hpp>


namespace ast {

class NestedDirectDeclarator: public DirectDeclarator {
public:
    NestedDirectDeclarator(std::shared_ptr<Declarator> declarator)
        : m_Declarator(declarator) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<Declarator> m_Declarator;
};

}  // namespace ast
