#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class Specifier: public ASTNode {
public:
    virtual ~Specifier() = default;

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
