#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Expression/CastExpression/CastExpression.hpp>
#include <Clipl/Grammar/AST/Program/TypeName.hpp>


namespace ast {

class CastTypenameExpression: public CastExpression {
public:
    CastTypenameExpression(std::shared_ptr<TypeName> typeName,
                           std::shared_ptr<CastExpression> castExpression)
        : m_TypeName(typeName),
          m_CastExpressionTail(castExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<TypeName> m_TypeName;
    std::shared_ptr<CastExpression> m_CastExpressionTail;
};

}  // namespace ast
