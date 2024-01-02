#pragma once

#include <Clipl/Grammar/AST/Expression/CastExpression/CastExpression.hpp>
#include <Clipl/Grammar/AST/Program/TypeName.hpp>


namespace ast {

class CastTypenameExpression: public CastExpression {
public:
    CastTypenameExpression(RefT<TypeName> typeName,
                           RefT<CastExpression> castExpression)
        : m_TypeName(typeName),
          m_CastExpressionTail(castExpression) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<TypeName> m_TypeName;
    RefT<CastExpression> m_CastExpressionTail;
};

}  // namespace ast
