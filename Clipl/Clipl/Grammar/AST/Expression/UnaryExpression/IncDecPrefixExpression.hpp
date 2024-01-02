#pragma once

#include <Clipl/Grammar/AST/Expression/UnaryExpression/UnaryExpression.hpp>


namespace ast {

class IncDecPrefixExpression: public UnaryExpression {
public:
    enum class Type {
        kPlus,
        kMinus,
    };

public:
    IncDecPrefixExpression(RefT<UnaryExpression> unaryExpression,
                           Type type)
        : m_Type(type),
          m_UnaryExpression(unaryExpression) {}

    // void accept(Visitor *visitor) override;

private:
    Type m_Type;

    RefT<UnaryExpression> m_UnaryExpression;
};

}  // namespace ast
