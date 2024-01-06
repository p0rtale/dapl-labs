#pragma once

#include <memory>
#include <string>


namespace clipl::type {

class Type {
public:
    enum class StorageSpecifier {
        kLocal,
        kExtern,
        kStatic,        
    };

public:
    Type(bool isVoid = false): m_IsVoid(isVoid) {}

    virtual ~Type() = default;

    virtual bool IsBasicType() const = 0;
    virtual bool IsPointerType() const = 0;
    virtual bool IsArrayType() const = 0;
    virtual bool IsFunctionType() const = 0;

    void SetIdentifier(std::string identifier) {
        m_Identifier = identifier;
    }

    std::string GetIdentifier() const {
        return m_Identifier;
    }

    void SetStorageSpecifier(StorageSpecifier specifier) {
        m_Storage = specifier;
    }

    StorageSpecifier GetStorageSpecifier() const {
        return m_Storage;
    }

    void SetDefine() {
        m_IsDefined = true;
    }

    bool IsDefined() const {
        return m_IsDefined;
    }

    bool IsVoid() const {
        return m_IsVoid;
    }

protected:
    StorageSpecifier m_Storage = StorageSpecifier::kLocal;

    std::string m_Identifier;

    bool m_IsDefined = false;

    bool m_IsVoid = false;
};

}  // namespace clipl::type
