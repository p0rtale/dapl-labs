#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class KeywordSpecifierList: public ASTNode {
public:
    KeywordSpecifierList();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
