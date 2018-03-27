/*
	Command Builder
*/

#include "wl/AST/CommandBuilder.h"

#include "wl/AST/IfElseStatement.h"
#include "wl/AST/WhileStatement.h"
#include "wl/AST/AssignmentStatement.h"
#include "wl/AST/IOReadCommand.h"
#include "wl/AST/IOWriteCommand.h"
#include "wl/AST/SkipStatement.h"

bool CommandBuilder::hasNext(Tokenizer& tokens)
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

ASTNode CommandBuilder::construct(Tokenizer& tokens)
{
	//Infer what type of command is next
	switch (tokens.peek().code)
	{
	case TOKEN_SKIP:	   return ASTNode(new SkipStatement(tokens));
	case TOKEN_IF:         return ASTNode(new IfElseStatement(tokens));
	case TOKEN_WHILE:      return ASTNode(new WhileStatement(tokens));
	case TOKEN_IDENTIFIER: return ASTNode(new AssignmentStatement(tokens));
	case TOKEN_READ:       return ASTNode(new IOReadCommand(tokens));
	case TOKEN_WRITE:      return ASTNode(new IOWriteCommand(tokens));
	}

	throw SyntaxError(TOKEN_IDENTIFIER, tokens.peek());
}
