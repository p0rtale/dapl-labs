#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class AndExpression: public ASTNode {
public:
    AndExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
