#pragma once

#include <Clipl/Grammar/AST/Expression/CastExpression.hpp>


namespace ast {

class UnaryExpression: public CastExpression {
public:
    virtual ~UnaryExpression() = default;

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
