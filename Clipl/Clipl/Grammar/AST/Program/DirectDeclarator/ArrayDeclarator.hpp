#pragma once

#include <Clipl/Grammar/AST/Program/DirectDeclarator/DirectDeclarator.hpp>
#include <Clipl/Grammar/AST/Expression/ConstantExpression.hpp>


namespace ast {

class ArrayDirectDeclarator: public DirectDeclarator {
public:
    ArrayDirectDeclarator(RefT<DirectDeclarator> directDeclarator,
                          RefT<ConstantExpression> constantExpression = nullptr)
        : m_DirectDeclarator(directDeclarator),
          m_ArraySizeConstexpr(constantExpression) {};

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<DirectDeclarator> GetDirectDeclarator() const {
        return m_DirectDeclarator;
    }

    RefT<ConstantExpression> GetArraySizeConstexpr() const {
        return m_ArraySizeConstexpr;
    }

private:
    RefT<DirectDeclarator> m_DirectDeclarator;
    RefT<ConstantExpression> m_ArraySizeConstexpr;
};

}  // namespace ast
