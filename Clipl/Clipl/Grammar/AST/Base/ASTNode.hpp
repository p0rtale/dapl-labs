#pragma once

#include <memory>


namespace ast {

template<typename T>
using RefT = std::shared_ptr<T>;

template<typename T, typename... Args>
constexpr RefT<T> CreateRef(Args&&... args) {
    return std::make_shared<T>(std::forward<Args>(args)...);
}

class ASTNode {
public:
    // virtual void accept(Visitor* visitor) = 0;
    virtual ~ASTNode() = default;
};

}  // namespace ast
