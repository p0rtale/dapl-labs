#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class KeywordSpecifier: public ASTNode {
public:
    virtual ~KeywordSpecifier() = default;

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
