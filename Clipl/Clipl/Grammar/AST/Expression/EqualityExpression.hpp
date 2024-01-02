#pragma once

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
    EqualityExpression(RefT<RelationalExpression> relationalExpression)
        : m_RelationalExpression(relationalExpression) {}

    EqualityExpression(RefT<EqualityExpression> equalityExpression,
                       RefT<RelationalExpression> relationalExpression,
                       Type type)
        : m_Type(type),
          m_EqualityExpression(equalityExpression),
          m_RelationalExpression(relationalExpression) {}

    // void accept(Visitor *visitor) override;

private:
    Type m_Type = Type::kBlank;

    RefT<EqualityExpression> m_EqualityExpression;
    RefT<RelationalExpression> m_RelationalExpression;
};

}  // namespace ast
