#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class Initializer: public ASTNode {
public:
    virtual ~Initializer() = default;

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }
};

}  // namespace ast
