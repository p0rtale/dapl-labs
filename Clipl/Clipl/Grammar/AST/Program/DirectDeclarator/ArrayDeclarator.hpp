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

    // void accept(Visitor *visitor) override;

private:
    RefT<DirectDeclarator> m_DirectDeclarator;
    RefT<ConstantExpression> m_ArraySizeConstexpr;
};

}  // namespace ast
