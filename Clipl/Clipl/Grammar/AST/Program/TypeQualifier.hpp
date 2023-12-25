#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class TypeQualifier: public ASTNode {
public:
    TypeQualifier(const std::string& type)
        : m_Type(type) {};

    // void accept(Visitor *visitor) override;

private:
    std::string m_Type;
};

}  // namespace ast
