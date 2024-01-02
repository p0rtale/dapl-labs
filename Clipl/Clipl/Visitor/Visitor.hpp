#pragma once

#include <Clipl/Grammar/AST/ForwardDecl.hpp>


namespace ast {

class Visitor {
public:
    /*
    =================================================================
                                Program
    =================================================================
    */

    // Declaration specifiers
    virtual void Visit(DeclarationSpecifiers& declarationSpecifiers) = 0;
    virtual void Visit(IdentDeclarationSpecifiers& identDeclarationSpecifiers) = 0;
    virtual void Visit(KeywordDeclarationSpecifiers& keywordDeclarationSpecifiers) = 0;

    // Declarator
    virtual void Visit(AbstractDeclarator& abstractDeclarator) = 0;
    virtual void Visit(BaseDeclarator& baseDeclarator) = 0;
    virtual void Visit(Declarator& declarator) = 0;

    // Direct abstract declarator
    virtual void Visit(ArrayDirectAbstractDeclarator& arrayDeclarator) = 0;
    virtual void Visit(DirectAbstractDeclarator& directAbstractDeclarator) = 0;
    virtual void Visit(NestedDirectAbstractDeclarator& nestedDeclarator) = 0;
    virtual void Visit(ParameterDirectAbstractDeclarator& parameterDeclarator) = 0;

    // Direct declarator
    virtual void Visit(ArrayDirectDeclarator& arrayDeclarator) = 0;
    virtual void Visit(DirectDeclarator& directDeclarator) = 0;
    virtual void Visit(IdentDirectDeclarator& identDeclarator) = 0;
    virtual void Visit(NestedDirectDeclarator& nestedDeclarator) = 0;
    virtual void Visit(ParameterDirectDeclarator& parameterDeclarator) = 0;

    // External declaration
    virtual void Visit(Declaration& declaration) = 0;
    virtual void Visit(ExternalDeclaration& externalDeclaration) = 0;
    virtual void Visit(FunctionDefinition& functionDefinition) = 0;

    // Initializer
    virtual void Visit(ExpressionInitializer& expressionInitializer) = 0;
    virtual void Visit(Initializer& initializer) = 0;
    virtual void Visit(InitializerList& initializerList) = 0;

    // Keyword specifier
    virtual void Visit(BasicKeywordSpecifier& basicKeywordSpecifier) = 0;
    virtual void Visit(EnumSpecifier& enumSpecifier) = 0;
    virtual void Visit(KeywordSpecifier& keywordSpecifier) = 0;
    virtual void Visit(StructOrUnionSpecifier& structOrUnionSpecifier) = 0;

    // Specifier
    virtual void Visit(Specifier& specifier) = 0;
    virtual void Visit(StorageClassSpecifier& storageClassSpecifier) = 0;
    virtual void Visit(TypeQualifier& typeQualifier) = 0;

    virtual void Visit(Enumerator& enumerator) = 0;
    virtual void Visit(IdentSpecifier& identSpecifier) = 0;
    virtual void Visit(InitDeclarator& initDeclarator) = 0;
    virtual void Visit(ParameterDeclaration& parameterDeclaration) = 0;
    virtual void Visit(ParameterTypeList& parameterTypeList) = 0;
    virtual void Visit(Pointer& pointer) = 0;
    virtual void Visit(Program& program) = 0;
    virtual void Visit(SpecifierQualifierList& specifierQualifierList) = 0;
    virtual void Visit(StructDeclaration& structDeclaration) = 0;
    virtual void Visit(StructDeclarator& structDeclarator) = 0;
    virtual void Visit(TypeName& typeName) = 0;


    /*
    =================================================================
                                Expression
    =================================================================
    */

    // Assignment expression
    virtual void Visit(AssignmentExpression& assignmentExpression) = 0;
    virtual void Visit(ConditionalAssignmentExpression& conditionalAssignmentExpression) = 0;
    virtual void Visit(UnaryAssignExpression& unaryAssignExpression) = 0;

    // Cast expression
    virtual void Visit(CastExpression& castExpression) = 0;
    virtual void Visit(CastTypenameExpression& castTypenameExpression) = 0;
    virtual void Visit(CastUnaryExpression& castUnaryExpression) = 0;

    // Postfix expression
    virtual void Visit(AccessExpression& accessExpression) = 0;
    virtual void Visit(CallExpression& callExpression) = 0;
    virtual void Visit(IncDecPostfixExpression& incDecPostfixExpression) = 0;
    virtual void Visit(IndexExpression& indexExpression) = 0;
    virtual void Visit(PostfixExpression& postfixExpression) = 0;

    // Primary expression
    virtual void Visit(IdentPrimaryExpression& identPrimaryExpression) = 0;
    virtual void Visit(NestedPrimaryExpression& nestedPrimaryExpression) = 0;
    virtual void Visit(NumberPrimaryExpression& numberPrimaryExpression) = 0;
    virtual void Visit(PrimaryExpression& primaryExpression) = 0;

    // Unary expression
    virtual void Visit(IncDecPrefixExpression& incDecPrefixExpression) = 0;
    virtual void Visit(OperatorUnaryExpression& operatorUnaryExpression) = 0;
    virtual void Visit(SizeofTypenameExpression& sizeofTypenameExpression) = 0;
    virtual void Visit(SizeofUnaryExpression& sizeofUnaryExpression) = 0;
    virtual void Visit(UnaryExpression& unaryExpression) = 0;

    virtual void Visit(AdditiveExpression& additiveExpression) = 0;
    virtual void Visit(AndExpression& andExpression) = 0;
    virtual void Visit(AssignmentOperator& assignmentOperator) = 0;
    virtual void Visit(ConditionalExpression& conditionalExpression) = 0;
    virtual void Visit(ConstantExpression& constantExpression) = 0;
    virtual void Visit(EqualityExpression& equalityExpression) = 0;
    virtual void Visit(ExclusiveOrExpression& exclusiveOrExpression) = 0;
    virtual void Visit(Expression& expression) = 0;
    virtual void Visit(InclusiveOrExpression& inclusiveOrExpression) = 0;
    virtual void Visit(LogicalAndExpression& logicalAndExpression) = 0;
    virtual void Visit(LogicalOrExpression& logicalOrExpression) = 0;
    virtual void Visit(MultiplicativeExpression& multiplicativeExpression) = 0;
    virtual void Visit(RelationalExpression& relationalExpression) = 0;
    virtual void Visit(ShiftExpression& shiftExpression) = 0;
    virtual void Visit(UnaryOperator& unaryOperator) = 0;

    /*
    =================================================================
                                Statement
    =================================================================
    */

    // Iteration statement
    virtual void Visit(DoWhileIterationStatement& doWhileIterationStatement) = 0;
    virtual void Visit(ForIterationStatement& forIterationStatement) = 0;
    virtual void Visit(IterationStatement& iterationStatement) = 0;
    virtual void Visit(WhileIterationStatement& whileIterationStatement) = 0;

    // Jump statement
    virtual void Visit(JumpStatement& jumpStatement) = 0;
    virtual void Visit(LoopJumpStatement& loopJumpStatement) = 0;
    virtual void Visit(ReturnJumpStatement& returnJumpStatement) = 0;

    // Labeled statement
    virtual void Visit(CaseLabeledStatement& caseLabeledStatement) = 0;
    virtual void Visit(DefaultLabeledStatement& defaultLabeledStatement) = 0;
    virtual void Visit(IdentLabeledStatement& identLabeledStatement) = 0;
    virtual void Visit(LabeledStatement& labeledStatement) = 0;

    // Selection statement
    virtual void Visit(IfSelectionStatement& ifSelectionStatement) = 0;
    virtual void Visit(SelectionStatement& selectionStatement) = 0;
    virtual void Visit(SwitchSelectionStatement& switchSelectionStatement) = 0;

    virtual void Visit(CompoundStatement& compoundStatement) = 0;
    virtual void Visit(ExpressionStatement& expressionStatement) = 0;
    virtual void Visit(Statement& statement) = 0;
};

}  // namespace ast
