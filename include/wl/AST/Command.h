/*
	Command:
	
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

class Command : public AST
{
public:
	
	Command() {}
	~Command() {}
	
	/*
		Test if next token is the start of a valid command
	*/
	static bool isCommand(Tokenizer& tokens)
	{
		switch (tokens.peek().code)
		{
			case TOKEN_SKIP:	   return true;
			case TOKEN_IF:         return true;
			case TOKEN_WHILE:      return true;
			case TOKEN_OP_ASSIGN:  return true;
			case TOKEN_READ:       return true;
			case TOKEN_WRITE:      return true;
		}
		
		return false;
	}
	
	/*
		Parse an abstract command
	*/
	Command(Tokenizer& tokens)
	{
		//Infer what type of command is next
		switch (tokens.peek().code)
		{
			case TOKEN_SKIP:	   m_command.reset(nullptr);                         return;
			case TOKEN_IF:         m_command.reset(new IfElseStatement(tokens));     return;
			case TOKEN_WHILE:      m_command.reset(new WhileStatement(tokens));      return;
			case TOKEN_OP_ASSIGN:  m_command.reset(new AssignmentStatement(tokens)); return;
			case TOKEN_READ:       m_command.reset(new IOReadCommand(tokens));       return;
			case TOKEN_WRITE:      m_command.reset(new IOWriteCommand(tokens));      return;
		}
		
		throw SyntaxError(tokens.peek().code, TOKEN_IDENTIFIER);
	}
	
	void evalutate(Context& ctx) override
	{
		if (m_command != nullptr)
		{
			m_command->evalutate(ctx);
		}
	}
	
private:
	
	std::unique_ptr<AST> m_command;
};
