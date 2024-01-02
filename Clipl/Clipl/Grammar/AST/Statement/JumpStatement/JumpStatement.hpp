#pragma once

#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class JumpStatement: public Statement {
public:
    virtual ~JumpStatement() = default;

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }
};

}  // namespace ast
