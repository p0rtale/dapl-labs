#pragma once

#include <Clipl/Grammar/AST/Program/DirectDeclarator/DirectDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/ParameterTypeList.hpp>


namespace ast {

class ParameterDirectDeclarator: public DirectDeclarator {
public:
    ParameterDirectDeclarator(RefT<DirectDeclarator> directDeclarator,
                              RefT<ParameterTypeList> parameterTypeList = nullptr)
        : m_DirectDeclarator(directDeclarator),
          m_ParameterTypeList(parameterTypeList) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<DirectDeclarator> GetDirectDeclarator() const {
        return m_DirectDeclarator;
    }

    RefT<ParameterTypeList> GetParameterTypeList() const {
        return m_ParameterTypeList;
    }

private:
    RefT<DirectDeclarator> m_DirectDeclarator;
    RefT<ParameterTypeList> m_ParameterTypeList;
};

}  // namespace ast
