#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Expression/UnaryExpression.hpp>
#include <Clipl/Grammar/AST/Program/TypeName.hpp>


namespace ast {

class SizeofTypenameExpression: public UnaryExpression {
public:
    SizeofTypenameExpression(std::shared_ptr<TypeName> typeName)
        : m_TypeName(typeName) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<TypeName> m_TypeName;
};

}  // namespace ast
