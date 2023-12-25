#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class ShiftExpression: public ASTNode {
public:
    ShiftExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
