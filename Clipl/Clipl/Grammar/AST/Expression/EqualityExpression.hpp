#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/RelationalExpression.hpp>


namespace ast {

class EqualityExpression: public ASTNode {
public:
    enum class Type {
        kBlank,
        kEqual,
        kNotEqual,
    };

public:
    EqualityExpression(std::shared_ptr<RelationalExpression> relationalExpression)
        : m_RelationalExpression(relationalExpression) {}

    EqualityExpression(std::shared_ptr<EqualityExpression> equalityExpression,
                       std::shared_ptr<RelationalExpression> relationalExpression,
                       Type type)
        : m_Type(type),
          m_EqualityExpression(equalityExpression),
          m_RelationalExpression(relationalExpression) {}

    // void accept(Visitor *visitor) override;

private:
    Type m_Type = Type::kBlank;

    std::shared_ptr<EqualityExpression> m_EqualityExpression;
    std::shared_ptr<RelationalExpression> m_RelationalExpression;
};

}  // namespace ast
