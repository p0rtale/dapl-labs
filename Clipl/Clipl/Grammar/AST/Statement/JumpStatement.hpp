#pragma once

#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class JumpStatement: public Statement {
public:
    JumpStatement();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
