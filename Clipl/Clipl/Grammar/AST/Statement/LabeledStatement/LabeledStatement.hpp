#pragma once

#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class LabeledStatement: public Statement {
public:
    virtual ~LabeledStatement() = default;

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }
};

}  // namespace ast
