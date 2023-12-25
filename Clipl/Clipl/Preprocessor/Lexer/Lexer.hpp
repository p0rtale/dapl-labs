#pragma once

// #if !defined(yyFlexLexerOnce)
#define yyFlexLexer preFlexLexer
#include <FlexLexer.h>
#undef yyFlexLexer
// #endif

#include <Clipl/Preprocessor/Lexer/LexerInternal.hpp>
