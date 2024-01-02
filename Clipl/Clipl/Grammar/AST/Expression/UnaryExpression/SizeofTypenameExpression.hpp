#pragma once

#include <Clipl/Grammar/AST/Expression/UnaryExpression/UnaryExpression.hpp>
#include <Clipl/Grammar/AST/Program/TypeName.hpp>


namespace ast {

class SizeofTypenameExpression: public UnaryExpression {
public:
    SizeofTypenameExpression(RefT<TypeName> typeName)
        : m_TypeName(typeName) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<TypeName> GetTypeName() const {
        return m_TypeName;
    }

private:
    RefT<TypeName> m_TypeName;
};

}  // namespace ast
