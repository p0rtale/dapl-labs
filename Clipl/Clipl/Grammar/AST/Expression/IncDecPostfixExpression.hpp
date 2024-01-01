#pragma once

#include <string>
#include <memory>

#include <Clipl/Grammar/AST/Expression/PostfixExpression.hpp>


namespace ast {

class IncDecPostfixExpression: public PostfixExpression {
public:
    enum class Type {
        kPlus,
        kMinus,
    };

public:
    IncDecPostfixExpression(std::shared_ptr<PostfixExpression> postfixExpression,
                            Type type)
        : m_Type(type),
          m_PostfixExpression(postfixExpression) {}

    // void accept(Visitor *visitor) override;

private:
    Type m_Type;

    std::shared_ptr<PostfixExpression> m_PostfixExpression;
};

}  // namespace ast
