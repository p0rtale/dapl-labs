#pragma once


namespace clipl {

template<typename T>
using RefT = std::shared_ptr<T>;

template<typename T>
using WRefT = std::weak_ptr<T>;

template<typename T, typename... Args>
constexpr RefT<T> CreateRef(Args&&... args) {
    return std::make_shared<T>(std::forward<Args>(args)...);
}

}  // namespace clipl
