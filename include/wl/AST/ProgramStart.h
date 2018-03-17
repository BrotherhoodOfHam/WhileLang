/*
	Program declaration:

	<program> ::= program
					<variable-declaration-list>
				  begin
					<command-list>
				  end
*/

#pragma once

#include "wl/AST.h"

#include "VariableDeclarationList.h"
#include "CommandList.h"

class ProgramStart : public AST
{
public:

	ProgramStart(Tokenizer& tokens)
	{
		tokens.nextAssert(TOKEN_PROGRAM);

		m_vars = VariableDeclarationList(tokens);

		tokens.nextAssert(TOKEN_BEGIN);

		m_commands = CommandList(tokens);

		tokens.nextAssert(TOKEN_END);
	}

	~ProgramStart() {}

	void evaluate(Context& ctx) override
	{

	}

private:

	VariableDeclarationList m_vars;
	CommandList m_commands;
};
