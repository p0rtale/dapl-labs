#pragma once

#include <memory>

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
    RelationalExpression(std::shared_ptr<ShiftExpression> shiftExpression)
        : m_ShiftExpression(shiftExpression) {}

    RelationalExpression(std::shared_ptr<RelationalExpression> relationalExpression,
                       std::shared_ptr<ShiftExpression> shiftExpression,
                       Type type)
        : m_Type(type),
          m_RelationalExpression(relationalExpression),
          m_ShiftExpression(shiftExpression) {}

    // void accept(Visitor *visitor) override;

private:
    Type m_Type = Type::kBlank;

    std::shared_ptr<RelationalExpression> m_RelationalExpression;
    std::shared_ptr<ShiftExpression> m_ShiftExpression;
};

}  // namespace ast
