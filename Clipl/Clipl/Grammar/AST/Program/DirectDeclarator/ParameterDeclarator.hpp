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

    // void accept(Visitor *visitor) override;

private:
    RefT<DirectDeclarator> m_DirectDeclarator;
    RefT<ParameterTypeList> m_ParameterTypeList;
};

}  // namespace ast
