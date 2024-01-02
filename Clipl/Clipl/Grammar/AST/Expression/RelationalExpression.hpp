#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/ShiftExpression.hpp>


namespace ast {

class RelationalExpression: public ASTNode {
public:
    enum class Type {
        kBlank,
        kLess,
        kGreater,
        kLessEq,
        kGreaterEq,
    };

public:
    RelationalExpression(RefT<ShiftExpression> shiftExpression)
        : m_ShiftExpression(shiftExpression) {}

    RelationalExpression(RefT<RelationalExpression> relationalExpression,
                         RefT<ShiftExpression> shiftExpression,
                         Type type)
        : m_Type(type),
          m_RelationalExpression(relationalExpression),
          m_ShiftExpression(shiftExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetTypeStr() const {
        switch (m_Type) {
            case Type::kBlank:     return "";
            case Type::kLess:      return "<";
            case Type::kGreater:   return ">";
            case Type::kLessEq:    return "<=";
            case Type::kGreaterEq: return ">=";
            default: {
                CLIPL_ERROR("Invalid type in RelationalExpression");
                return "";
            }
        }
    }

    RefT<RelationalExpression> GetRelationalExpression() const {
        return m_RelationalExpression;
    }

    RefT<ShiftExpression> GetShiftExpression() const {
        return m_ShiftExpression;
    }

private:
    Type m_Type = Type::kBlank;

    RefT<RelationalExpression> m_RelationalExpression;
    RefT<ShiftExpression> m_ShiftExpression;
};

}  // namespace ast
