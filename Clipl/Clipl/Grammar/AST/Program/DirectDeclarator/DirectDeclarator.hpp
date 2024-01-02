#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class DirectDeclarator: public ASTNode {
public:
    virtual ~DirectDeclarator() = default;

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }
};

}  // namespace ast
