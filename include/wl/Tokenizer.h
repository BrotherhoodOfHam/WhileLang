/*
	Tokenizer:

	Takes a stream of characters as input and produces a sequence of tokens.
*/

#pragma once

#include <istream>
#include <string>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum TokenCode : uint8_t
{
	TOKEN_STOP,
	
	//keywords
	TOKEN_PROGRAM,
	TOKEN_VAR,
	TOKEN_BEGIN,
	TOKEN_END,
	TOKEN_SKIP,
	TOKEN_READ,
	TOKEN_WRITE,

	//Values
	TOKEN_INTEGER,
	TOKEN_BOOL,

	TOKEN_COLON,     //:
	TOKEN_COMMA,	 //,
	TOKEN_SEPARATOR, //;

	TOKEN_OPEN_BRACKET,  //(
	TOKEN_CLOSE_BRACKET, //)

	//Boolean operators
	TOKEN_OP_AND,
	TOKEN_OP_OR,
	TOKEN_OP_NOT,

	TOKEN_ASSIGN, //:=

	//Comparators
	TOKEN_OP_EQ,  // ==
	TOKEN_OP_NEQ, // !=
	TOKEN_OP_LE,  // <=
	TOKEN_OP_GE,  // >=
	TOKEN_OP_LT,  // <
	TOKEN_OP_GT,  // >

	//Arithmetic operators
	TOKEN_OP_MUL,   // *
	TOKEN_OP_DIV,   // /
	TOKEN_OP_MOD,   // %
	TOKEN_OP_MINUS, // -
	TOKEN_OP_PLUS,  // +

	//Control flow
	TOKEN_IF,
	TOKEN_THEN,
	TOKEN_ELSE,
	TOKEN_FI, //end if
	TOKEN_WHILE,
	TOKEN_DO,
	TOKEN_OD, //end while

	//Generic identifier
	TOKEN_IDENTIFIER,
	//Code comment
	TOKEN_COMMENT,

	TOKEN_UNKNOWN,

	ENUM_SIZE
};

/*
	Token data structure
*/
struct Token
{
	std::string symbol;
	TokenCode code;
	int line;
	int toknum;

	Token() :
		code(TOKEN_STOP),
		line(1),
		toknum(0)
	{}

	Token(const Token& rhs) :
		symbol(rhs.symbol),
		code(rhs.code),
		line(rhs.line),
		toknum(rhs.toknum)
	{}

	static const char* codeToString(TokenCode code);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
	Tokenizer class
*/
class Tokenizer
{
public:

	Tokenizer(std::istream& stream) :
		m_stream(stream)
	{
		next();
	}

	//Peek the next token
	const Token& peek() const
	{
		return m_next;
	}

	//Consume and return the next available token
	Token next();

	//Get the next token and assert it's type is equal to the given code
	Token nextAssert(TokenCode code);

	//Return true if there is another token
	bool hasNext() const
	{
		return peek().code != TOKEN_STOP;
	}

	//Return true if the next token is of a given type
	bool isNext(TokenCode code) const
	{
		return peek().code == code;
	}

private:

	void fetch();

	//store one token ahead
	Token m_next;
	std::istream& m_stream;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
