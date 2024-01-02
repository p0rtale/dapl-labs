#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator/DirectAbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Expression/ConstantExpression.hpp>


namespace ast {

class ArrayDirectAbstractDeclarator: public DirectAbstractDeclarator {
public:
    ArrayDirectAbstractDeclarator(std::shared_ptr<ConstantExpression> constantExpression = nullptr)
        : m_ArraySizeConstexpr(constantExpression) {}

    ArrayDirectAbstractDeclarator(std::shared_ptr<DirectAbstractDeclarator> directAbstractDeclarator,
                                  std::shared_ptr<ConstantExpression> constantExpression = nullptr)
        : m_DirectAbstractDeclarator(directAbstractDeclarator),
          m_ArraySizeConstexpr(constantExpression) {};

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<DirectAbstractDeclarator> m_DirectAbstractDeclarator;
    std::shared_ptr<ConstantExpression> m_ArraySizeConstexpr;
};

}  // namespace ast
