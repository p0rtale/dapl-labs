%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <memory>

    /* Forward declaration of classes in order to disable cyclic dependencies */
    namespace clipl {
        class Lexer;
        class Driver;
    }

    #include <Clipl/Grammar/AST/ForwardDecl.hpp>

    using namespace clipl;
    using namespace ast;
}


%define parse.trace
%define parse.error verbose

%code {
    #include <Clipl/Grammar/Driver/Driver.hpp>
    #include <Clipl/Grammar/Parser/location.hh>
    #include <Clipl/Grammar/Lexer/Lexer.hpp>

    #include <Clipl/Grammar/AST/AST.hpp>

    /* Redefine parser to use our function from scanner */
    static yy::parser::symbol_type yylex(Lexer &lexer) {
        return lexer.scanToken();
    }
}

%lex-param { Lexer &lexer }

%parse-param { Lexer &lexer }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    LSBRACKET "["
    RSBRACKET "]"
    LPAREN "("
    RPAREN ")"
    LCBRACKET "{"
    RCBRACKET "}"

    ELLIPSIS "..."

    DOT "."
    ARROW "->"

    INCREMENT "++"
    DECREMENT "--"

    AMPERSAND "&"
    STAR "*"
    PLUS "+"
    MINUS "-"
    LOGICAL_NOT "~"
    NOT "!"
    SLASH "/"
    PERCENT "%"

    LTLT "<<"
    GTGT ">>"

    LT "<"
    GT ">"
    LE "<="
    GE ">="
    EQUAL "=="
    NOT_EQUAL "!="

    LOGICAL_XOR "^"
    LOGICAL_OR "|"

    AND "&&"
    OR "||"

    QUESTION "?"

    COLON ":"
    SEMICOLON ";"

    ASSIGN "="
    STAR_ASSIGN "*="
    SLASH_ASSIGN "/="
    PERCENT_ASSIGN "%="
    PLUS_ASSIGN "+="
    MINUS_ASSIGN "-="
    LTLT_ASSIGN "<<="
    GTGT_ASSIGN ">>="
    AMPERSAND_ASSIGN "&="
    XOR_ASSIGN "^="
    OR_ASSIGN "|="

    COMMA ","

    BREAK "break"
    CONTINUE "continue"

    SWITCH "switch"
    DEFAULT "default"
    CASE "case"

    VOID "void"
    CHAR "char"
    SHORT "short"
    INT "int"
    LONG "long"
    FLOAT "float"
    DOUBLE "double"

    SIGNED "signed"
    UNSIGNED "unsigned"

    CONST "const"
    VOLATILE "volatile"

    DO "do"
    FOR "for"
    WHILE "while"

    IF "if"
    ELSE "else"

    RETURN "return"

    STRUCT "struct"
    ENUM "enum"
    UNION "union"

    STATIC "static"
    EXTERN "extern"

    TYPEDEF "typedef"

    GOTO "goto"

    SIZEOF "sizeof"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"


%nterm <std::shared_ptr<TranslationUnit>> translation_unit;
%nterm <std::shared_ptr<ExternalDeclaration>> external_declaration;
%nterm <std::shared_ptr<FunctionDefinition>> function_definition;
%nterm <std::shared_ptr<DeclarationSpecifiers>> declaration_specifiers;
%nterm <std::shared_ptr<IdentDeclarationSpecifiers>> ident_specifier_list;
%nterm <std::shared_ptr<IdentSpecifier>> ident_specifier;
%nterm <std::shared_ptr<KeywordSpecifier>> keyword_specifier;
%nterm <std::shared_ptr<KeywordDeclarationSpecifiers>> keyword_specifier_list;
%nterm <std::shared_ptr<Specifier>> specifier;
%nterm <std::vector<std::shared_ptr<Specifier>>> specifier_list;
%nterm <std::shared_ptr<StorageClassSpecifier>> storage_class_specifier;
%nterm <std::shared_ptr<TypeQualifier>> type_qualifier;
%nterm <std::vector<std::shared_ptr<TypeQualifier>>> type_qualifier_list;
%nterm <std::shared_ptr<Declarator>> declarator;
%nterm <std::shared_ptr<Pointer>> pointer;
%nterm <std::shared_ptr<DirectDeclarator>> direct_declarator;
%nterm <std::shared_ptr<ParameterTypeList>> parameter_type_list;
%nterm <std::vector<std::shared_ptr<ParameterDeclaration>>> parameter_list;
%nterm <std::shared_ptr<ParameterDeclaration>> parameter_declaration;
%nterm <std::shared_ptr<AbstractDeclarator>> abstract_declarator;
%nterm <std::shared_ptr<DirectAbstractDeclarator>> direct_abstract_declarator;
%nterm <std::shared_ptr<ConstantExpression>> constant_expression;
%nterm <std::shared_ptr<ConditionalExpression>> conditional_expression;
%nterm <std::shared_ptr<LogicalOrExpression>> logical_or_expression;
%nterm <std::shared_ptr<LogicalAndExpression>> logical_and_expression;
%nterm <std::shared_ptr<InclusiveOrExpression>> inclusive_or_expression;
%nterm <std::shared_ptr<ExclusiveOrExpression>> exclusive_or_expression;
%nterm <std::shared_ptr<AndExpression>> and_expression;
%nterm <std::shared_ptr<EqualityExpression>> equality_expression;
%nterm <std::shared_ptr<RelationalExpression>> relational_expression;
%nterm <std::shared_ptr<ShiftExpression>> shift_expression;
%nterm <std::shared_ptr<AdditiveExpression>> additive_expression;
%nterm <std::shared_ptr<MultiplicativeExpression>> multiplicative_expression;
%nterm <std::shared_ptr<CastExpression>> cast_expression;
%nterm <std::shared_ptr<TypeName>> type_name;
%nterm <std::shared_ptr<SpecifierQualifierList>> specifier_qualifier_list;
%nterm <std::shared_ptr<UnaryExpression>> unary_expression;
%nterm <std::shared_ptr<UnaryOperator>> unary_operator;
%nterm <std::shared_ptr<PostfixExpression>> postfix_expression;
%nterm <std::vector<std::shared_ptr<AssignmentExpression>>> argument_expression_list;
%nterm <std::shared_ptr<PrimaryExpression>> primary_expression;
%nterm <std::shared_ptr<Expression>> expression;
%nterm <std::shared_ptr<AssignmentExpression>> assignment_expression;
%nterm <std::shared_ptr<AssignmentOperator>> assignment_operator;
%nterm <std::shared_ptr<CompoundStatement>> compound_statement;
%nterm <std::vector<std::shared_ptr<Declaration>>> declaration_list;
%nterm <std::shared_ptr<Declaration>> declaration;
%nterm <std::vector<std::shared_ptr<InitDeclarator>>> init_declarator_list;
%nterm <std::shared_ptr<InitDeclarator>> init_declarator;
%nterm <std::vector<std::shared_ptr<Initializer>>> initializer_list;
%nterm <std::shared_ptr<Initializer>> initializer;
%nterm <std::vector<std::shared_ptr<Statement>>> statement_list;
%nterm <std::shared_ptr<Statement>> statement;
%nterm <std::shared_ptr<LabeledStatement>> labeled_statement;
%nterm <std::shared_ptr<ExpressionStatement>> expression_statement;
%nterm <std::shared_ptr<SelectionStatement>> selection_statement;
%nterm <std::shared_ptr<IterationStatement>> iteration_statement;
%nterm <std::shared_ptr<JumpStatement>> jump_statement;

%nterm <std::shared_ptr<Enumerator>> enumerator;
%nterm <std::shared_ptr<EnumeratorList>> enumerator_list;
%nterm <std::shared_ptr<EnumSpecifier>> enum_specifier;

%nterm <std::shared_ptr<StructOrUnionSpecifier>> struct_or_union_specifier;
%nterm <std::shared_ptr<StructDeclaration>> struct_declaration;
%nterm <std::shared_ptr<StructDeclarationList>> struct_declaration_list;
%nterm <std::shared_ptr<StructDeclarator>> struct_declarator;
%nterm <std::shared_ptr<StructDeclaratorList>> struct_declarator_list;


// Prints output in parsing option for debugging location terminal
// %printer { yyo << $$; } <*>;

%%

%start translation_unit;

translation_unit
    : external_declaration {
        $$ = std::make_shared<TranslationUnit>($1);
    }
    | external_declaration translation_unit {
        $$ = std::make_shared<TranslationUnit>($1, $2);
    };

external_declaration
    : function_definition {
        $$ = $1;
    }
    | declaration {
        $$ = $1;
    };

function_definition
    : declaration_specifiers declarator compound_statement {
        $$ = std::make_shared<FunctionDefinition>($1, $2, $3);
    }
    | declaration_specifiers error compound_statement {
        // TODO: handle error
    }
    | error compound_statement {
        // TODO: handle error
    };

declaration_specifiers
    : specifier declaration_specifiers {
        auto declarationSpecifiers = $2;
        declarationSpecifiers->addSpecifier($1);
        $$ = declarationSpecifiers;
    }
    | keyword_specifier_list {
        $$ = std::static_pointer_cast<DeclarationSpecifiers>($1);
    }
    | ident_specifier_list {
        $$ = std::static_pointer_cast<DeclarationSpecifiers>($1);
    };

specifier_qualifier_list
    : keyword_specifier specifier_qualifier_list {

    }
    | keyword_specifier {

    }
    | ident_specifier specifier_qualifier_list {

    }
    | ident_specifier {

    }
    | type_qualifier specifier_qualifier_list {

    }
    | type_qualifier {

    };

specifier
    : storage_class_specifier {
        $$ = $1;
    }
    | type_qualifier {
        $$ = $1;
    };

keyword_specifier_list
    : keyword_specifier {
        $$ = std::make_shared<KeywordDeclarationSpecifiers>($1);
    }
    | keyword_specifier_list keyword_specifier {
        auto keywordSpecifierList = $1;
        keywordSpecifierList->addKeywordSpecifier($2);
        $$ = keywordSpecifierList;
    }
    | keyword_specifier_list specifier {
        auto keywordSpecifierList = $1;
        keywordSpecifierList->addSpecifier($2);
        $$ = keywordSpecifierList;
    };

ident_specifier_list
    : ident_specifier {
        $$ = std::make_shared<IdentDeclarationSpecifiers>($1);
    }
    | ident_specifier specifier_list {
        $$ = std::make_shared<IdentDeclarationSpecifiers>($1, $2);  
    };

specifier_list
    : specifier_list specifier {
        ($1).push_back($2);
        $$ = std::move($1);
    }
    | specifier {
        $$ = std::vector{$1};
    };

keyword_specifier
    : "void" {
        $$ = std::make_shared<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kVoid);
    }
    | "char" {
        $$ = std::make_shared<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kChar);
    }
    | "short" {
        $$ = std::make_shared<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kShort);
    }
    | "int" {
        $$ = std::make_shared<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kInt);
    }
    | "long" {
        $$ = std::make_shared<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kLong);
    }
    | "float" {
        $$ = std::make_shared<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kFloat);
    }
    | "double" {
        $$ = std::make_shared<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kDouble);
    }
    | "signed" {
        $$ = std::make_shared<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kSigned);
    }
    | "unsigned" {
        $$ = std::make_shared<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kUnsigned);
    }
    | struct_or_union_specifier {

    }
    | enum_specifier {

    };

struct_or_union_specifier
    : struct_or_union IDENTIFIER '{' struct_declaration_list '}' {

    }
    | struct_or_union '{' struct_declaration_list '}' {

    }
    | struct_or_union IDENTIFIER {

    }
    | struct_or_union IDENTIFIER '{' error '}' {
        // TODO: handle
    }
    | struct_or_union '{' error '}' {
        // TODO: handle error
    };

struct_or_union
    : "struct" {
        
    }
    | "union" {

    };

struct_declaration_list
    : struct_declaration {

    }
    | struct_declaration_list struct_declaration {

    };

struct_declaration
    : specifier_qualifier_list struct_declarator_list ';' {

    }
    | error ';' {
        // TODO: handle error
    };

struct_declarator_list
    : struct_declarator {

    }
    | struct_declarator_list ',' struct_declarator {

    }
    | error ',' struct_declarator {
        // TODO: handle error
    };

struct_declarator
    : declarator {

    };

enum_specifier
    : "enum" '{' enumerator_list '}' {

    }
    | "enum" IDENTIFIER '{' enumerator_list '}' {

    }
    | "enum" '{' error '}' {
        // TODO: handle error
    }
    | "enum" IDENTIFIER '{' error '}' {
        // TODO: handle error
    }
    | "enum" IDENTIFIER {

    };

enumerator_list
    : enumerator {

    }
    | enumerator_list ',' enumerator {

    }
    | error ',' enumerator {
        // TODO: handle error
    };

enumerator
    : IDENTIFIER {

    }
    | IDENTIFIER '=' constant_expression {

    }
    | error '=' constant_expression {
        // TODO: handle error
    };

storage_class_specifier
    : "typedef" {
        $$ = std::make_shared<StorageClassSpecifier>(StorageClassSpecifier::Type::kTypedef);
    }
    | "extern" {
        $$ = std::make_shared<StorageClassSpecifier>(StorageClassSpecifier::Type::kExtern);
    }
    | "static" {
        $$ = std::make_shared<StorageClassSpecifier>(StorageClassSpecifier::Type::kStatic);
    };

type_qualifier
    : "const" {
        $$ = std::make_shared<TypeQualifier>(TypeQualifier::Type::kConst);
    }
    | "volatile" {
        $$ = std::make_shared<TypeQualifier>(TypeQualifier::Type::kVolatile);
    };

type_qualifier_list
    : type_qualifier {
        $$ = std::vector{$1};
    }
    | type_qualifier_list type_qualifier {
        ($1).push_back($2);
        $$ = std::move($1);
    };

declarator
    : pointer direct_declarator {
        $$ = std::make_shared<Declarator>($2, $1);
    }
    | direct_declarator {
        $$ = std::make_shared<Declarator>($1);
    };

pointer
    : "*" {
        $$ = std::make_shared<Pointer>();
    }
    | "*" type_qualifier_list {
        $$ = std::make_shared<Pointer>($2);
    }
    | "*" pointer {
        std::vector<std::shared_ptr<TypeQualifier>> typeQualifiers;
        $$ = std::make_shared<Pointer>(typeQualifiers, $2);
    }
    | "*" type_qualifier_list pointer {
        $$ = std::make_shared<Pointer>($2, $3);
    }
    | "*" error pointer {
        // TODO: handle error
    };

direct_declarator
    : "identifier" {
        $$ = std::make_shared<IdentDirectDeclarator>(std::move($1));
    }
    | "(" declarator ")" {
        $$ = std::make_shared<NestedDirectDeclarator>($2);
    }
    | direct_declarator "[" constant_expression "]" {
        $$ = std::make_shared<ArrayDirectDeclarator>($1, $3);
    }
    | direct_declarator "[" "]" {
        $$ = std::make_shared<ArrayDirectDeclarator>($1);
    }
    | direct_declarator "(" parameter_type_list ")" {
        $$ = std::make_shared<ParameterDirectDeclarator>($1, $3);
    }
    | direct_declarator "(" ")" {
        $$ = std::make_shared<ParameterDirectDeclarator>($1);
    }
    | direct_declarator "(" error ")" {
        // TODO: handle error
    }
    | error "(" error ")" {
        // TODO: handle error
    }
    | "(" error ")" {
        // TODO: handle error
    };

parameter_type_list
    : parameter_list {
        $$ = std::make_shared<ParameterTypeList>($1);
    }
    | parameter_list "," "..." {
        $$ = std::make_shared<ParameterTypeList>($1, /*haveEllipsis=*/true);
    }
    | error "," "..." {
        // TODO: handle error
    };

parameter_list
    : parameter_declaration {
        $$ = std::vector{$1};
    }
    | parameter_list "," parameter_declaration {
        ($1).push_back($3);
        $$ = std::move($1);
    }
    | error "," parameter_declaration {
        // TODO: handle error
    };

parameter_declaration
    : declaration_specifiers declarator {
        $$ = std::make_shared<ParameterDeclaration>($1, $2);
    }
    | declaration_specifiers abstract_declarator {
        $$ = std::make_shared<ParameterDeclaration>($1, $2);
    }
    | declaration_specifiers {
        $$ = std::make_shared<ParameterDeclaration>($1);
    };

abstract_declarator
    : pointer {
        $$ = std::make_shared<AbstractDeclarator>($1);
    }
    | direct_abstract_declarator {
        $$ = std::make_shared<AbstractDeclarator>($1);
    }
    | pointer direct_abstract_declarator {
        $$ = std::make_shared<AbstractDeclarator>($2, $1);
    };

direct_abstract_declarator
    : "(" abstract_declarator ")" {
        $$ = std::make_shared<NestedDirectAbstractDeclarator>($2);
    }
    | "[" "]" {
        $$ = std::make_shared<ArrayDirectAbstractDeclarator>();
    }
    | "[" constant_expression "]" {
        $$ = std::make_shared<ArrayDirectAbstractDeclarator>($2);
    }
    | "[" error "]" {
        // TODO: handle error
    }
    | direct_abstract_declarator "[" "]" {
        $$ = std::make_shared<ArrayDirectAbstractDeclarator>($1);
    }
    | direct_abstract_declarator "[" constant_expression "]" {
        $$ = std::make_shared<ArrayDirectAbstractDeclarator>($1, $3);
    }
    | "(" ")" {
        $$ = std::make_shared<ParameterDirectAbstractDeclarator>();
    }
    | "(" parameter_type_list ")" {
        $$ = std::make_shared<ParameterDirectAbstractDeclarator>($2);
    }
    | direct_abstract_declarator "(" ")" {
        $$ = std::make_shared<ParameterDirectAbstractDeclarator>($1);
    }
    | direct_abstract_declarator "(" parameter_type_list ")" {
        $$ = std::make_shared<ParameterDirectAbstractDeclarator>($1, $3);
    }
    | direct_abstract_declarator "(" error ")" {
        // TODO: handle error
    }
    | direct_abstract_declarator "[" error "]" {
        // TODO: handle error
    };

constant_expression
    : conditional_expression {
        $$ = std::make_shared<ConstantExpression>($1);
    };

conditional_expression
    : logical_or_expression {
        $$ = std::make_shared<ConditionalExpression>($1);
    }
    | logical_or_expression "?" expression ":" conditional_expression {
        $$ = std::make_shared<ConditionalExpression>($1, $3, $5);
    }
    | error "?" error ":" conditional_expression {
        // TODO: handle error
    }
    | logical_or_expression "?" error ":" conditional_expression {
        // TODO: handle error
    }
    | error "?" expression ":" conditional_expression {
        // TODO: handle error
    };

logical_or_expression
    : logical_and_expression {
        $$ = std::make_shared<LogicalOrExpression>($1);
    }
    | logical_or_expression "||" logical_and_expression {
        $$ = std::make_shared<LogicalOrExpression>($3, $1);
    };

logical_and_expression
    : inclusive_or_expression {
        $$ = std::make_shared<LogicalAndExpression>($1);
    }
    | logical_and_expression "&&" inclusive_or_expression {
        $$ = std::make_shared<LogicalAndExpression>($3, $1);
    };

inclusive_or_expression
    : exclusive_or_expression {
        $$ = std::make_shared<InclusiveOrExpression>($1);
    }
    | inclusive_or_expression "|" exclusive_or_expression {
        $$ = std::make_shared<InclusiveOrExpression>($3, $1);
    };

exclusive_or_expression
    : and_expression {
        $$ = std::make_shared<ExclusiveOrExpression>($1);
    }
    | exclusive_or_expression "^" and_expression {
        $$ = std::make_shared<ExclusiveOrExpression>($3, $1);
    };

and_expression
    : equality_expression {
        $$ = std::make_shared<AndExpression>($1);
    }
    | and_expression "&" equality_expression {
        $$ = std::make_shared<AndExpression>($3, $1);
    };

equality_expression
    : relational_expression {
        $$ = std::make_shared<EqualityExpression>($1);
    }
    | equality_expression "==" relational_expression {
        $$ = std::make_shared<EqualityExpression>($1, $3, EqualityExpression::Type::kEqual);
    }
    | equality_expression "!=" relational_expression {
        $$ = std::make_shared<EqualityExpression>($1, $3, EqualityExpression::Type::kNotEqual);
    }
    | error "==" relational_expression {
        // TODO: handle error
    }
    | error "!=" relational_expression {
        // TODO: handle error
    };

relational_expression
    : shift_expression {
        $$ = std::make_shared<RelationalExpression>($1);
    }
    | relational_expression "<" shift_expression {
        $$ = std::make_shared<RelationalExpression>($1, $3, RelationalExpression::Type::kLess);
    }
    | relational_expression ">" shift_expression {
        $$ = std::make_shared<RelationalExpression>($1, $3, RelationalExpression::Type::kGreater);
    }
    | relational_expression "<=" shift_expression {
        $$ = std::make_shared<RelationalExpression>($1, $3, RelationalExpression::Type::kLessEq);
    }
    | relational_expression ">=" shift_expression {
        $$ = std::make_shared<RelationalExpression>($1, $3, RelationalExpression::Type::kGreaterEq);
    }
    | error "<" shift_expression {
        // TODO: handle error
    }
    | error ">" shift_expression {
        // TODO: handle error
    }
    | error "<=" shift_expression {
        // TODO: handle error
    }
    | error ">=" shift_expression {
        // TODO: handle error
    };

shift_expression
    : additive_expression {
        $$ = std::make_shared<ShiftExpression>($1);
    }
    | shift_expression "<<" additive_expression {
        $$ = std::make_shared<ShiftExpression>($1, $3, ShiftExpression::Type::kLeft);
    }
    | shift_expression ">>" additive_expression {
        $$ = std::make_shared<ShiftExpression>($1, $3, ShiftExpression::Type::kRight);
    };

additive_expression
    : multiplicative_expression {
        $$ = std::make_shared<AdditiveExpression>($1);
    }
    | additive_expression "+" multiplicative_expression {
        $$ = std::make_shared<AdditiveExpression>($1, $3, AdditiveExpression::Type::kPlus);
    }
    | additive_expression "-" multiplicative_expression {
        $$ = std::make_shared<AdditiveExpression>($1, $3, AdditiveExpression::Type::kMinus);
    }
    | error "+" multiplicative_expression {
        // TODO: handle error
    }
    | error '-' multiplicative_expression {
        // TODO: handle error
    };

multiplicative_expression
    : cast_expression {
        $$ = std::make_shared<MultiplicativeExpression>($1);
    }
    | multiplicative_expression "*" cast_expression {
        $$ = std::make_shared<MultiplicativeExpression>($1, $3, MultiplicativeExpression::Type::kMult);
    }
    | multiplicative_expression "/" cast_expression {
        $$ = std::make_shared<MultiplicativeExpression>($1, $3, MultiplicativeExpression::Type::kDiv);
    }
    | multiplicative_expression "%" cast_expression {
        $$ = std::make_shared<MultiplicativeExpression>($1, $3, MultiplicativeExpression::Type::kMod);
    }
    | error "*" cast_expression {
        // TODO: handle error
    }
    | error "/" cast_expression {
        // TODO: handle error
    }
    | error "%" cast_expression {
        // TODO: handle error
    };

cast_expression
    : unary_expression {
        $$ = std::make_shared<CastUnaryExpression>($1);
    }
    | "(" type_name ")" cast_expression {
        $$ = std::make_shared<CastTypenameExpression>($2, $4);
    };

type_name
    : specifier_qualifier_list {

    }
    | specifier_qualifier_list abstract_declarator {

    };

unary_expression
    : postfix_expression {
        $$ = $1;
    }
    | "++" unary_expression {
        $$ = std::make_shared<IncDecPrefixExpression>($2, IncDecPrefixExpression::Type::kPlus);
    }
    | "--" unary_expression {
        $$ = std::make_shared<IncDecPrefixExpression>($2, IncDecPrefixExpression::Type::kMinus);
    }
    | unary_operator cast_expression {
        $$ = std::make_shared<OperatorUnaryExpression>($1, $2);
    }
    | "sizeof" unary_expression {
        $$ = std::make_shared<SizeofUnaryExpression>($2);
    }
    | "sizeof" "(" type_name ")" {
        $$ = std::make_shared<SizeofTypenameExpression>($3);
    };

unary_operator
    : "&" {
        $$ = std::make_shared<UnaryOperator>(UnaryOperator::Type::kAddress);
    }
    | "*" {
        $$ = std::make_shared<UnaryOperator>(UnaryOperator::Type::kMult);
    }
    | "+" {
        $$ = std::make_shared<UnaryOperator>(UnaryOperator::Type::kPlus);
    }
    | "-" {
        $$ = std::make_shared<UnaryOperator>(UnaryOperator::Type::kMinus);
    }
    | "~" {
        $$ = std::make_shared<UnaryOperator>(UnaryOperator::Type::kLogicalNot);
    }
    | "!" {
        $$ = std::make_shared<UnaryOperator>(UnaryOperator::Type::kNot);
    };

postfix_expression
    : primary_expression {
        $$ = $1;
    }
    | postfix_expression "[" expression "]" {
        $$ = std::make_shared<IndexExpression>($1, $3);
    }
    | postfix_expression "(" ")" {
        $$ = std::make_shared<CallExpression>($1);
    }
    | postfix_expression "(" argument_expression_list ")" {
        $$ = std::make_shared<CallExpression>($1, $3);
    }
    | postfix_expression "." "identifier" {
        $$ = std::make_shared<AccessExpression>($1, std::move($3), AccessExpression::Type::kDot);
    }
    | postfix_expression "->" "identifier" {
        $$ = std::make_shared<AccessExpression>($1, std::move($3), AccessExpression::Type::kArrow);
    }
    | postfix_expression "++" {
        $$ = std::make_shared<IncDecPostfixExpression>($1, IncDecPostfixExpression::Type::kPlus);
    }
    | postfix_expression "--" {
        $$ = std::make_shared<IncDecPostfixExpression>($1, IncDecPostfixExpression::Type::kMinus);
    };

argument_expression_list
    : assignment_expression {
        $$ = std::vector{$1};
    }
    | argument_expression_list "," assignment_expression {
        ($1).push_back($3);
        $$ = std::move($1);
    }
    | error "," assignment_expression {
        // TODO: handle error
    };

primary_expression
    : "identifier" {
        $$ = std::make_shared<IdentPrimaryExpression>(std::move($1));
    }
    | "number" {
        // TODO: real numbers
        $$ = std::make_shared<NumberPrimaryExpression>($1);
    }
    | '(' expression ')' {
        $$ = std::make_shared<NestedPrimaryExpression>($2);
    }
    | '(' error ')' {
        // TODO: handle error
    };
//  | STRING_LITERAL
// TODO: constants

expression
    : assignment_expression {
        $$ = std::make_shared<Expression>($1);
    }
    | expression "," assignment_expression {
        $$ = std::make_shared<Expression>($3, $1);
    };

assignment_expression
    : conditional_expression {
        $$ = std::make_shared<ConditionalAssignmentExpression>($1);
    }
    | unary_expression assignment_operator assignment_expression {
        $$ = std::make_shared<UnaryAssignExpression>($1, $2, $3);
    };

assignment_operator
    : "=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kAssign);
    }
    | "*=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kMulAssign);
    }
    | "/=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kDivAssign);
    }
    | "%=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kModAssign);
    }
    | "+=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kPlusAssign);
    }
    | "-=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kMinusAssign);
    }
    | "<<=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kShiftLeftAssign);
    }
    | ">>=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kShiftRightAssign);
    }
    | "&=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kLogicalAndAssign);
    }
    | "^=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kXorAssign);
    }
    | "|=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kLogicalOrAssign);
    };

compound_statement
    : "{" "}" {
        $$ = std::make_shared<CompoundStatement>();
    }
    | "{" statement_list "}" {
        $$ = std::make_shared<CompoundStatement>($2);
    }
    | "{" declaration_list "}" {
        $$ = std::make_shared<CompoundStatement>($2);
    }
    | "{" declaration_list statement_list "}" {
        $$ = std::make_shared<CompoundStatement>($2, $3);
    }
    | "{" error "}" {
        // TODO: handle error
    };

declaration_list
    : declaration {
        $$ = std::vector{$1};
    }
    | declaration_list declaration {
        ($1).push_back($2);
        $$ = std::move($1);
    };

declaration
    : declaration_specifiers ";" {
        $$ = std::make_shared<Declaration>($1);
    }
    | declaration_specifiers init_declarator_list ";" {
        $$ = std::make_shared<Declaration>($1, $2);
    }
    | declaration_specifiers init_declarator_list "=" assignment_expression ";" {
        $$ = std::make_shared<Declaration>($1, $2, $4);
    }
    | declaration_specifiers error ";" {
        // TODO: handle error
    };

init_declarator_list
    : init_declarator {
        $$ = std::vector{$1};
    }
    | init_declarator_list "," init_declarator {
        ($1).push_back($3);
        $$ = std::move($1);
    }
    | error "," init_declarator {
        // TODO: handle error
    };

init_declarator
    : declarator "=" initializer {
        $$ = std::make_shared<InitDeclarator>($1, $3);
    }
    | declarator {
        $$ = std::make_shared<InitDeclarator>($1);
    }
    | error "=" initializer {
        // TODO: handle error
    };

initializer
    : assignment_expression {
        $$ = std::make_shared<ExpressionInitializer>($1);
    }
    | "{" initializer_list "}" {
        $$ = std::make_shared<InitializerList>($2);
    }
    | "{" initializer_list "," "}" {
        $$ = std::make_shared<InitializerList>($2);
    }
    | "{" error "}" {
        // TODO: handle error
    };

initializer_list
    : initializer {
        $$ = std::vector{$1};
    }
    | initializer_list "," initializer {
        ($1).push_back($3);
        $$ = std::move($1);
    }
    | error "," initializer {
        // TODO: handle error
    };

statement_list
    : statement {
        $$ = std::vector{$1};
    }
    | statement_list statement {
        ($1).push_back($2);
        $$ = std::move($1);
    };

statement
    : labeled_statement {
        $$ = $1;
    }
    | compound_statement {
        $$ = $1;
    }
    | expression_statement {
        $$ = $1;
    }
    | selection_statement {
        $$ = $1;
    }
    | iteration_statement {
        $$ = $1;
    }
    | jump_statement {
        $$ = $1;
    };

labeled_statement
    : "identifier" ":" statement {
        $$ = std::make_shared<IdentLabeledStatement>(std::move($1), $3);
    }
    | "case" constant_expression ":" statement {
        $$ = std::make_shared<CaseLabeledStatement>($2, $4);
    }
    | "default" ":" statement {
        $$ = std::make_shared<DefaultLabeledStatement>($3);
    };

expression_statement
    : error ";" {
        // TODO: handle error
    }
    | expression ";" {
        $$ = std::make_shared<ExpressionStatement>($1);
    };

selection_statement
    : "if" "(" expression ")" statement {
        $$ = std::make_shared<IfSelectionStatement>($3, $5);
    }
    | "if" "(" expression ")" statement "else" statement {
        $$ = std::make_shared<IfSelectionStatement>($3, $5, $7);
    }
    | "switch" "(" expression ")" statement {
        $$ = std::make_shared<SwitchSelectionStatement>($3, $5);
    }
    | "if" "(" error ")" statement {
        // TODO: handle error
    }
    | "if" "(" error ")" statement "else" statement {
        // TODO: handle error
    }
    | "switch" "(" error ")" statement {
        // TODO: handle error
    };

iteration_statement
    : "while" "(" expression ")" statement {
        $$ = std::make_shared<WhileIterationStatement>($3, $5);
    }
    | "do" statement "while" "(" expression ")" ";" {
        $$ = std::make_shared<DoWhileIterationStatement>($5, $2);
    }
    | "for" "(" expression_statement expression_statement ")" statement {
        $$ = std::make_shared<ForIterationStatement>($6, $3, $4);
    }
    | "for" "(" expression_statement expression_statement expression ")" statement {
        $$ = std::make_shared<ForIterationStatement>($7, $3, $4, $5);
    }
    | "do" error "while" "(" expression ")" ";" {
        // TODO: handle error
    }
    | "for" "(" error ")" statement {
        // TODO: handle error
    };

jump_statement
    : "goto" "identifier" ";" {

    }
    | "continue" ";" {
        $$ = std::make_shared<LoopJumpStatement>(LoopJumpStatement::Type::kContinue);
    }
    | "break" ";" {
        $$ = std::make_shared<LoopJumpStatement>(LoopJumpStatement::Type::kBreak);
    }
    | "return" ";" {
        $$ = std::make_shared<ReturnJumpStatement>();
    }
    | "return" expression ";" {
        $$ = std::make_shared<ReturnJumpStatement>($2);
    }
    | "return" error ";" {
        // TODO: handle error
    };

ident_specifier
    : "identifier" {
        $$ = std::make_shared<IdentSpecifier>(std::move($1));
    };

%%

void yy::parser::error(const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
}
