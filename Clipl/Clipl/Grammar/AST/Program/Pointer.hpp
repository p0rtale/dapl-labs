#pragma once

#include <vector>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/Specifier/TypeQualifier.hpp>

namespace ast {

class Pointer: public ASTNode {
public:
    Pointer() = default;

    Pointer(std::vector<RefT<TypeQualifier>> typeQualifiers,
            RefT<Pointer> pointer = nullptr)
        : m_TypeQualifiers(std::move(typeQualifiers)),
          m_Tail(pointer) {}

    // void accept(Visitor *visitor) override;

private:
    std::vector<RefT<TypeQualifier>> m_TypeQualifiers;
    RefT<Pointer> m_Tail = nullptr;
};

}  // namespace ast
