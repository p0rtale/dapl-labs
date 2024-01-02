#pragma once

#include <Clipl/Grammar/AST/Program/Declarator/Declarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectDeclarator/DirectDeclarator.hpp>


namespace ast {

class NestedDirectDeclarator: public DirectDeclarator {
public:
    NestedDirectDeclarator(RefT<Declarator> declarator)
        : m_Declarator(declarator) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<Declarator> GetDeclarator() const {
        return  m_Declarator;
    }

private:
    RefT<Declarator> m_Declarator;
};

}  // namespace ast
