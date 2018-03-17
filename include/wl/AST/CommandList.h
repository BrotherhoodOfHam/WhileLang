/*
	Command List:

	<command-list> ::= <command>; | <command>; <command-list>
*/

#pragma once

#include "CommandBuilder.h"

class CommandList : public AST
{
public:

	CommandList() {}
	~CommandList() {}

	CommandList(Tokenizer& tokens)
	{
		while (CommandBuilder::hasNext(tokens))
		{
			m_commands.emplace_back(CommandBuilder::construct(tokens));
			tokens.nextAssert(TOKEN_SEPARATOR);
		}
	}

	void evaluate(Context& ctx) override
	{
		
	}

private:

	//Really ugly fix
	//Chnage to unique_ptrs at some point
	std::vector<std::shared_ptr<AST>> m_commands;
};
