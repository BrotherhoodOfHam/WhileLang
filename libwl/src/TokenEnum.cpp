/*
	Token Code enum string table.
*/

#include "Tokenizer.h"

const char* Token::codeToString(TokenCode code)
{
	static const char* strings[] =
	{
		"STOP"

		//keywords
		"PROGRAM",
		"VAR",
		"SKIP",
		"READ",
		"WRITE",

		//Values
		"INTEGER",
		"BOOL_TRUE",
		"BOOL_FALSE",

		"COLON",     //:
		"SEPARATOR", //;

					 //Boolean operators
		"OP_AND",
		"OP_OR",
		"OP_NOT",

		"OP_ASSIGN", //:=

					 //Comparators
		"OP_EQ",  // ==
		"OP_NEQ", // !=
		"OP_LE",  // <=
		"OP_GE",  // >=
		"OP_LT",  // <
		"OP_GT",  // >

				  //Arithmetic operators
		"OP_MUL",   // *
		"OP_DIV",   // /
		"OP_MOD",   // %
		"OP_MINUS", // -
		"OP_PLUS",  // +

					//Control flow
		"IF",
		"THEN",
		"ELSE",
		"FI", //end if
		"WHILE",
		"DO",
		"OD", //end while

			  //Generic identifier
		"IDENTIFIER",

		"UNKNOWN"
	};

	return strings[code - 1];
}
