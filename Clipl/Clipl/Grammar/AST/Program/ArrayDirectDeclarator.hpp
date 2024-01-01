#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Program/DirectDeclarator.hpp>
#include <Clipl/Grammar/AST/Expression/ConstantExpression.hpp>


namespace ast {

class ArrayDirectDeclarator: public DirectDeclarator {
public:
    ArrayDirectDeclarator(std::shared_ptr<DirectDeclarator> directDeclarator,
                          std::shared_ptr<ConstantExpression> constantExpression = nullptr)
        : m_DirectDeclarator(directDeclarator),
          m_ArraySizeConstexpr(constantExpression) {};

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<DirectDeclarator> m_DirectDeclarator;
    std::shared_ptr<ConstantExpression> m_ArraySizeConstexpr;
};

}  // namespace ast
