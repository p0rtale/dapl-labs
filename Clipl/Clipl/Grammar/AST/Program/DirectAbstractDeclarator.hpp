#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class DirectAbstractDeclarator: public ASTNode {
public:
    virtual ~DirectAbstractDeclarator() = default;

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
