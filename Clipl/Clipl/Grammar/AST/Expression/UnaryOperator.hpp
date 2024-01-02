#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class UnaryOperator: public ASTNode {
public:
    enum class Type {
        kAddress,
        kMult,
        kPlus,
        kMinus,
        kLogicalNot,
        kNot,
    };

public:
    UnaryOperator(Type operatorType)
        : m_Type(operatorType) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetTypeStr() const {
        switch (m_Type) {
            case Type::kAddress :   return "&";
            case Type::kMult:       return "*";
            case Type::kPlus:       return "+";
            case Type::kMinus:      return "-";
            case Type::kLogicalNot: return "~";
            case Type::kNot:        return "!";
            default: {
                CLIPL_ERROR("Invalid type in UnaryOperator");
                return "";
            }
        }
    }

private:
    Type m_Type;
};

}  // namespace ast
