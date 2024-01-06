#pragma once

#include <string>
#include <vector>
#include <fstream>

#include <Clipl/SymbolTable/SymbolTree.hpp>
#include <Clipl/Type/Type.hpp>
#include <Clipl/Type/ComplexType.hpp>


namespace clipl {

class SymbolTreeDotConverter {
public:
    SymbolTreeDotConverter(const SymbolTree& tree, const std::string& filename)
        : m_OutputStream(filename), m_Tree(tree) {}

    void Convert() {
        printWithSpaces(std::format("digraph \"{}\" {{\n", m_GraphName));

        m_CurrentNodeIdent = "ScopeTree";
        spaceLevelUp();
        printWithSpaces(std::format("{} [\n", m_CurrentNodeIdent));

        spaceLevelUp();
        printSpaces();
        m_OutputStream << "style=filled,\n";
        printSpaces();
        m_OutputStream << "fillcolor=\"#181818\",\n";
        printSpaces();
        m_OutputStream << "label=\"ScopeTree\",\n";
        printSpaces();
        m_OutputStream << "fontsize=\"15pt\",\n";
        printSpaces();
        m_OutputStream << "fontcolor=\"#22bd74\",\n";
        spaceLevelDown();

        printWithSpaces("];\n");

        convertScope(m_Tree.GetGlobalScope());

        spaceLevelDown();

        printWithSpaces("}\n");      
    }

private:
    void spaceLevelUp() {
        ++m_SpaceLevel;
    }

    void spaceLevelDown() {
        if (m_SpaceLevel > 0) { 
            --m_SpaceLevel;
        }
    }

    void printWithSpaces(const std::string& string) {
        printSpaces();
        m_OutputStream << string;
    }

    void printSpaces() {
        m_OutputStream << std::string(m_SpaceLevel, '\t');
    }
    
    void printNodeAttributes(const std::string& label, const auto& symbols) {
        printSpaces();
        m_OutputStream << "shape=record,\n";
        printSpaces();
        m_OutputStream << "style=filled,\n";
        printSpaces();
        m_OutputStream << "fillcolor=\"#181818\",\n";
        printSpaces();
        m_OutputStream << std::format("label=\"{{{}|", label);
        for (auto [symbol, type] : symbols) {
            if (!type->IsBasicType() && !type->IsFunctionType()) {
                using clipl::type::ComplexType;
                auto complexType = std::dynamic_pointer_cast<ComplexType>(type);
                auto internalType = complexType->GetInternalType();
                switch (internalType) {
                case ComplexType::InternalType::kStruct:
                    m_OutputStream << "TAG struct ";
                    break;
                case ComplexType::InternalType::kUnion:
                    m_OutputStream << "TAG union ";
                    break;
                case ComplexType::InternalType::kEnum:
                    m_OutputStream << "TAG enum ";
                    break;
                default:
                    break;
                }
            }
            m_OutputStream << std::format("\\\"{}\\\" [type = {}]\\l",
                                          symbol.GetName(), typeid(*type).name());
        }
        m_OutputStream << "}\",\n";
        printSpaces();
        m_OutputStream << "fontsize=\"15pt\",\n";
        printSpaces();
        m_OutputStream << "fontcolor=\"#22bd74\",\n";
    }

    void printNode(const std::string& ident, const auto& symbols) {
        m_CurrentNodeIdent = getId(ident);

        printWithSpaces(std::format("{} [\n", m_CurrentNodeIdent));

        spaceLevelUp();
        printNodeAttributes(ident, symbols);
        spaceLevelDown();

        printWithSpaces("];\n");

        printWithSpaces(std::format("{} -> {};\n", m_PreviousNodeIdent, m_CurrentNodeIdent));
    }

    void convertScope(RefT<Scope> scope) {
        m_PreviousNodeIdent = m_CurrentNodeIdent;
        std::string prevNodeIdent = m_PreviousNodeIdent;
        
        auto scopeLabel = scope->GetLabel();
        printNode(scopeLabel.GetName(), scope->GetSymbolTypes());

        convertScopes(scope->GetChildrenScopes());   

        m_CurrentNodeIdent = prevNodeIdent;
    }

    void convertScopes(const std::vector<RefT<Scope>>& scopes) {
        m_PreviousNodeIdent = m_CurrentNodeIdent;
        std::string prevNodeIdent = m_PreviousNodeIdent;
        for (auto scope : scopes) {
            convertScope(scope);
            m_PreviousNodeIdent = prevNodeIdent;
        }
        m_CurrentNodeIdent = prevNodeIdent;
    }

    std::string getId(const std::string& ident) {
        return std::format("{}_{}", ident, m_IdCounter++);
    }

private:
    std::ofstream m_OutputStream;
    size_t m_SpaceLevel = 0;

    const std::string m_GraphName = "symbol_table";

    std::string m_CurrentNodeIdent;
    std::string m_PreviousNodeIdent;

    size_t m_IdCounter = 0;

    const SymbolTree& m_Tree;
};

}  // namespace clipl
