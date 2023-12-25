#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class RelationalExpression: public ASTNode {
public:
    RelationalExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
