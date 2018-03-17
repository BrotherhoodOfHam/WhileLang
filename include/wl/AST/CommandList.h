/*
	Command List:

	<command-list> ::= <command>; | <command>; <command-list>
*/

#pragma once

#include "Command.h"

class CommandList : public AST
{
public:

	CommandList() {}
	~CommandList() {}

	CommandList(Tokenizer& tokens)
	{
		while (Command::isCommand(tokens))
		{
			m_commands.push_back(Command(tokens));
			tokens.nextAssert(TOKEN_SEPARATOR);
		}
	}

	void evalutate(Context& ctx) override
	{
		
	}

private:

	std::vector<Command> m_commands;
};
