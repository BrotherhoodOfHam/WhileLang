/*
	Test tokenizer
*/

#pragma once

#include <sstream>

#include "Tokenizer.h"

TEST(libwl, tokenizer)
{
	std::stringstream ss;
	ss << "var c:=10*20+1;var b := c == 201;";

	Tokenizer tok(ss);

	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_VAR);			//var
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_IDENTIFIER);	//c
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_OP_ASSIGN);		//:=
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_INTEGER);		//10
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_OP_MUL);		//*
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_INTEGER);		//20
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_OP_PLUS);		//+
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_INTEGER);		//1
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_SEPARATOR);		//;
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_VAR);			//var
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_IDENTIFIER);	//b
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_OP_ASSIGN);		//:=
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_IDENTIFIER);	//c
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_OP_EQ);			//==
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_INTEGER);		//201
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_SEPARATOR);		//;
	ASSERT_EQ(tok.next().code, TokenCode::TOKEN_STOP);			//<STOP>
}
