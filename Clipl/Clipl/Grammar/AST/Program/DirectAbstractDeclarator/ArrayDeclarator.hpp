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

    // void accept(Visitor *visitor) override;

private:
    RefT<DirectAbstractDeclarator> m_DirectAbstractDeclarator;
    RefT<ConstantExpression> m_ArraySizeConstexpr;
};

}  // namespace ast
