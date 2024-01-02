#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class AssignmentOperator: public ASTNode {
public:
    enum class Type {
        kAssign,
        kMulAssign,
        kDivAssign,
        kModAssign,
        kPlusAssign,
        kMinusAssign,
        kShiftLeftAssign,
        kShiftRightAssign,
        kLogicalAndAssign,
        kLogicalOrAssign,
        kXorAssign,
    };

public:
    AssignmentOperator(Type operatorType)
        : m_Type(operatorType) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetTypeStr() const {
        switch (m_Type) {
            case Type::kAssign:           return "=";
            case Type::kMulAssign:        return "*=";
            case Type::kDivAssign:        return "/=";
            case Type::kModAssign:        return "%=";
            case Type::kPlusAssign:       return "+=";
            case Type::kShiftLeftAssign:  return "<<=";
            case Type::kShiftRightAssign: return ">>=";
            case Type::kLogicalAndAssign: return "&=";
            case Type::kLogicalOrAssign:  return "|=";
            case Type::kXorAssign:        return "^=";
            default: {
                CLIPL_ERROR("Invalid type in AssignmentOperator");
                return "";
            }
        }
    }

private:
    Type m_Type;
};

}  // namespace ast
