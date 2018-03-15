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

class ProgramDeclaration : public AST
{
public:

	ProgramDeclaration(Tokenizer& tokens)
	{
		tokens.nextAssert(TOKEN_PROGRAM);

		m_vars = VariableDeclarationList(tokens);

		tokens.nextAssert(TOKEN_BEGIN);

		m_commands = CommandList(tokens);

		tokens.nextAssert(TOKEN_END);
	}

	~ProgramDeclaration() {}

	void evalutate(Context& ctx) override
	{

	}

private:

	VariableDeclarationList m_vars;
	CommandList m_commands;
};
