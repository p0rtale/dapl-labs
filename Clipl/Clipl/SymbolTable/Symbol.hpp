#pragma once

#include <functional>
#include <string>


namespace clipl {

class Symbol {
public:
    Symbol() = default;
    Symbol(std::string name): m_Name(std::move(name)) {}
    ~Symbol() = default;

    Symbol(const Symbol& other) = default;

    bool operator==(const Symbol& other) const {
        return m_Name == other.m_Name;
    }

    bool operator!=(const Symbol& other) const {
        return m_Name != other.m_Name;
    }

    std::string GetName() const {
        return m_Name;
    }

private:
    std::string m_Name;
};

}  // namespace clipl


template<>
struct std::hash<clipl::Symbol> {
    std::size_t operator()(const clipl::Symbol& symbol) const noexcept {
        return std::hash<std::string>()(symbol.GetName());
    }
};
