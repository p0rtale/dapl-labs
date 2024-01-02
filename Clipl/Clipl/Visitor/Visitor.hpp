#pragma once

#include <Clipl/Grammar/AST/ForwardDecl.hpp>

class Visitor {
public:
    /*
    =================================================================
                                Program
    =================================================================
    */

    // Declaration specifiers
    virtual void Visit(RefT<DeclarationSpecifiers> declarationSpecifiers) = 0;
    virtual void Visit(RefT<IdentDeclarationSpecifiers> identDeclarationSpecifiers) = 0;
    virtual void Visit(RefT<KeywordDeclarationSpecifiers> keywordDeclarationSpecifiers) = 0;

    // Declarator
    virtual void Visit(RefT<AbstractDeclarator> abstractDeclarator) = 0;
    virtual void Visit(RefT<BaseDeclarator> baseDeclarator) = 0;
    virtual void Visit(RefT<Declarator> declarator) = 0;

    // Direct abstract declarator
    virtual void Visit(RefT<ArrayDirectAbstractDeclarator> arrayDeclarator) = 0;
    virtual void Visit(RefT<DirectAbstractDeclarator> directAbstractDeclarator) = 0;
    virtual void Visit(RefT<NestedDirectAbstractDeclarator> nestedDeclarator) = 0;
    virtual void Visit(RefT<ParameterDirectAbstractDeclarator> parameterDeclarator) = 0;

    // Direct declarator
    virtual void Visit(RefT<ArrayDirectDeclarator> arrayDeclarator) = 0;
    virtual void Visit(RefT<DirectDeclarator> directDeclarator) = 0;
    virtual void Visit(RefT<IdentDirectDeclarator> identDeclarator) = 0;
    virtual void Visit(RefT<NestedDirectDeclarator> nestedDeclarator) = 0;
    virtual void Visit(RefT<ParameterDirectDeclarator> parameterDeclarator) = 0;

    // External declaration
    virtual void Visit(RefT<Declaration> declaration) = 0;
    virtual void Visit(RefT<ExternalDeclaration> externalDeclaration) = 0;
    virtual void Visit(RefT<FunctionDefinition> functionDefinition) = 0;

    // Initializer
    virtual void Visit(RefT<ExpressionInitializer> expressionInitializer) = 0;
    virtual void Visit(RefT<Initializer> initializer) = 0;
    virtual void Visit(RefT<InitializerList> initializerList) = 0;

    // Keyword specifier
    virtual void Visit(RefT<BasicKeywordSpecifier> basicKeywordSpecifier) = 0;
    virtual void Visit(RefT<EnumSpecifier> enumSpecifier) = 0;
    virtual void Visit(RefT<KeywordSpecifier> keywordSpecifier) = 0;
    virtual void Visit(RefT<StructOrUnionSpecifier> structOrUnionSpecifier) = 0;

    // Specifier
    virtual void Visit(RefT<Specifier> specifier) = 0;
    virtual void Visit(RefT<StorageClassSpecifier> storageClassSpecifier) = 0;
    virtual void Visit(RefT<TypeQualifier> typeQualifier) = 0;

    virtual void Visit(RefT<Enumerator> enumerator) = 0;
    virtual void Visit(RefT<IdentSpecifier> identSpecifier) = 0;
    virtual void Visit(RefT<InitDeclarator> initDeclarator) = 0;
    virtual void Visit(RefT<ParameterDeclaration> parameterDeclaration) = 0;
    virtual void Visit(RefT<ParameterTypeList> parameterTypeList) = 0;
    virtual void Visit(RefT<Pointer> pointer) = 0;
    virtual void Visit(RefT<SpecifierQualifierList> specifierQualifierList) = 0;
    virtual void Visit(RefT<StructDeclaration> structDeclaration) = 0;
    virtual void Visit(RefT<StructDeclarator> structDeclarator) = 0;
    virtual void Visit(RefT<TranslationUnit> translationUnit) = 0;
    virtual void Visit(RefT<TypeName> typeName) = 0;


    /*
    =================================================================
                                Expression
    =================================================================
    */

    // Assignment expression
    virtual void Visit(RefT<AssignmentExpression> assignmentExpression) = 0;
    virtual void Visit(RefT<ConditionalAssignmentExpression> conditionalExpression) = 0;
    virtual void Visit(RefT<UnaryAssignExpression> unaryAssignExpression) = 0;

    // Cast expression
    virtual void Visit(RefT<CastExpression> castExpression) = 0;
    virtual void Visit(RefT<CastTypenameExpression> castTypenameExpression) = 0;
    virtual void Visit(RefT<CastUnaryExpression> castUnaryExpression) = 0;

    // Postfix expression
    virtual void Visit(RefT<AccessExpression> accessExpression) = 0;
    virtual void Visit(RefT<CallExpression> callExpression) = 0;
    virtual void Visit(RefT<IncDecPostfixExpression> incDecPostfixExpression) = 0;
    virtual void Visit(RefT<IndexExpression> indexExpression) = 0;
    virtual void Visit(RefT<PostfixExpression> postfixExpression) = 0;

    // Primary expression
    virtual void Visit(RefT<IdentPrimaryExpression> identPrimaryExpression) = 0;
    virtual void Visit(RefT<NestedPrimaryExpression> nestedPrimaryExpression) = 0;
    virtual void Visit(RefT<NumberPrimaryExpression> numberPrimaryExpression) = 0;
    virtual void Visit(RefT<PrimaryExpression> primaryExpression) = 0;

    // Unary expression
    virtual void Visit(RefT<IncDecPrefixExpression> incDecPrefixExpression) = 0;
    virtual void Visit(RefT<OperatorUnaryExpression> operatorUnaryExpression) = 0;
    virtual void Visit(RefT<SizeofTypenameExpression> sizeofTypenameExpression) = 0;
    virtual void Visit(RefT<SizeofUnaryExpression> sizeofUnaryExpression) = 0;
    virtual void Visit(RefT<UnaryExpression> unaryExpression) = 0;

    virtual void Visit(RefT<AdditiveExpression> additiveExpression) = 0;
    virtual void Visit(RefT<AndExpression> andExpression) = 0;
    virtual void Visit(RefT<AssignmentOperator> assignmentOperator) = 0;
    virtual void Visit(RefT<ConditionalExpression> conditionalExpression) = 0;
    virtual void Visit(RefT<ConstantExpression> constantExpression) = 0;
    virtual void Visit(RefT<EqualityExpression> equalityExpression) = 0;
    virtual void Visit(RefT<ExclusiveOrExpression> exclusiveOrExpression) = 0;
    virtual void Visit(RefT<Expression> expression) = 0;
    virtual void Visit(RefT<InclusiveOrExpression> inclusiveOrExpression) = 0;
    virtual void Visit(RefT<LogicalAndExpression> logicalAndExpression) = 0;
    virtual void Visit(RefT<LogicalOrExpression> logicalOrExpression) = 0;
    virtual void Visit(RefT<MultiplicativeExpression> multiplicativeExpression) = 0;
    virtual void Visit(RefT<RelationalExpression> relationalExpression) = 0;
    virtual void Visit(RefT<ShiftExpression> shiftExpression) = 0;
    virtual void Visit(RefT<UnaryOperator> unaryOperator) = 0;

    /*
    =================================================================
                                Statement
    =================================================================
    */

    // Iteration statement
    virtual void Visit(RefT<DoWhileIterationStatement> doWhileIterationStatement) = 0;
    virtual void Visit(RefT<ForIterationStatement> forIterationStatement) = 0;
    virtual void Visit(RefT<IterationStatement> iterationStatement) = 0;
    virtual void Visit(RefT<WhileIterationStatement> whileIterationStatement) = 0;

    // Jump statement
    virtual void Visit(RefT<JumpStatement> jumpStatement) = 0;
    virtual void Visit(RefT<LoopJumpStatement> loopJumpStatement) = 0;
    virtual void Visit(RefT<ReturnJumpStatement> returnJumpStatement) = 0;

    // Labeled statement
    virtual void Visit(RefT<CaseLabeledStatement> caseLabeledStatement) = 0;
    virtual void Visit(RefT<DefaultLabeledStatement> defaultLabeledStatement) = 0;
    virtual void Visit(RefT<IdentLabeledStatement> identLabeledStatement) = 0;
    virtual void Visit(RefT<LabeledStatement> labeledStatement) = 0;

    // Selection statement
    virtual void Visit(RefT<IfSelectionStatement> ifSelectionStatement) = 0;
    virtual void Visit(RefT<SelectionStatement> selectionStatement) = 0;
    virtual void Visit(RefT<SwitchSelectionStatement> switchSelectionStatement) = 0;

    virtual void Visit(RefT<CompoundStatement> compoundStatement) = 0;
    virtual void Visit(RefT<ExpressionStatement> expressionStatement) = 0;
    virtual void Visit(RefT<Statement> statement) = 0;
};
