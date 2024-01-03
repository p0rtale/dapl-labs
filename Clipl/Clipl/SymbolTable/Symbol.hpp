#pragma once

#include <functional>
#include <string>


namespace ast {

class Symbol {
public:
    Symbol(const std::string& name): m_Name(name) {}
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

}  // namespace ast


template<>
struct std::hash<ast::Symbol> {
    std::size_t operator()(const ast::Symbol& symbol) const noexcept {
        return std::hash<std::string>()(symbol.GetName());
    }
};
