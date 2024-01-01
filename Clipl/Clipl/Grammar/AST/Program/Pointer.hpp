#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/TypeQualifier.hpp>

namespace ast {

class Pointer: public ASTNode {
public:
    Pointer() = default;

    Pointer(std::vector<std::shared_ptr<TypeQualifier>> typeQualifiers,
            std::shared_ptr<Pointer> pointer = nullptr)
        : m_TypeQualifiers(std::move(typeQualifiers)),
          m_Tail(pointer) {}

    // void accept(Visitor *visitor) override;

private:
    std::vector<std::shared_ptr<TypeQualifier>> m_TypeQualifiers;
    std::shared_ptr<Pointer> m_Tail = nullptr;
};

}  // namespace ast
