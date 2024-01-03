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

%nterm <RefT<Program>> program;
%nterm <std::vector<RefT<ExternalDeclaration>>> translation_unit;
%nterm <RefT<ExternalDeclaration>> external_declaration;
%nterm <RefT<FunctionDefinition>> function_definition;
%nterm <RefT<DeclarationSpecifiers>> declaration_specifiers;
%nterm <RefT<IdentDeclarationSpecifiers>> ident_specifier_list;
%nterm <RefT<IdentSpecifier>> ident_specifier;
%nterm <RefT<KeywordSpecifier>> keyword_specifier;
%nterm <RefT<KeywordDeclarationSpecifiers>> keyword_specifier_list;
%nterm <RefT<Specifier>> specifier;
%nterm <std::vector<RefT<Specifier>>> specifier_list;
%nterm <RefT<StorageClassSpecifier>> storage_class_specifier;
%nterm <RefT<TypeQualifier>> type_qualifier;
%nterm <std::vector<RefT<TypeQualifier>>> type_qualifier_list;
%nterm <RefT<Declarator>> declarator;
%nterm <RefT<Pointer>> pointer;
%nterm <RefT<DirectDeclarator>> direct_declarator;
%nterm <RefT<ParameterTypeList>> parameter_type_list;
%nterm <std::vector<RefT<ParameterDeclaration>>> parameter_list;
%nterm <RefT<ParameterDeclaration>> parameter_declaration;
%nterm <RefT<AbstractDeclarator>> abstract_declarator;
%nterm <RefT<DirectAbstractDeclarator>> direct_abstract_declarator;
%nterm <RefT<ConstantExpression>> constant_expression;
%nterm <RefT<ConditionalExpression>> conditional_expression;
%nterm <RefT<LogicalOrExpression>> logical_or_expression;
%nterm <RefT<LogicalAndExpression>> logical_and_expression;
%nterm <RefT<InclusiveOrExpression>> inclusive_or_expression;
%nterm <RefT<ExclusiveOrExpression>> exclusive_or_expression;
%nterm <RefT<AndExpression>> and_expression;
%nterm <RefT<EqualityExpression>> equality_expression;
%nterm <RefT<RelationalExpression>> relational_expression;
%nterm <RefT<ShiftExpression>> shift_expression;
%nterm <RefT<AdditiveExpression>> additive_expression;
%nterm <RefT<MultiplicativeExpression>> multiplicative_expression;
%nterm <RefT<CastExpression>> cast_expression;
%nterm <RefT<TypeName>> type_name;
%nterm <RefT<SpecifierQualifierList>> specifier_qualifier_list;
%nterm <RefT<UnaryExpression>> unary_expression;
%nterm <RefT<UnaryOperator>> unary_operator;
%nterm <RefT<PostfixExpression>> postfix_expression;
%nterm <std::vector<RefT<AssignmentExpression>>> argument_expression_list;
%nterm <RefT<PrimaryExpression>> primary_expression;
%nterm <RefT<Expression>> expression;
%nterm <RefT<AssignmentExpression>> assignment_expression;
%nterm <RefT<AssignmentOperator>> assignment_operator;
%nterm <RefT<CompoundStatement>> compound_statement;
%nterm <std::vector<RefT<Declaration>>> declaration_list;
%nterm <RefT<Declaration>> declaration;
%nterm <std::vector<RefT<InitDeclarator>>> init_declarator_list;
%nterm <RefT<InitDeclarator>> init_declarator;
%nterm <std::vector<RefT<Initializer>>> initializer_list;
%nterm <RefT<Initializer>> initializer;
%nterm <std::vector<RefT<Statement>>> statement_list;
%nterm <RefT<Statement>> statement;
%nterm <RefT<LabeledStatement>> labeled_statement;
%nterm <RefT<ExpressionStatement>> expression_statement;
%nterm <RefT<SelectionStatement>> selection_statement;
%nterm <RefT<IterationStatement>> iteration_statement;
%nterm <RefT<JumpStatement>> jump_statement;

%nterm <RefT<Enumerator>> enumerator;
%nterm <std::vector<RefT<Enumerator>>> enumerator_list;
%nterm <RefT<EnumSpecifier>> enum_specifier;

%nterm <StructOrUnionType> struct_or_union;

%nterm <RefT<StructOrUnionSpecifier>> struct_or_union_specifier;
%nterm <RefT<StructDeclaration>> struct_declaration;
%nterm <std::vector<RefT<StructDeclaration>>> struct_declaration_list;
%nterm <RefT<StructDeclarator>> struct_declarator;
%nterm <std::vector<RefT<StructDeclarator>>> struct_declarator_list;


// Prints output in parsing option for debugging location terminal
// %printer { yyo << $$; } <*>;

%%

%start program;

program
    : translation_unit {
        $$ = CreateRef<Program>(std::move($1));
        driver.setAST(std::move($$));
    }

translation_unit
    : external_declaration {
        $$ = std::vector{$1};
    }
    | external_declaration translation_unit {
        ($2).push_back($1);
        $$ = std::move($2);
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
        $$ = CreateRef<FunctionDefinition>($1, $2, $3);
    }
    | declaration_specifiers error compound_statement {
        // TODO: handle error
        YYABORT;
    }
    | error compound_statement {
        // TODO: handle error
        YYABORT;
    };

declaration_specifiers
    : specifier declaration_specifiers {
        ($2)->AddSpecifier($1);
        $$ = $2;
    }
    | keyword_specifier_list {
        $$ = std::static_pointer_cast<DeclarationSpecifiers>($1);
    }
    | ident_specifier_list {
        $$ = std::static_pointer_cast<DeclarationSpecifiers>($1);
    };

specifier_qualifier_list
    : keyword_specifier specifier_qualifier_list {
        ($2)->AddKeywordSpecifier($1);
        $$ = $2; 
    }
    | keyword_specifier {
        $$ = CreateRef<SpecifierQualifierList>($1);
    }
    | ident_specifier specifier_qualifier_list {
        ($2)->AddIdentSpecifier($1);
        $$ = $2; 
    }
    | ident_specifier {
        $$ = CreateRef<SpecifierQualifierList>($1);
    }
    | type_qualifier specifier_qualifier_list {
        ($2)->AddTypeQualifier($1);
        $$ = $2; 
    }
    | type_qualifier {
        $$ = CreateRef<SpecifierQualifierList>($1);
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
        $$ = CreateRef<KeywordDeclarationSpecifiers>($1);
    }
    | keyword_specifier_list keyword_specifier {
        auto keywordSpecifierList = $1;
        keywordSpecifierList->AddKeywordSpecifier($2);
        $$ = keywordSpecifierList;
    }
    | keyword_specifier_list specifier {
        auto keywordSpecifierList = $1;
        keywordSpecifierList->AddSpecifier($2);
        $$ = keywordSpecifierList;
    };

ident_specifier_list
    : ident_specifier {
        $$ = CreateRef<IdentDeclarationSpecifiers>($1);
    }
    | ident_specifier specifier_list {
        $$ = CreateRef<IdentDeclarationSpecifiers>($1, $2);  
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
        $$ = CreateRef<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kVoid);
    }
    | "char" {
        $$ = CreateRef<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kChar);
    }
    | "short" {
        $$ = CreateRef<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kShort);
    }
    | "int" {
        $$ = CreateRef<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kInt);
    }
    | "long" {
        $$ = CreateRef<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kLong);
    }
    | "float" {
        $$ = CreateRef<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kFloat);
    }
    | "double" {
        $$ = CreateRef<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kDouble);
    }
    | "signed" {
        $$ = CreateRef<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kSigned);
    }
    | "unsigned" {
        $$ = CreateRef<BasicKeywordSpecifier>(BasicKeywordSpecifier::Type::kUnsigned);
    }
    | struct_or_union_specifier {
        $$ = $1;
    }
    | enum_specifier {
        $$ = $1;
    };

struct_or_union_specifier
    : struct_or_union "identifier" '{' struct_declaration_list '}' {
        $$ = CreateRef<StructOrUnionSpecifier>($1, std::move($2), $4);
    }
    | struct_or_union '{' struct_declaration_list '}' {
        $$ = CreateRef<StructOrUnionSpecifier>($1, "", $3);
    }
    | struct_or_union "identifier" {
        $$ = CreateRef<StructOrUnionSpecifier>($1, std::move($2));
    }
    | struct_or_union "identifier" '{' error '}' {
        // TODO: handle
    }
    | struct_or_union '{' error '}' {
        // TODO: handle error
        YYABORT;
    };

struct_or_union
    : "struct" {
        $$ = StructOrUnionType::kStruct;
    }
    | "union" {
        $$ = StructOrUnionType::kUnion;
    };

struct_declaration_list
    : struct_declaration {
        $$ = std::vector{$1};
    }
    | struct_declaration_list struct_declaration {
        ($1).push_back($2);
        $$ = std::move($1);
    };

struct_declaration
    : specifier_qualifier_list struct_declarator_list ';' {
        $$ = CreateRef<StructDeclaration>($1, $2);
    }
    | error ';' {
        // TODO: handle error
        YYABORT;
    };

struct_declarator_list
    : struct_declarator {
        $$ = std::vector{$1};
    }
    | struct_declarator_list ',' struct_declarator {
        ($1).push_back($3);
        $$ = std::move($1);
    }
    | error ',' struct_declarator {
        // TODO: handle error
        YYABORT;
    };

struct_declarator
    : declarator {
        $$ = CreateRef<StructDeclarator>($1);
    };

enum_specifier
    : "enum" '{' enumerator_list '}' {
        $$ = CreateRef<EnumSpecifier>("", $3);
    }
    | "enum" "identifier" '{' enumerator_list '}' {
        $$ = CreateRef<EnumSpecifier>($2, $4);
    }
    | "enum" '{' error '}' {
        // TODO: handle error
        YYABORT;
    }
    | "enum" "identifier" '{' error '}' {
        // TODO: handle error
        YYABORT;
    }
    | "enum" "identifier" {
        $$ = CreateRef<EnumSpecifier>($2);
    };

enumerator_list
    : enumerator {
        $$ = std::vector{$1};
    }
    | enumerator_list ',' enumerator {
        ($1).push_back($3);
        $$ = std::move($1);
    }
    | error ',' enumerator {
        // TODO: handle error
        YYABORT;
    };

enumerator
    : "identifier" {
        $$ = CreateRef<Enumerator>($1);
    }
    | "identifier" '=' constant_expression {
        $$ = CreateRef<Enumerator>($1, $3);
    }
    | error '=' constant_expression {
        // TODO: handle error
        YYABORT;
    };

storage_class_specifier
    : "typedef" {
        $$ = CreateRef<StorageClassSpecifier>(StorageClassSpecifier::Type::kTypedef);
    }
    | "extern" {
        $$ = CreateRef<StorageClassSpecifier>(StorageClassSpecifier::Type::kExtern);
    }
    | "static" {
        $$ = CreateRef<StorageClassSpecifier>(StorageClassSpecifier::Type::kStatic);
    };

type_qualifier
    : "const" {
        $$ = CreateRef<TypeQualifier>(TypeQualifier::Type::kConst);
    }
    | "volatile" {
        $$ = CreateRef<TypeQualifier>(TypeQualifier::Type::kVolatile);
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
        $$ = CreateRef<Declarator>($2, $1);
    }
    | direct_declarator {
        $$ = CreateRef<Declarator>($1);
    };

pointer
    : "*" {
        $$ = CreateRef<Pointer>();
    }
    | "*" type_qualifier_list {
        $$ = CreateRef<Pointer>($2);
    }
    | "*" pointer {
        std::vector<RefT<TypeQualifier>> typeQualifiers;
        $$ = CreateRef<Pointer>(typeQualifiers, $2);
    }
    | "*" type_qualifier_list pointer {
        $$ = CreateRef<Pointer>($2, $3);
    }
    | "*" error pointer {
        // TODO: handle error
        YYABORT;
    };

direct_declarator
    : "identifier" {
        $$ = CreateRef<IdentDirectDeclarator>(std::move($1));
    }
    | "(" declarator ")" {
        $$ = CreateRef<NestedDirectDeclarator>($2);
    }
    | direct_declarator "[" constant_expression "]" {
        $$ = CreateRef<ArrayDirectDeclarator>($1, $3);
    }
    | direct_declarator "[" "]" {
        $$ = CreateRef<ArrayDirectDeclarator>($1);
    }
    | direct_declarator "(" parameter_type_list ")" {
        $$ = CreateRef<ParameterDirectDeclarator>($1, $3);
    }
    | direct_declarator "(" ")" {
        $$ = CreateRef<ParameterDirectDeclarator>($1);
    }
    | direct_declarator "(" error ")" {
        // TODO: handle error
        YYABORT;
    }
    | error "(" error ")" {
        // TODO: handle error
        YYABORT;
    }
    | "(" error ")" {
        // TODO: handle error
        YYABORT;
    };

parameter_type_list
    : parameter_list {
        $$ = CreateRef<ParameterTypeList>($1);
    }
    | parameter_list "," "..." {
        $$ = CreateRef<ParameterTypeList>($1, /*haveEllipsis=*/true);
    }
    | error "," "..." {
        // TODO: handle error
        YYABORT;
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
        YYABORT;
    };

parameter_declaration
    : declaration_specifiers declarator {
        $$ = CreateRef<ParameterDeclaration>($1, $2);
    }
    | declaration_specifiers abstract_declarator {
        $$ = CreateRef<ParameterDeclaration>($1, $2);
    }
    | declaration_specifiers {
        $$ = CreateRef<ParameterDeclaration>($1);
    };

abstract_declarator
    : pointer {
        $$ = CreateRef<AbstractDeclarator>($1);
    }
    | direct_abstract_declarator {
        $$ = CreateRef<AbstractDeclarator>($1);
    }
    | pointer direct_abstract_declarator {
        $$ = CreateRef<AbstractDeclarator>($2, $1);
    };

direct_abstract_declarator
    : "(" abstract_declarator ")" {
        $$ = CreateRef<NestedDirectAbstractDeclarator>($2);
    }
    | "[" "]" {
        $$ = CreateRef<ArrayDirectAbstractDeclarator>();
    }
    | "[" constant_expression "]" {
        $$ = CreateRef<ArrayDirectAbstractDeclarator>($2);
    }
    | "[" error "]" {
        // TODO: handle error
        YYABORT;
    }
    | direct_abstract_declarator "[" "]" {
        $$ = CreateRef<ArrayDirectAbstractDeclarator>($1);
    }
    | direct_abstract_declarator "[" constant_expression "]" {
        $$ = CreateRef<ArrayDirectAbstractDeclarator>($1, $3);
    }
    | "(" ")" {
        $$ = CreateRef<ParameterDirectAbstractDeclarator>();
    }
    | "(" parameter_type_list ")" {
        $$ = CreateRef<ParameterDirectAbstractDeclarator>($2);
    }
    | direct_abstract_declarator "(" ")" {
        $$ = CreateRef<ParameterDirectAbstractDeclarator>($1);
    }
    | direct_abstract_declarator "(" parameter_type_list ")" {
        $$ = CreateRef<ParameterDirectAbstractDeclarator>($1, $3);
    }
    | direct_abstract_declarator "(" error ")" {
        // TODO: handle error
        YYABORT;
    }
    | direct_abstract_declarator "[" error "]" {
        // TODO: handle error
        YYABORT;
    };

constant_expression
    : conditional_expression {
        $$ = CreateRef<ConstantExpression>($1);
    };

conditional_expression
    : logical_or_expression {
        $$ = CreateRef<ConditionalExpression>($1);
    }
    | logical_or_expression "?" expression ":" conditional_expression {
        $$ = CreateRef<ConditionalExpression>($1, $3, $5);
    }
    | error "?" error ":" conditional_expression {
        // TODO: handle error
        YYABORT;
    }
    | logical_or_expression "?" error ":" conditional_expression {
        // TODO: handle error
        YYABORT;
    }
    | error "?" expression ":" conditional_expression {
        // TODO: handle error
        YYABORT;
    };

logical_or_expression
    : logical_and_expression {
        $$ = CreateRef<LogicalOrExpression>($1);
    }
    | logical_or_expression "||" logical_and_expression {
        $$ = CreateRef<LogicalOrExpression>($3, $1);
    };

logical_and_expression
    : inclusive_or_expression {
        $$ = CreateRef<LogicalAndExpression>($1);
    }
    | logical_and_expression "&&" inclusive_or_expression {
        $$ = CreateRef<LogicalAndExpression>($3, $1);
    };

inclusive_or_expression
    : exclusive_or_expression {
        $$ = CreateRef<InclusiveOrExpression>($1);
    }
    | inclusive_or_expression "|" exclusive_or_expression {
        $$ = CreateRef<InclusiveOrExpression>($3, $1);
    };

exclusive_or_expression
    : and_expression {
        $$ = CreateRef<ExclusiveOrExpression>($1);
    }
    | exclusive_or_expression "^" and_expression {
        $$ = CreateRef<ExclusiveOrExpression>($3, $1);
    };

and_expression
    : equality_expression {
        $$ = CreateRef<AndExpression>($1);
    }
    | and_expression "&" equality_expression {
        $$ = CreateRef<AndExpression>($3, $1);
    };

equality_expression
    : relational_expression {
        $$ = CreateRef<EqualityExpression>($1);
    }
    | equality_expression "==" relational_expression {
        $$ = CreateRef<EqualityExpression>($1, $3, EqualityExpression::Type::kEqual);
    }
    | equality_expression "!=" relational_expression {
        $$ = CreateRef<EqualityExpression>($1, $3, EqualityExpression::Type::kNotEqual);
    }
    | error "==" relational_expression {
        // TODO: handle error
        YYABORT;
    }
    | error "!=" relational_expression {
        // TODO: handle error
        YYABORT;
    };

relational_expression
    : shift_expression {
        $$ = CreateRef<RelationalExpression>($1);
    }
    | relational_expression "<" shift_expression {
        $$ = CreateRef<RelationalExpression>($1, $3, RelationalExpression::Type::kLess);
    }
    | relational_expression ">" shift_expression {
        $$ = CreateRef<RelationalExpression>($1, $3, RelationalExpression::Type::kGreater);
    }
    | relational_expression "<=" shift_expression {
        $$ = CreateRef<RelationalExpression>($1, $3, RelationalExpression::Type::kLessEq);
    }
    | relational_expression ">=" shift_expression {
        $$ = CreateRef<RelationalExpression>($1, $3, RelationalExpression::Type::kGreaterEq);
    }
    | error "<" shift_expression {
        // TODO: handle error
        YYABORT;
    }
    | error ">" shift_expression {
        // TODO: handle error
        YYABORT;
    }
    | error "<=" shift_expression {
        // TODO: handle error
        YYABORT;
    }
    | error ">=" shift_expression {
        // TODO: handle error
        YYABORT;
    };

shift_expression
    : additive_expression {
        $$ = CreateRef<ShiftExpression>($1);
    }
    | shift_expression "<<" additive_expression {
        $$ = CreateRef<ShiftExpression>($1, $3, ShiftExpression::Type::kLeft);
    }
    | shift_expression ">>" additive_expression {
        $$ = CreateRef<ShiftExpression>($1, $3, ShiftExpression::Type::kRight);
    };

additive_expression
    : multiplicative_expression {
        $$ = CreateRef<AdditiveExpression>($1);
    }
    | additive_expression "+" multiplicative_expression {
        $$ = CreateRef<AdditiveExpression>($1, $3, AdditiveExpression::Type::kPlus);
    }
    | additive_expression "-" multiplicative_expression {
        $$ = CreateRef<AdditiveExpression>($1, $3, AdditiveExpression::Type::kMinus);
    }
    | error "+" multiplicative_expression {
        // TODO: handle error
        YYABORT;
    }
    | error '-' multiplicative_expression {
        // TODO: handle error
        YYABORT;
    };

multiplicative_expression
    : cast_expression {
        $$ = CreateRef<MultiplicativeExpression>($1);
    }
    | multiplicative_expression "*" cast_expression {
        $$ = CreateRef<MultiplicativeExpression>($1, $3, MultiplicativeExpression::Type::kMult);
    }
    | multiplicative_expression "/" cast_expression {
        $$ = CreateRef<MultiplicativeExpression>($1, $3, MultiplicativeExpression::Type::kDiv);
    }
    | multiplicative_expression "%" cast_expression {
        $$ = CreateRef<MultiplicativeExpression>($1, $3, MultiplicativeExpression::Type::kMod);
    }
    | error "*" cast_expression {
        // TODO: handle error
        YYABORT;
    }
    | error "/" cast_expression {
        // TODO: handle error
        YYABORT;
    }
    | error "%" cast_expression {
        // TODO: handle error
        YYABORT;
    };

cast_expression
    : unary_expression {
        $$ = CreateRef<CastUnaryExpression>($1);
    }
    | "(" type_name ")" cast_expression {
        $$ = CreateRef<CastTypenameExpression>($2, $4);
    };

type_name
    : specifier_qualifier_list {
        $$ = CreateRef<TypeName>($1);
    }
    | specifier_qualifier_list abstract_declarator {
        $$ = CreateRef<TypeName>($1, $2);
    };

unary_expression
    : postfix_expression {
        $$ = $1;
    }
    | "++" unary_expression {
        $$ = CreateRef<IncDecPrefixExpression>($2, IncDecPrefixExpression::Type::kPlus);
    }
    | "--" unary_expression {
        $$ = CreateRef<IncDecPrefixExpression>($2, IncDecPrefixExpression::Type::kMinus);
    }
    | unary_operator cast_expression {
        $$ = CreateRef<OperatorUnaryExpression>($1, $2);
    }
    | "sizeof" unary_expression {
        $$ = CreateRef<SizeofUnaryExpression>($2);
    }
    | "sizeof" "(" type_name ")" {
        $$ = CreateRef<SizeofTypenameExpression>($3);
    };

unary_operator
    : "&" {
        $$ = CreateRef<UnaryOperator>(UnaryOperator::Type::kAddress);
    }
    | "*" {
        $$ = CreateRef<UnaryOperator>(UnaryOperator::Type::kMult);
    }
    | "+" {
        $$ = CreateRef<UnaryOperator>(UnaryOperator::Type::kPlus);
    }
    | "-" {
        $$ = CreateRef<UnaryOperator>(UnaryOperator::Type::kMinus);
    }
    | "~" {
        $$ = CreateRef<UnaryOperator>(UnaryOperator::Type::kLogicalNot);
    }
    | "!" {
        $$ = CreateRef<UnaryOperator>(UnaryOperator::Type::kNot);
    };

postfix_expression
    : primary_expression {
        $$ = $1;
    }
    | postfix_expression "[" expression "]" {
        $$ = CreateRef<IndexExpression>($1, $3);
    }
    | postfix_expression "(" ")" {
        $$ = CreateRef<CallExpression>($1);
    }
    | postfix_expression "(" argument_expression_list ")" {
        $$ = CreateRef<CallExpression>($1, $3);
    }
    | postfix_expression "." "identifier" {
        $$ = CreateRef<AccessExpression>($1, std::move($3), AccessExpression::Type::kDot);
    }
    | postfix_expression "->" "identifier" {
        $$ = CreateRef<AccessExpression>($1, std::move($3), AccessExpression::Type::kArrow);
    }
    | postfix_expression "++" {
        $$ = CreateRef<IncDecPostfixExpression>($1, IncDecPostfixExpression::Type::kPlus);
    }
    | postfix_expression "--" {
        $$ = CreateRef<IncDecPostfixExpression>($1, IncDecPostfixExpression::Type::kMinus);
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
        YYABORT;
    };

primary_expression
    : "identifier" {
        $$ = CreateRef<IdentPrimaryExpression>(std::move($1));
    }
    | "number" {
        // TODO: real numbers
        $$ = CreateRef<NumberPrimaryExpression>($1);
    }
    | '(' expression ')' {
        $$ = CreateRef<NestedPrimaryExpression>($2);
    }
    | '(' error ')' {
        // TODO: handle error
        YYABORT;
    };
//  | STRING_LITERAL
// TODO: constants

expression
    : assignment_expression {
        $$ = CreateRef<Expression>($1);
    }
    | expression "," assignment_expression {
        $$ = CreateRef<Expression>($3, $1);
    };

assignment_expression
    : conditional_expression {
        $$ = CreateRef<ConditionalAssignmentExpression>($1);
    }
    | unary_expression assignment_operator assignment_expression {
        $$ = CreateRef<UnaryAssignExpression>($1, $2, $3);
    };

assignment_operator
    : "=" {
        $$ = CreateRef<AssignmentOperator>(AssignmentOperator::Type::kAssign);
    }
    | "*=" {
        $$ = CreateRef<AssignmentOperator>(AssignmentOperator::Type::kMulAssign);
    }
    | "/=" {
        $$ = CreateRef<AssignmentOperator>(AssignmentOperator::Type::kDivAssign);
    }
    | "%=" {
        $$ = CreateRef<AssignmentOperator>(AssignmentOperator::Type::kModAssign);
    }
    | "+=" {
        $$ = CreateRef<AssignmentOperator>(AssignmentOperator::Type::kPlusAssign);
    }
    | "-=" {
        $$ = CreateRef<AssignmentOperator>(AssignmentOperator::Type::kMinusAssign);
    }
    | "<<=" {
        $$ = CreateRef<AssignmentOperator>(AssignmentOperator::Type::kShiftLeftAssign);
    }
    | ">>=" {
        $$ = CreateRef<AssignmentOperator>(AssignmentOperator::Type::kShiftRightAssign);
    }
    | "&=" {
        $$ = CreateRef<AssignmentOperator>(AssignmentOperator::Type::kLogicalAndAssign);
    }
    | "^=" {
        $$ = CreateRef<AssignmentOperator>(AssignmentOperator::Type::kXorAssign);
    }
    | "|=" {
        $$ = CreateRef<AssignmentOperator>(AssignmentOperator::Type::kLogicalOrAssign);
    };

compound_statement
    : "{" "}" {
        $$ = CreateRef<CompoundStatement>();
    }
    | "{" statement_list "}" {
        $$ = CreateRef<CompoundStatement>($2);
    }
    | "{" declaration_list "}" {
        $$ = CreateRef<CompoundStatement>($2);
    }
    | "{" declaration_list statement_list "}" {
        $$ = CreateRef<CompoundStatement>($2, $3);
    }
    | "{" error "}" {
        // TODO: handle error
        YYABORT;
        $$ = CreateRef<CompoundStatement>();
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
        $$ = CreateRef<Declaration>($1);
    }
    | declaration_specifiers init_declarator_list ";" {
        $$ = CreateRef<Declaration>($1, $2);
    }
    | declaration_specifiers init_declarator_list "=" assignment_expression ";" {
        $$ = CreateRef<Declaration>($1, $2, $4);
    }
    | declaration_specifiers error ";" {
        // TODO: handle error
        YYABORT;
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
        YYABORT;
    };

init_declarator
    : declarator "=" initializer {
        $$ = CreateRef<InitDeclarator>($1, $3);
    }
    | declarator {
        $$ = CreateRef<InitDeclarator>($1);
    }
    | error "=" initializer {
        // TODO: handle error
        YYABORT;
    };

initializer
    : assignment_expression {
        $$ = CreateRef<ExpressionInitializer>($1);
    }
    | "{" initializer_list "}" {
        $$ = CreateRef<InitializerList>($2);
    }
    | "{" initializer_list "," "}" {
        $$ = CreateRef<InitializerList>($2);
    }
    | "{" error "}" {
        // TODO: handle error
        YYABORT;
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
        YYABORT;
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
        $$ = CreateRef<IdentLabeledStatement>(std::move($1), $3);
    }
    | "case" constant_expression ":" statement {
        $$ = CreateRef<CaseLabeledStatement>($2, $4);
    }
    | "default" ":" statement {
        $$ = CreateRef<DefaultLabeledStatement>($3);
    };

expression_statement
    : error ";" {
        // TODO: handle error
        YYABORT;
    }
    | expression ";" {
        $$ = CreateRef<ExpressionStatement>($1);
    };

selection_statement
    : "if" "(" expression ")" statement {
        $$ = CreateRef<IfSelectionStatement>($3, $5);
    }
    | "if" "(" expression ")" statement "else" statement {
        $$ = CreateRef<IfSelectionStatement>($3, $5, $7);
    }
    | "switch" "(" expression ")" statement {
        $$ = CreateRef<SwitchSelectionStatement>($3, $5);
    }
    | "if" "(" error ")" statement {
        // TODO: handle error
        YYABORT;
    }
    | "if" "(" error ")" statement "else" statement {
        // TODO: handle error
        YYABORT;
    }
    | "switch" "(" error ")" statement {
        // TODO: handle error
        YYABORT;
    };

iteration_statement
    : "while" "(" expression ")" statement {
        $$ = CreateRef<WhileIterationStatement>($3, $5);
    }
    | "do" statement "while" "(" expression ")" ";" {
        $$ = CreateRef<DoWhileIterationStatement>($5, $2);
    }
    | "for" "(" expression_statement expression_statement ")" statement {
        $$ = CreateRef<ForIterationStatement>($6, $3, $4);
    }
    | "for" "(" expression_statement expression_statement expression ")" statement {
        $$ = CreateRef<ForIterationStatement>($7, $3, $4, $5);
    }
    | "do" error "while" "(" expression ")" ";" {
        // TODO: handle error
        YYABORT;
    }
    | "for" "(" error ")" statement {
        // TODO: handle error
        YYABORT;
    };

jump_statement
    : "goto" "identifier" ";" {

    }
    | "continue" ";" {
        $$ = CreateRef<LoopJumpStatement>(LoopJumpStatement::Type::kContinue);
    }
    | "break" ";" {
        $$ = CreateRef<LoopJumpStatement>(LoopJumpStatement::Type::kBreak);
    }
    | "return" ";" {
        $$ = CreateRef<ReturnJumpStatement>();
    }
    | "return" expression ";" {
        $$ = CreateRef<ReturnJumpStatement>($2);
    }
    | "return" error ";" {
        // TODO: handle error
        YYABORT;
    };

ident_specifier
    : "identifier" {
        $$ = CreateRef<IdentSpecifier>(std::move($1));
    };

%%

void yy::parser::error(const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
}
