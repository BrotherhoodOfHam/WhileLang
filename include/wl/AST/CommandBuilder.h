/*
	CommandBuilder:
	
	<command> ::=  <if-statement> |
				   <while-statement> |
				   <assignment> |
				   <io-command>
*/

#pragma once

#include "wl/AST.h"
#include "wl/SyntaxError.h"

class CommandBuilder
{
public:

	/*
		Test if next token is the start of a valid command
	*/
	static bool hasNext(Tokenizer& tokens);
	
	/*
		Parse an abstract command
	*/
	static ASTNode construct(Tokenizer& tokens);

private:

	CommandBuilder() {}
};
