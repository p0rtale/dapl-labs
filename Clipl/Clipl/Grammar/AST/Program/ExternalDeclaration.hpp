#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class ExternalDeclaration: public ASTNode {
public:
    virtual ~ExternalDeclaration() = default;

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
