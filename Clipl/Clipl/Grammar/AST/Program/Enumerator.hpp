#pragma once

#include <string>
#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/ConstantExpression.hpp>


namespace ast {

class Enumerator: public ASTNode {
public:
    Enumerator(std::string identifier,
               std::shared_ptr<ConstantExpression> constantExpression = nullptr)
        : m_Identifier(std::move(identifier)),
          m_Constexpr(constantExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::string m_Identifier;
    std::shared_ptr<ConstantExpression> m_Constexpr;
};

}  // namespace ast
