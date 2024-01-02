#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class ExternalDeclaration: public ASTNode {
public:
    virtual ~ExternalDeclaration() = default;

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }
};

}  // namespace ast
