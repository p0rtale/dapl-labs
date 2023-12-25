#pragma once

namespace ast {

class ASTNode {
public:
    // virtual void accept(Visitor* visitor) = 0;
    virtual ~ASTNode() = default;
};

}  // namespace ast
