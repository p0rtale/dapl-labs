#pragma once

#include <vector>

#include <Clipl/Clipl/Type/BasicType.hpp>


namespace type {

class FunctionType: public Type {
public:
    FunctionType() = default;

    std::vector<RefT<Type>> GetParameters() const {
        return m_Parameters;
    }

    RefT<Type> GetReturnType() const {
        return m_ReturnType;
    }

private:
    std::vector<RefT<Type>> m_Parameters;
    RefT<Type> m_ReturnType;
};

}  // namespace type
