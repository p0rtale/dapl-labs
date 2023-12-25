#pragma once

#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class SelectionStatement: public Statement {
public:
    SelectionStatement();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
