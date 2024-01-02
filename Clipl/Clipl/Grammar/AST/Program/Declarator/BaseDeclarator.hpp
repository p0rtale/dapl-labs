#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class BaseDeclarator: public ASTNode {
public:
    virtual ~BaseDeclarator() = default;

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
