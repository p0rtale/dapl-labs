#pragma once

#include <Clipl/Grammar/AST/Statement/JumpStatement/JumpStatement.hpp>


namespace ast {

class LoopJumpStatement: public JumpStatement {
public:
    enum class Type {
        kContinue,
        kBreak,
    };

public:
    LoopJumpStatement(Type type): m_Type(type) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetTypeStr() const {
        switch (m_Type) {
            case Type::kContinue: return "continue";
            case Type::kBreak:    return "break";
            default: {
                CLIPL_ERROR("Invalid type in LoopJumpStatement");
                return "";
            }
        }
    }

private:
    Type m_Type;
};

}  // namespace ast
