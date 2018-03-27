/*
	Token Code enum string table.
*/

#include "wl/Tokenizer.h"

const char* Token::codeToString(TokenCode code)
{
	static const char* strings[] =
	{
		"STOP",

		//keywords
		"program",
		"var",
		"begin",
		"end",
		"skip",
		"read",
		"write",

		//Values
		"Integer Constant",
		"Boolean Constant",

		":",
		",",
		";",

		"(",  //(
		")", //)

		//Boolean operators
		"and",
		"or",
		"not",

		//Assignment
		":=",

		//Comparators
		"==",
		"!=",
		"<=",
		">=",
		"<",
		">",

		//Arithmetic operators
		"*",
		"/",
		"%",
		"-",
		"+",

		//Control flow
		"if",
		"then",
		"else",
		"fi", //end if
		"while",
		"do",
		"od", //end while

		//Generic identifier
		"Identifier",
		"Comment",

		"UNKNOWN"
	};

	return strings[code];
}
