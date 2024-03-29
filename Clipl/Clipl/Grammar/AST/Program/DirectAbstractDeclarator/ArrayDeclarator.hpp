#pragma once

#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator/DirectAbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Expression/ConstantExpression.hpp>


namespace ast {

class ArrayDirectAbstractDeclarator: public DirectAbstractDeclarator {
public:
    ArrayDirectAbstractDeclarator(RefT<ConstantExpression> constantExpression = nullptr)
        : m_ArraySizeConstexpr(constantExpression) {}

    ArrayDirectAbstractDeclarator(RefT<DirectAbstractDeclarator> directAbstractDeclarator,
                                  RefT<ConstantExpression> constantExpression = nullptr)
        : m_DirectAbstractDeclarator(directAbstractDeclarator),
          m_ArraySizeConstexpr(constantExpression) {};

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<DirectAbstractDeclarator> GetDirectAbstractDeclarator() const {
        return m_DirectAbstractDeclarator;
    }

    RefT<ConstantExpression> GetArraySizeConstexpr() {
        return m_ArraySizeConstexpr;
    }

private:
    RefT<DirectAbstractDeclarator> m_DirectAbstractDeclarator;
    RefT<ConstantExpression> m_ArraySizeConstexpr;
};

}  // namespace ast
