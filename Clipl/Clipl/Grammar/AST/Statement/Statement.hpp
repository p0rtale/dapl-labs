#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class Statement: public ASTNode {
public:
    virtual ~Statement() = default;

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }
};

}  // namespace ast
