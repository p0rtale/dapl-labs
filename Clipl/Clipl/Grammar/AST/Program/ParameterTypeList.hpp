#pragma once

#include <vector>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/ParameterDeclaration.hpp>


namespace ast {

class ParameterTypeList: public ASTNode {
public:
    ParameterTypeList(std::vector<RefT<ParameterDeclaration>> parameters,
                      bool haveEllipsis = false)
        : m_Parameters(std::move(parameters)),
          m_HaveEllipsis(haveEllipsis) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::vector<RefT<ParameterDeclaration>> GetParameters() const {
        return m_Parameters;
    }

    bool HaveEllipsis() const {
        return m_HaveEllipsis;
    }

private:
    std::vector<RefT<ParameterDeclaration>> m_Parameters;
    bool m_HaveEllipsis = false;
};

}  // namespace ast
