/*
	Test tokenizer
*/

#pragma once

#include <gtest/gtest.h>

#include "utils.h"
#include "wl/Tokenizer.h"

TEST(WLtest, tokenizer)
{
	auto stream(wrapStream("var c:=10*20+1;var b := c == 201;"));
	Tokenizer tok(stream);

	ASSERT_EQ(TokenCode::TOKEN_VAR,        tok.next().code); //var
	ASSERT_EQ(TokenCode::TOKEN_IDENTIFIER, tok.next().code); //c
	ASSERT_EQ(TokenCode::TOKEN_ASSIGN,     tok.next().code); //:=
	ASSERT_EQ(TokenCode::TOKEN_INTEGER,    tok.next().code); //10
	ASSERT_EQ(TokenCode::TOKEN_OP_MUL,     tok.next().code); //*
	ASSERT_EQ(TokenCode::TOKEN_INTEGER,    tok.next().code); //20
	ASSERT_EQ(TokenCode::TOKEN_OP_PLUS,    tok.next().code); //+
	ASSERT_EQ(TokenCode::TOKEN_INTEGER,    tok.next().code); //1
	ASSERT_EQ(TokenCode::TOKEN_SEPARATOR,  tok.next().code); //;
	ASSERT_EQ(TokenCode::TOKEN_VAR,        tok.next().code); //var
	ASSERT_EQ(TokenCode::TOKEN_IDENTIFIER, tok.next().code); //b
	ASSERT_EQ(TokenCode::TOKEN_ASSIGN,     tok.next().code); //:=
	ASSERT_EQ(TokenCode::TOKEN_IDENTIFIER, tok.next().code); //c
	ASSERT_EQ(TokenCode::TOKEN_OP_EQ,      tok.next().code); //==
	ASSERT_EQ(TokenCode::TOKEN_INTEGER,    tok.next().code); //201
	ASSERT_EQ(TokenCode::TOKEN_SEPARATOR,  tok.next().code); //;
	ASSERT_EQ(TokenCode::TOKEN_STOP,       tok.next().code); //<STOP>
}
