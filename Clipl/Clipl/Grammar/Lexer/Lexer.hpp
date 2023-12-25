#pragma once

// #if !defined(yyFlexLexerOnce)
#define yyFlexLexer cliplFlexLexer
#include <FlexLexer.h>
#undef yyFlexLexer
// #endif

#include <Clipl/Grammar/Lexer/LexerInternal.hpp>
