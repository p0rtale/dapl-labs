#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class CastExpression: public ASTNode {
public:
    virtual ~CastExpression() = default;

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
