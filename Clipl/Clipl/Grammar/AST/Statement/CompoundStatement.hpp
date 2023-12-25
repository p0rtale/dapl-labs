#pragma once

#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class CompoundStatement: public Statement {
public:
    CompoundStatement();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
