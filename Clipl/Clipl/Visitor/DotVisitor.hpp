#pragma once

#include <fstream>
#include <format>

#include <Clipl/Grammar/AST/AST.hpp>


namespace ast {

class DotVisitor: public Visitor {
public:
    DotVisitor(const std::string& filename): m_OutputStream(filename) {}

public:
    /*
    =================================================================
                                Program
    =================================================================
    */

    // Declaration specifiers
    void Visit(DeclarationSpecifiers&) override {
        // Base class
    }

    void Visit(IdentDeclarationSpecifiers& identDeclarationSpecifiers) override {
        printNode("ident_declaration_specifiers", "IdentDeclSpecifiers");

        auto specifiers = identDeclarationSpecifiers.GetSpecifiers();
        acceptNodeList(specifiers, "Specifier"); 
        // for (size_t i = 0; i < specifiers.size(); ++i) {
        //     m_PreviousNodeIdent = m_CurrentNodeIdent;
        //     m_EdgeLabel = std::format("Specifier{}", i);
        //     specifiers[i]->Accept(*this);
        // }

        auto ident = identDeclarationSpecifiers.GetIdent();
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // ident->Accept(*this);
        acceptNode(ident, "Ident");
    }
    
    void Visit(KeywordDeclarationSpecifiers& keywordDeclarationSpecifiers) override {
        printNode("keyword_declaration_specifiers", "KeywordDeclarationSpecifiers");

        auto specifiers = keywordDeclarationSpecifiers.GetSpecifiers();
        acceptNodeList(specifiers, "Specifier");              

        auto keywords = keywordDeclarationSpecifiers.GetKeywords();
        acceptNodeList(keywords, "Keyword");              
    }

    // Declarator
    void Visit(AbstractDeclarator& abstractDeclarator) override {
        printNode("abstract_declarator", "AbstractDeclarator");

        auto pointer = abstractDeclarator.GetPointer();
        if (pointer) {
            acceptNode(pointer, "Pointer");
        }

        auto directAbstractDeclarator = abstractDeclarator.GetDirectAbstractDeclarator();
        if (directAbstractDeclarator) {
            acceptNode(directAbstractDeclarator, "DirectAbstractDeclarator");
        }        
    }

    void Visit(BaseDeclarator&) override {
        // Base class
    }

    void Visit(Declarator& declarator) override {
        printNode("declarator", "Declarator");

        auto pointer = declarator.GetPointer();
        if (pointer) {
            acceptNode(pointer, "Pointer");
        }

        auto directDeclarator = declarator.GetDirectDeclarator();
        acceptNode(directDeclarator, "DirectDeclarator");
    }

    // Direct abstract declarator
    void Visit(ArrayDirectAbstractDeclarator& arrayDeclarator) override {
        printNode("array_direct_abstract_declarator", "ArrayDirectAbstractDeclarator");

        auto directAbstractDeclarator = arrayDeclarator.GetDirectAbstractDeclarator();
        if (directAbstractDeclarator) {
            acceptNode(directAbstractDeclarator, "DirectAbstractDeclarator");
        }

        auto arraySizeConstexpr = arrayDeclarator.GetArraySizeConstexpr();
        if (arraySizeConstexpr) {
            acceptNode(arraySizeConstexpr, "ArraySizeConstexpr");
        }
    }

    void Visit(DirectAbstractDeclarator&) override {
        // Base class
    }

    void Visit(NestedDirectAbstractDeclarator& nestedDeclarator) override {
        printNode("nested_direct_abstract_declarator", "NestedDirectAbstractDeclarator");

        auto abstractDeclarator = nestedDeclarator.GetAbstractDeclarator();
        acceptNode(abstractDeclarator, "AbstractDeclarator");         
    }

    void Visit(ParameterDirectAbstractDeclarator& parameterDeclarator) override {
        printNode("parameter_direct_abstract_declarator", "ParameterDirectAbstractDeclarator");

        auto directAbstractDeclarator = parameterDeclarator.GetDirectAbstractDeclarator();
        if (directAbstractDeclarator) {
            acceptNode(directAbstractDeclarator, "DirectAbstractDeclarator");
        }

        auto parameterTypeList = parameterDeclarator.GetParameterTypeList();
        if (parameterTypeList) {
            acceptNode(parameterTypeList, "ParameterTypeList");
        }
    }

    // Direct declarator
    void Visit(ArrayDirectDeclarator& arrayDeclarator) override {
        printNode("array_direct_declarator", "ArrayDirectDeclarator");

        auto directDeclarator = arrayDeclarator.GetDirectDeclarator();
        acceptNode(directDeclarator, "DirectDeclarator");

        auto arraySizeConstexpr = arrayDeclarator.GetArraySizeConstexpr();
        if (arraySizeConstexpr) {
            acceptNode(arraySizeConstexpr, "ArraySizeConstexpr");
        }
    }

    void Visit(DirectDeclarator&) override {
        // Base class
    }

    void Visit(IdentDirectDeclarator& identDeclarator) override {
        std::string ident = identDeclarator.GetIdentifier();
        printNode("ident_direct_declarator",
                  std::format("IdentDirectDeclarator [\\\"{}\\\"]", ident));
    }

    void Visit(NestedDirectDeclarator& nestedDeclarator) override {
        printNode("nested_direct_declarator", "NestedDirectDeclarator");

        auto declarator = nestedDeclarator.GetDeclarator();
        acceptNode(declarator, "Declarator");
    }

    void Visit(ParameterDirectDeclarator& parameterDeclarator) override {
        printNode("parameter_direct_declarator", "ParameterDirectDeclarator");

        auto directDeclarator = parameterDeclarator.GetDirectDeclarator();
        acceptNode(directDeclarator, "DirectDeclarator");

        auto parameterTypeList = parameterDeclarator.GetParameterTypeList();
        if (parameterTypeList) {
            acceptNode(parameterTypeList, "ParameterTypeList");
        }
    }

    // External declaration
    void Visit(Declaration& declaration) override {
        printNode("declaration", "Declaration");

        auto declarationSpecifiers = declaration.GetDeclarationSpecifiers();
        acceptNode(declarationSpecifiers, "DeclarationSpecifiers");

        auto initDeclarators = declaration.GetInitDeclarators();
        acceptNodeList(initDeclarators, "InitDeclarator");

        auto assignmentExpression = declaration.GetAssignmentExpression();
        if (assignmentExpression) {
            acceptNode(assignmentExpression, "DeclarationSpecifiers");
        }
    }

    void Visit(ExternalDeclaration&) override {
        // Base class
    }

    void Visit(FunctionDefinition& functionDefinition) override {
        printNode("function_definition", "FuncDefinition");

        auto declarationSpecifiers = functionDefinition.GetDeclarationSpecifiers();
        acceptNode(declarationSpecifiers, "DeclarationSpecifiers");
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "DeclarationSpecifiers";
        // declarationSpecifiers->Accept(*this);

        auto declarator = functionDefinition.GetDeclarator();
        acceptNode(declarator, "Declarator");
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "Declarator";
        // declarator->Accept(*this);

        auto compoundStatement = functionDefinition.GetCompoundStatement();
        acceptNode(compoundStatement, "CompoundStatement");
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "CompoundStatement";
        // compoundStatement->Accept(*this);
    }

    // Initializer
    void Visit(ExpressionInitializer& expressionInitializer) override {
        printNode("expression_initializer", "ExpressionInitializer");

        auto assignmentExpression = expressionInitializer.GetAssignmentExpression();
        acceptNode(assignmentExpression, "AssignmentExpression");
    }

    void Visit(Initializer&) override {
        // Base class
    }

    void Visit(InitializerList& initializerList) override {
        printNode("initializer_list", "InitializerList");

        auto initializers = initializerList.GetInitializers();
        acceptNodeList(initializers, "Initializer");           
    }

    // Keyword specifier
    void Visit(BasicKeywordSpecifier& basicKeywordSpecifier) override {
        std::string typeStr = basicKeywordSpecifier.GetTypeStr();
        printNode("basic_keyword_specifier",
                  std::format("BasicKeywordSpecifier [{}]", typeStr));
    }

    void Visit(EnumSpecifier& enumSpecifier) override {
        std::string identifier = enumSpecifier.GetIdentifier();
        if (identifier != "") {
            printNode("enum_specifier",
                    std::format("EnumSpecifier [\\\"{}\\\"]", identifier));
        } else {
            printNode("enum_specifier", "EnumSpecifier [None]");            
        }

        auto enumeratorList = enumSpecifier.GetEnumeratorList();
        acceptNodeList(enumeratorList, "Enumerator");         
    }

    void Visit(KeywordSpecifier&) override {
        // Base class
    }

    void Visit(StructOrUnionSpecifier& structOrUnionSpecifier) override {
        std::string typeStr = structOrUnionSpecifier.GetTypeStr();
        std::string identifier = structOrUnionSpecifier.GetIdentifier();
        if (identifier != "") {
            printNode("struct_or_union_specifier",
                      std::format("StructOrUnionSpecifier [{},\\\"{}\\\"]", typeStr, identifier));
        } else {
            printNode("struct_or_union_specifier",
                      std::format("StructOrUnionSpecifier [{},None]", typeStr));
        }

        auto structDeclarationList = structOrUnionSpecifier.GetStructDeclarationList();
        acceptNodeList(structDeclarationList, "StructDeclaration");                
    }

    // Specifier
    void Visit(Specifier&) override {
        // Base class
    }

    void Visit(StorageClassSpecifier& storageClassSpecifier) override {
        auto typeStr = storageClassSpecifier.GetTypeStr();
        printNode("storage_class_specifier", std::format("StorageClassSpecifier [{}]", typeStr));
    }

    void Visit(TypeQualifier& typeQualifier) override {
        auto typeStr = typeQualifier.GetTypeStr();
        printNode("type_qualifier", std::format("TypeQualifier [{}]", typeStr));       
    }

    // Rest
    void Visit(Enumerator& enumerator) override {
        std::string identifier = enumerator.GetIdentifier();
        printNode("enumerator", std::format("Enumerator [\\\"{}\\\"]", identifier));

        auto constExpression = enumerator.GetConstantExpression();
        if (constExpression) {
            acceptNode(constExpression, "ConstExpr");
        }
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "ConstExpr";
        // constExpression->Accept(*this);          
    }

    void Visit(IdentSpecifier& identSpecifier) override {
        std::string identifier = identSpecifier.GetIdentifier();
        printNode("ident_specifier", std::format("identSpecifier [\\\"{}\\\"]", identifier));
    }

    void Visit(InitDeclarator& initDeclarator) override {
        printNode("init_declarator", "InitDeclarator");

        auto declarator = initDeclarator.GetDeclarator();
        acceptNode(declarator, "Declarator");
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "Declarator";
        // declarator->Accept(*this);  

        auto initializer = initDeclarator.GetInitializer();
        if (initializer) {
            acceptNode(initializer, "Initializer");
        }
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "Initializer";
        // initializer->Accept(*this);           
    }

    void Visit(ParameterDeclaration& parameterDeclaration) override {
        printNode("parameter_declaration", "ParameterDeclaration");

        auto declarationSpecifiers = parameterDeclaration.GetDeclarationSpecifiers();
        acceptNode(declarationSpecifiers, "DeclarationSpecifiers");
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "DeclarationSpecifiers";
        // declarationSpecifiers->Accept(*this);  

        auto baseDeclarator = parameterDeclaration.GetBaseDeclarator();
        if (baseDeclarator) {
            acceptNode(baseDeclarator, "BaseDeclarator");
        }
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "BaseDeclarator";
        // baseDeclarator->Accept(*this);          
    }

    void Visit(ParameterTypeList& parameterTypeList) override {
        std::string nodeLabel = "ParameterTypeList [ellipsis=false]";
        bool haveEllipsis = parameterTypeList.HaveEllipsis();
        if (haveEllipsis) {
            nodeLabel = "ParameterTypeList [ellipsis = true]";
        }
        printNode("parameter_type_list", nodeLabel);

        auto parameters = parameterTypeList.GetParameters();
        acceptNodeList(parameters, "Parameter");        
    }

    void Visit(Pointer& pointer) override {
        printNode("pointer", "Pointer");

        auto typeQualifiers = pointer.GetTypeQualifiers();
        acceptNodeList(typeQualifiers, "TypeQualifier");
        // for (size_t i = 0; i < typeQualifiers.size(); ++i) {
        //     m_PreviousNodeIdent = m_CurrentNodeIdent;
        //     m_EdgeLabel = std::format("TypeQualifier{}", i);
        //     typeQualifiers[i]->Accept(*this);
        // }

        auto pointerTail = pointer.GetPointerTail();
        if (pointerTail) {
            acceptNode(pointerTail, "PointerTail");
        }
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "PointerTail";
        // pointerTail->Accept(*this);      
    }

    void Visit(Program& program) override {
        printWithSpaces(std::format("digraph \"{}\" {{\n", m_GraphName));

        m_CurrentNodeIdent = std::string{"program"};

        spaceLevelUp();
        printWithSpaces(std::format("{} [\n", m_CurrentNodeIdent));

        spaceLevelUp();
        printNodeAttributes("Program");
        spaceLevelDown();

        printWithSpaces("];\n");

        auto externalDeclarations = program.GetExternalDeclarations();
        acceptNodeList(externalDeclarations, "ExternalDecl");
        // for (size_t i = 0; i < externalDeclarations.size(); ++i) {
        //     m_PreviousNodeIdent = m_CurrentNodeIdent;
        //     m_EdgeLabel = std::format("ExternalDecl{}", i);
        //     externalDeclarations[i]->Accept(*this);
        // }
        spaceLevelDown();

        printWithSpaces("}\n");
    }

    void Visit(SpecifierQualifierList& specifierQualifierList) override {
        printNode("specifier_qualifier_list", "SpecifierQualifierList");

        auto typeQualifiers = specifierQualifierList.GetTypeQualifiers();
        acceptNodeList(typeQualifiers, "TypeQualifier");
        // for (size_t i = 0; i < typeQualifiers.size(); ++i) {
        //     m_PreviousNodeIdent = m_CurrentNodeIdent;
        //     m_EdgeLabel = std::format("TypeQualifier{}", i);
        //     typeQualifiers[i]->Accept(*this);
        // }

        auto identSpecifiers = specifierQualifierList.GetIdentSpecifiers();
        acceptNodeList(identSpecifiers, "IdentSpecifier");
        // for (size_t i = 0; i < identSpecifiers.size(); ++i) {
        //     m_PreviousNodeIdent = m_CurrentNodeIdent;
        //     m_EdgeLabel = std::format("IdentSpecifier{}", i);
        //     identSpecifiers[i]->Accept(*this);
        // }

        auto keywordSpecifiers = specifierQualifierList.GetKeywordSpecifiers();
        acceptNodeList(keywordSpecifiers, "KeywordSpecifier");
        // for (size_t i = 0; i < keywordSpecifiers.size(); ++i) {
        //     m_PreviousNodeIdent = m_CurrentNodeIdent;
        //     m_EdgeLabel = std::format("KeywordSpecifier{}", i);
        //     keywordSpecifiers[i]->Accept(*this);
        // }
    }

    void Visit(StructDeclaration& structDeclaration) override {
        printNode("struct_declaration", "StructDeclaration");

        auto specifierQualifierList = structDeclaration.GetSpecifierQualifierList();
        acceptNode(specifierQualifierList, "SpecifierQualifierList");
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "SpecifierQualifierList";
        // specifierQualifierList->Accept(*this);

        auto structDeclaratorList = structDeclaration.GetStructDeclaratorList();
        acceptNodeList(structDeclaratorList, "StructDeclarator");
        // for (size_t i = 0; i < structDeclaratorList.size(); ++i) {
        //     m_PreviousNodeIdent = m_CurrentNodeIdent;
        //     m_EdgeLabel = std::format("StructDeclarator{}", i);
        //     structDeclaratorList[i]->Accept(*this);
        // }
    }

    void Visit(StructDeclarator& structDeclarator) override {
        printNode("struct_declarator", "StructDeclarator");

        auto declarator = structDeclarator.GetDeclarator();
        acceptNode(declarator, "Declarator");
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "Declarator";
        // declarator->Accept(*this);
    }

    void Visit(TypeName& typeName) override {
        printNode("type_name", "TypeName");

        auto specifierQualifierList = typeName.GetSpecifierQualifierList();
        acceptNode(specifierQualifierList, "SpecifierQualifierList");
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "SpecifierQualifierList";
        // specifierQualifierList->Accept(*this);

        auto abstractDeclarator = typeName.GetAbstractDeclarator();
        if (abstractDeclarator) {
            acceptNode(abstractDeclarator, "AbstractDeclarator");
        }
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "AbstractDeclarator";
        // abstractDeclarator->Accept(*this);
    }


    /*
    =================================================================
                                Expression
    =================================================================
    */

    // Assignment expression
    void Visit(AssignmentExpression&) override {
        // Base class
    }

    void Visit(ConditionalAssignmentExpression& conditionalAssignmentExpression) override {
        printNode("conditional_assignment_expression", "ConditionalAssignmentExpression"); 

        auto conditionalExpression = conditionalAssignmentExpression.GetConditionalExpression();
        acceptNode(conditionalExpression, "ConditionalExpression");       
    }

    void Visit(UnaryAssignExpression& unaryAssignExpression) override {
        printNode("unary_assign_expression", "UnaryAssignExpression"); 

        auto unaryExpressionLeft = unaryAssignExpression.GetUnaryExpression();
        acceptNode(unaryExpressionLeft, "UnaryExpressionLeft");

        auto assignmentOperator = unaryAssignExpression.GetAssignmentOperator();
        acceptNode(assignmentOperator, "AssignmentOperator");

        auto assignmentExpressionRight = unaryAssignExpression.GetAssignmentExpression();
        acceptNode(assignmentExpressionRight, "AssignmentExpressionRight");
    }

    // Cast expression
    void Visit(CastExpression&) override {
        // Base class
    }

    void Visit(CastTypenameExpression& castTypenameExpression) override {
        printNode("cast_typename_expression", "CastTypenameExpression"); 

        auto typeName = castTypenameExpression.GetTypeName();
        acceptNode(typeName, "TypeName");

        auto castExpressionTail = castTypenameExpression.GetCastExpressionTail();
        acceptNode(castExpressionTail, "CastExpressionTail");
    }

    void Visit(CastUnaryExpression& castUnaryExpression) override {
        printNode("cast_unary_expression", "CastUnaryExpression"); 

        auto unaryExpression = castUnaryExpression.GetUnaryExpression();
        acceptNode(unaryExpression, "UnaryExpression");
    }

    // Postfix expression
    void Visit(AccessExpression& accessExpression) override {
        std::string typeStr = accessExpression.GetTypeStr();
        std::string identifier = accessExpression.GetIdentifier();
        printNode("access_expression",
                  std::format("AccessExpression [{},\\\"{}\\\"]", typeStr, identifier)); 

        auto postfixExpression = accessExpression.GetPostfixExpression();
        acceptNode(postfixExpression, "PostfixExpression");
    }

    void Visit(CallExpression& callExpression) override {
        printNode("call_expression", "CallExpression");

        auto postfixExpression = callExpression.GetPostfixExpression();
        acceptNode(postfixExpression, "PostfixExpression");

        auto argumentExpressions = callExpression.GetArgumentExpressions();
        acceptNodeList(argumentExpressions, "ArgumentExpression");
    }

    void Visit(IncDecPostfixExpression& incDecPostfixExpression) override {
        std::string typeStr = incDecPostfixExpression.GetTypeStr();
        printNode("inc_dec_postfix_expression",
                  std::format("IncDecPostfixExpression [{}]", typeStr));

        auto postfixExpression = incDecPostfixExpression.GetPostfixExpression();
        acceptNode(postfixExpression, "PostfixExpression");
    }

    void Visit(IndexExpression& indexExpression) override {
        printNode("index_expression", "IndexExpression");

        auto postfixExpression = indexExpression.GetPostfixExpression();
        acceptNode(postfixExpression, "PostfixExpression");

        auto indexExpr = indexExpression.GetIndexExpr();
        acceptNode(indexExpr, "IndexExpr");
    }

    void Visit(PostfixExpression&) override {
        // Base class
    }

    // Primary expression
    void Visit(IdentPrimaryExpression& identPrimaryExpression) override {
        std::string ident = identPrimaryExpression.GetIdentifier();
        printNode("ident_primary_expression",
                  std::format("IdentPrimaryExpression [\\\"{}\\\"]", ident));
    }

    void Visit(NestedPrimaryExpression& nestedPrimaryExpression) override {
        printNode("nested_primary_expression", "NestedPrimaryExpression");

        auto expression = nestedPrimaryExpression.GetExpression();
        acceptNode(expression, "Expression");
    }

    void Visit(NumberPrimaryExpression& numberPrimaryExpression) override {
        int number = numberPrimaryExpression.GetNumber();
        printNode("number_primary_expression",
                  std::format("NumberPrimaryExpression [{}]", number));
    }

    void Visit(PrimaryExpression&) override {
        // Base class
    }

    // Unary expression
    void Visit(IncDecPrefixExpression& incDecPrefixExpression) override {
        std::string typeStr = incDecPrefixExpression.GetTypeStr();
        printNode("inc_dec_prefix_expression",
                  std::format("IncDecPrefixExpression [{}]", typeStr));

        auto unaryExpression = incDecPrefixExpression.GetUnaryExpression();
        acceptNode(unaryExpression, "UnaryExpression");
    }

    void Visit(OperatorUnaryExpression& operatorUnaryExpression) override {
        printNode("sizeof_unary_expression", "SizeofUnaryExpression");

        auto unaryOperator = operatorUnaryExpression.GetUnaryOperator();
        acceptNode(unaryOperator, "UnaryOperator");

        auto castExpression = operatorUnaryExpression.GetCastExpression();
        acceptNode(castExpression, "CastExpression");
    }

    void Visit(SizeofTypenameExpression& sizeofTypenameExpression) override {
        printNode("sizeof_typename_expression", "SizeofTypenameExpression");

        auto typeName = sizeofTypenameExpression.GetTypeName();
        acceptNode(typeName, "TypeName");
    }

    void Visit(SizeofUnaryExpression& sizeofUnaryExpression) override {
        printNode("sizeof_unary_expression", "SizeofUnaryExpression");

        auto unaryExpression = sizeofUnaryExpression.GetUnaryExpression();
        acceptNode(unaryExpression, "UnaryExpression");
    }

    void Visit(UnaryExpression&) override {
        // Base class
    }

    // Rest
    void Visit(AdditiveExpression& additiveExpression) override {
        std::string typeStr = additiveExpression.GetTypeStr();
        auto multiplicativeExpressionRight = additiveExpression.GetMultiplicativeExpression();
        if (typeStr != "") {
            printNode("additive_expression",
                      std::format("AdditiveExpression [{}]", typeStr));

            auto additiveExpressionLeft = additiveExpression.GetAdditiveExpression();
            acceptNode(additiveExpressionLeft, "AdditiveExpressionLeft");
            acceptNode(multiplicativeExpressionRight, "MultiplicativeExpressionRight");
        } else {
            printNode("additive_expression", "AdditiveExpression [None]");
            acceptNode(multiplicativeExpressionRight, "MultiplicativeExpression");
        }
    }

    void Visit(AndExpression& andExpression) override {
        printNode("and_expression", "AndExpression");

        auto andExpressionLeft = andExpression.GetAndExpression();
        auto equalityExpressionRight = andExpression.GetEqualityExpression();
        if (andExpressionLeft) {
            acceptNode(andExpressionLeft, "AndExpressionLeft");
            acceptNode(equalityExpressionRight, "EqualityExpressionRight");
        } else {
            acceptNode(equalityExpressionRight, "EqualityExpression");            
        }
    }

    void Visit(AssignmentOperator& assignmentOperator) override {
        std::string typeStr = assignmentOperator.GetTypeStr();
        printNode("assignment_operator",
                  std::format("AssignmentOperator [{}]", typeStr));         
    }

    void Visit(ConditionalExpression& conditionalExpression) override {
        printNode("conditional_expression", "ConditionalExpression"); 

        auto condition = conditionalExpression.GetCondition();
        acceptNode(condition, "Condition");

        auto expression = conditionalExpression.GetExpression();
        auto conditionalExpressionFalse = conditionalExpression.GetConditionalExpressionFalse();
        if (expression && conditionalExpressionFalse) {
            acceptNode(expression, "Expression");
            acceptNode(conditionalExpressionFalse, "ConditionalExpressionFalse");
        }
    }

    void Visit(ConstantExpression& constantExpression) override {
        printNode("constant_expression", "ConstantExpression");

        auto conditionalExpression = constantExpression.GetConditionalExpression();
        acceptNode(conditionalExpression, "ConditionalExpression");
    }

    void Visit(EqualityExpression& equalityExpression) override {
        std::string typeStr = equalityExpression.GetTypeStr();
        auto relationalExpressionRight = equalityExpression.GetRelationalExpression();
        if (typeStr != "") {
            printNode("equality_expression",
                    std::format("EqualityExpression [{}]", typeStr));

            auto equalityExpressionLeft = equalityExpression.GetEqualityExpression();
            acceptNode(equalityExpressionLeft, "EqualityExpressionLeft");
            acceptNode(relationalExpressionRight, "RelationalExpressionRight");
        } else {
            printNode("equality_expression", "EqualityExpression [None]");
            acceptNode(relationalExpressionRight, "RelationalExpression");
        }
    }

    void Visit(ExclusiveOrExpression& exclusiveOrExpression) override {
        printNode("exclusive_or_expression", "ExclusiveOrExpression");

        auto exclusiveOrExpressionLeft = exclusiveOrExpression.GetExclusiveOrExpression();
        auto andExpressionRight = exclusiveOrExpression.GetAndExpression();
        if (exclusiveOrExpressionLeft) {
            acceptNode(exclusiveOrExpressionLeft, "ExclusiveOrExpressionLeft");
            acceptNode(andExpressionRight, "AndExpressionRight");
        } else {
            acceptNode(andExpressionRight, "AndExpression");
        }
    }

    void Visit(Expression& expression) override {
        printNode("expression", "Expression");

        auto expressionHead = expression.GetExpressionHead();
        if (expressionHead) {
            acceptNode(expressionHead, "ExpressionHead");
        }

        auto assignmentExpression = expression.GetAssignmentExpression();
        acceptNode(assignmentExpression, "AssignmentExpression");
    }

    void Visit(InclusiveOrExpression& inclusiveOrExpression) override {
        printNode("inclusive_or_expression", "InclusiveOrExpression");

        auto inclusiveOrExpressionLeft = inclusiveOrExpression.GetInclusiveOrExpression();
        auto exclusiveOrExpressionRight = inclusiveOrExpression.GetExclusiveOrExpression();
        if (inclusiveOrExpressionLeft) {
            acceptNode(inclusiveOrExpressionLeft, "InclusiveOrExpressionLeft");
            acceptNode(exclusiveOrExpressionRight, "ExclusiveOrExpressionRight");
        } else {
            acceptNode(exclusiveOrExpressionRight, "ExclusiveOrExpression");
        }
    }

    void Visit(LogicalAndExpression& logicalAndExpression) override {
        printNode("logical_and_expression", "LogicalAndExpression");

        auto logicalAndExpressionLeft = logicalAndExpression.GetLogicalAndExpression();
        auto inclusiveOrExpressionRight = logicalAndExpression.GetInclusiveOrExpression();
        if (logicalAndExpressionLeft) {
            acceptNode(logicalAndExpressionLeft, "LogicalAndExpressionLeft");
            acceptNode(inclusiveOrExpressionRight, "InclusiveOrExpressionRight");
        } else {
            acceptNode(inclusiveOrExpressionRight, "InclusiveOrExpression");
        }
    }

    void Visit(LogicalOrExpression& logicalOrExpression) override {
        printNode("logical_or_expression", "LogicalOrExpression");

        auto logicalOrExpressionLeft = logicalOrExpression.GetLogicalOrExpression();
        auto logicalAndExpressionRight = logicalOrExpression.GetLogicalAndExpression();
        if (logicalOrExpressionLeft) {
            acceptNode(logicalOrExpressionLeft, "LogicalOrExpressionLeft");
            acceptNode(logicalAndExpressionRight, "LogicalAndExpressionRight");
        } else {
            acceptNode(logicalAndExpressionRight, "LogicalAndExpression");
        }
    }

    void Visit(MultiplicativeExpression& multiplicativeExpression) override {
        std::string typeStr = multiplicativeExpression.GetTypeStr();
        auto castExpressionRight = multiplicativeExpression.GetCastExpression();
        if (typeStr != "") {
            printNode("multiplicative_expression",
                    std::format("MultiplicativeExpression [{}]", typeStr));

            auto multiplicativeExpressionLeft = multiplicativeExpression.GetMultiplicativeExpression();
            acceptNode(multiplicativeExpressionLeft, "MultiplicativeExpressionLeft");
            acceptNode(castExpressionRight, "CastExpressionRight");
        } else {
            printNode("multiplicative_expression", "MultiplicativeExpression [None]");
            acceptNode(castExpressionRight, "CastExpression");
        }
    }

    void Visit(RelationalExpression& relationalExpression) override {
        std::string typeStr = relationalExpression.GetTypeStr();
        auto shiftExpressionRight = relationalExpression.GetShiftExpression();
        if (typeStr != "") {
            printNode("relational_expression",
                    std::format("RelationalExpression [{}]", typeStr));

            auto relationalExpressionLeft = relationalExpression.GetRelationalExpression();
            acceptNode(relationalExpressionLeft, "RelationalExpressionLeft");
            acceptNode(shiftExpressionRight, "ShiftExpressionRight");
        } else {
            printNode("relational_expression", "RelationalExpression [None]");
            acceptNode(shiftExpressionRight, "ShiftExpression");
        }
    }

    void Visit(ShiftExpression& shiftExpression) override {
        std::string typeStr = shiftExpression.GetTypeStr();
        auto additiveExpressionRight = shiftExpression.GetAdditiveExpression();
        if (typeStr != "") {
            printNode("shift_expression",
                    std::format("ShiftExpression [{}]", typeStr));

            auto shiftExpressionLeft = shiftExpression.GetShiftExpression();
            acceptNode(shiftExpressionLeft, "ShiftExpressionLeft");
            acceptNode(additiveExpressionRight, "AdditiveExpressionRight");
        } else {
            printNode("shift_expression", "ShiftExpression [None]");
            acceptNode(additiveExpressionRight, "AdditiveExpression");
        }
    }

    void Visit(UnaryOperator& unaryOperator) override {
        std::string typeStr = unaryOperator.GetTypeStr();
        printNode("unary_operator",
                  std::format("UnaryOperator [{}]", typeStr));
    }

    /*
    =================================================================
                                Statement
    =================================================================
    */

    // Iteration statement
    void Visit(DoWhileIterationStatement& doWhileIterationStatement) override {
        printNode("do_while_iteration_statement", "DoWhileIterationStatement");

        auto expression = doWhileIterationStatement.GetExpression();
        acceptNode(expression, "Expression");

        auto statement = doWhileIterationStatement.GetStatement();
        acceptNode(statement, "Statement");
    }

    void Visit(ForIterationStatement& forIterationStatement) override {
        printNode("for_iteration_statement", "ForIterationStatement");

        auto initExprStatement = forIterationStatement.GetInitExpressionStatement();
        acceptNode(initExprStatement, "InitExpr");

        auto condExprStatement = forIterationStatement.GetCondExpressionStatement();
        acceptNode(condExprStatement, "CondExpr");

        auto loopExpression = forIterationStatement.GetLoopExpression();
        if (loopExpression) {
            acceptNode(loopExpression, "LoopExpr");
        }

        auto statement = forIterationStatement.GetStatement();
        acceptNode(statement, "Statement");
    }

    void Visit(IterationStatement&) override {
        // Base class
    }

    void Visit(WhileIterationStatement& whileIterationStatement) override {
        printNode("while_iteration_statement", "WhileIterationStatement");

        auto expression = whileIterationStatement.GetExpression();
        acceptNode(expression, "Expression");

        auto statement = whileIterationStatement.GetStatement();
        acceptNode(statement, "Statement");
    }

    // Jump statement
    void Visit(JumpStatement&) override {
        // Base class
    }

    void Visit(LoopJumpStatement& loopJumpStatement) override {
        std::string typeStr = loopJumpStatement.GetTypeStr();
        printNode("loop_jump_statement",
                  std::format("LoopJumpStatement [{}]", typeStr));
    }

    void Visit(ReturnJumpStatement& returnJumpStatement) override {
        printNode("return_jump_statement", "ReturnJumpStatement");

        auto expression = returnJumpStatement.GetExpression();
        if (expression) {
            acceptNode(expression, "Expression");
        }
    }

    // Labeled statement
    void Visit(CaseLabeledStatement& caseLabeledStatement) override {
        printNode("case_labeled_statement", "CaseLabeledStatement");

        auto constExpression = caseLabeledStatement.GetConstExpression();
        acceptNode(constExpression, "ConstExpr");

        auto statement = caseLabeledStatement.GetStatement();
        acceptNode(statement, "Statement");
    }

    void Visit(DefaultLabeledStatement& defaultLabeledStatement) override {
        printNode("default_labeled_statement", "DefaultLabeledStatement");

        auto statement = defaultLabeledStatement.GetStatement();
        acceptNode(statement, "Statement");
    }

    void Visit(IdentLabeledStatement& identLabeledStatement) override {
        std::string identifier = identLabeledStatement.GetIdentifier();
        printNode("ident_labeled_statement",
                  std::format("IdentLabeledStatement [\\\"{}\\\"]", identifier));

        auto statement = identLabeledStatement.GetStatement();
        acceptNode(statement, "Statement");
    }

    void Visit(LabeledStatement&) override {
        // Base class
    }

    // Selection statement
    void Visit(IfSelectionStatement& ifSelectionStatement) override {
        printNode("if_selection_statement", "IfSelectionStatement");

        auto expression = ifSelectionStatement.GetExpression();
        acceptNode(expression, "Expression");
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "Expression";
        // expression->Accept(*this);

        auto statementTrue = ifSelectionStatement.GetStatementTrue();
        acceptNode(statementTrue, "StatementTrue");
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "StatementTrue";
        // statementTrue->Accept(*this);

        auto statementFalse = ifSelectionStatement.GetStatementFalse();
        if (statementFalse) {
            acceptNode(statementFalse, "StatementFalse");
        }
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "StatementFalse";
        // statementFalse->Accept(*this); 
    }

    void Visit(SelectionStatement&) override {
        // Base class
    }

    void Visit(SwitchSelectionStatement& switchSelectionStatement) override {
        printNode("switch_selection_statement", "SwitchSelectionStatement");

        auto expression = switchSelectionStatement.GetExpression();
        acceptNode(expression, "Expression");

        auto statement = switchSelectionStatement.GetStatement();
        acceptNode(statement, "Statement");
    }

    // Rest
    void Visit(CompoundStatement& compoundStatement) override {
        printNode("compound_statement", "CompoundStatement");

        auto declarations = compoundStatement.GetDeclarations();
        acceptNodeList(declarations, "Declaration");
        // for (size_t i = 0; i < declarations.size(); ++i) {
        //     m_PreviousNodeIdent = m_CurrentNodeIdent;
        //     m_EdgeLabel = std::format("Declaration{}", i);
        //     declarations[i]->Accept(*this);
        // }

        auto statements = compoundStatement.GetStatements();
        acceptNodeList(statements, "Expression");
        // for (size_t i = 0; i < statements.size(); ++i) {
        //     m_PreviousNodeIdent = m_CurrentNodeIdent;
        //     m_EdgeLabel = std::format("Expression{}", i);
        //     statements[i]->Accept(*this);
        // }
    }

    void Visit(ExpressionStatement& expressionStatement) override {
        printNode("expression_statement", "ExpressionStatement");

        auto expression = expressionStatement.GetExpression();
        acceptNode(expression, "Expression");
        // m_PreviousNodeIdent = m_CurrentNodeIdent;
        // m_EdgeLabel = "Expression";
        // expression->Accept(*this);
    }

    void Visit(Statement&) override {
        // Base class
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
    
    void printNodeAttributes(const std::string& label) {
        printSpaces();
        m_OutputStream << "shape=record,\n";
        printSpaces();
        m_OutputStream << "style=filled,\n";
        printSpaces();
        m_OutputStream << "fillcolor=lightgrey,\n";
        printSpaces();
        m_OutputStream << std::format("label=\"{}\",\n", label);
        printSpaces();
        m_OutputStream << "fontsize=\"15pt\"\n";
    }

    void printNode(const std::string& ident, const std::string& label) {
        m_CurrentNodeIdent = getId(ident);

        printWithSpaces(std::format("{} [\n", m_CurrentNodeIdent));

        spaceLevelUp();
        printNodeAttributes(label);
        spaceLevelDown();

        printWithSpaces("];\n");

        printWithSpaces(std::format("{} -> {} [label=\"{}\", fontsize=\"13pt\"];\n",
                        m_PreviousNodeIdent, m_CurrentNodeIdent, m_EdgeLabel));
    }

    template <typename S>
    void acceptNode(RefT<S> node, const std::string& edgeLabel) {
        m_PreviousNodeIdent = m_CurrentNodeIdent;
        std::string prevNodeIdent = m_PreviousNodeIdent;
        m_EdgeLabel = edgeLabel;
        node->Accept(*this);
        m_CurrentNodeIdent = prevNodeIdent;
    }

    template <typename S>
    void acceptNodeList(const std::vector<RefT<S>>& nodeList, const std::string& edgeLabel) {
        m_PreviousNodeIdent = m_CurrentNodeIdent;
        std::string prevNodeIdent = m_PreviousNodeIdent;
        for (size_t i = 0; i < nodeList.size(); ++i) {
            m_EdgeLabel = std::format("{}{}", edgeLabel, i);
            nodeList[i]->Accept(*this);
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

    const std::string m_GraphName = "program";

    std::string m_CurrentNodeIdent;
    std::string m_PreviousNodeIdent;
    std::string m_EdgeLabel;

    size_t m_IdCounter = 0;
};

}  // namespace ast
