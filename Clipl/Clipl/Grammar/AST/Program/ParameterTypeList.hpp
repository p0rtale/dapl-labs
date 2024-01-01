#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/ParameterDeclaration.hpp>


namespace ast {

class ParameterTypeList: public ASTNode {
public:
    ParameterTypeList(std::vector<std::shared_ptr<ParameterDeclaration>> parameters,
                      bool haveEllipsis = false)
        : m_Parameters(std::move(parameters)),
          m_HaveEllipsis(haveEllipsis) {}

    // void accept(Visitor *visitor) override;

private:
    std::vector<std::shared_ptr<ParameterDeclaration>> m_Parameters;
    bool m_HaveEllipsis = false;
};

}  // namespace ast
