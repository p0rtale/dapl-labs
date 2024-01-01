#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class AssignmentExpression: public ASTNode {
public:
    virtual ~AssignmentExpression() = default;

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
