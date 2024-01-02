#pragma once

#include <string>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/ConstantExpression.hpp>


namespace ast {

class Enumerator: public ASTNode {
public:
    Enumerator(std::string identifier,
               RefT<ConstantExpression> constantExpression = nullptr)
        : m_Identifier(std::move(identifier)),
          m_Constexpr(constantExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::string m_Identifier;
    RefT<ConstantExpression> m_Constexpr;
};

}  // namespace ast
