#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class EqualityExpression: public ASTNode {
public:
    EqualityExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
