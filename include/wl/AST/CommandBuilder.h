/*
	CommandBuilder:
	
	<command> ::=  <if-statement> |
				   <while-statement> |
				   <assignment> |
				   <io-command>
*/

#pragma once

#include "wl/AST.h"

#include "IfElseStatement.h"
#include "WhileStatement.h"
#include "AssignmentStatement.h"
#include "IOReadCommand.h"
#include "IOWriteCommand.h"

class CommandBuilder
{
public:

	/*
		Test if next token is the start of a valid command
	*/
	static bool hasNext(Tokenizer& tokens)
	{
		switch (tokens.peek().code)
		{
			case TOKEN_SKIP:	   return true;
			case TOKEN_IF:         return true;
			case TOKEN_WHILE:      return true;
			case TOKEN_IDENTIFIER: return true;
			case TOKEN_READ:       return true;
			case TOKEN_WRITE:      return true;
		}
		
		return false;
	}
	
	/*
		Parse an abstract command
	*/
	static ASTNode construct(Tokenizer& tokens)
	{
		//Infer what type of command is next
		switch (tokens.peek().code)
		{
			case TOKEN_SKIP:	   return nullptr;
			case TOKEN_IF:         return ASTNode(new IfElseStatement(tokens));
			case TOKEN_WHILE:      return ASTNode(new WhileStatement(tokens));
			case TOKEN_IDENTIFIER: return ASTNode(new AssignmentStatement(tokens));
			case TOKEN_READ:       return ASTNode(new IOReadCommand(tokens));
			case TOKEN_WRITE:      return ASTNode(new IOWriteCommand(tokens));
		}
		
		throw SyntaxError(tokens.peek().code, TOKEN_IDENTIFIER);
	}

private:

	CommandBuilder() {}
};
