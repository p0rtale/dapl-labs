#pragma once

#include <string>
#include <vector>
#include <memory>

#include <Clipl/Grammar/AST/Program/KeywordSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/StructDeclaration.hpp>


namespace ast {

enum class StructOrUnionType {
    kStruct,
    kUnion,
};

class StructOrUnionSpecifier: public KeywordSpecifier {
public:
    StructOrUnionSpecifier(StructOrUnionType type, std::string identifier,
                           std::vector<std::shared_ptr<StructDeclaration>> structDeclarationList = {})
        : m_Type(type),
          m_Identifier(std::move(identifier)),
          m_StructDeclarationList(structDeclarationList) {}

    // void accept(Visitor *visitor) override;

private:
    StructOrUnionType m_Type;

    std::string m_Identifier;
    std::vector<std::shared_ptr<StructDeclaration>> m_StructDeclarationList;
};

}  // namespace ast
