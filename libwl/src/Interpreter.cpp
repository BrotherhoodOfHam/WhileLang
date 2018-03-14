/*
	Interpreter class
*/

#include <iostream>

#include "wl/Interpreter.h"
#include "SyntaxError.h"

////////////////////////////////////////////////////////////////////////////////////////////////

WLInterpreter::WLInterpreter(std::istream& program) :
	m_tokens(program)
{
	//default logger is STDOUT
	m_log = &std::cout;
}

ExitCode WLInterpreter::execute()
{
	try
	{
		//Evaluate program header
		evaluateHeader();
		//Evaluate variable declarations
		evaluateDeclarationList();
		//Evaluate program code
		evaluateCode();
	}
	catch (SyntaxError e)
	{
		e.format(log());
	}

	return EX_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void WLInterpreter::evaluateHeader()
{
	//program keyword
	assertNext(TOKEN_PROGRAM);
}

/*
	Evaluate variable declaration list

	<declaration-list> ::= <declaration> | <declaration> <declaration-list>
*/
void WLInterpreter::evaluateDeclarationList()
{
	while (!m_tokens.isNext(TOKEN_BEGIN))
	{
		evaluateDeclaration();
	}
}

/*
	Evaluate variable declaration

	<declaration> ::= var <identifier-list> : <type>;
*/
void WLInterpreter::evaluateDeclaration()
{
	std::vector<std::string> varNames;
	std::string typeName;

	while (!m_tokens.isNext(TOKEN_SEPARATOR))
	{
		varNames.clear();

		assertNext(TOKEN_VAR);

		/*
			Extract variable names
		*/
		bool cont = true;

		while (cont)
		{
			varNames.push_back(assertNext(TOKEN_IDENTIFIER).symbol);
			
			if (m_tokens.isNext(TOKEN_COLON))
			{
				m_tokens.next();
				cont = false;
			}
			else
			{
				assertNext(TOKEN_COMMA);
			}
		}

		//Extract type name
		typeName = assertNext(TOKEN_IDENTIFIER).symbol;

		//Forward declare all variables
		for (const auto& name : varNames)
		{
			m_ctx.declareVariable(name, typeName);
		}
	}

	//consume ;
	m_tokens.next();
}

void WLInterpreter::evaluateCode()
{
	assertNext(TOKEN_BEGIN);

	while (!m_tokens.isNext(TOKEN_END))
	{

	}

	assertNext(TOKEN_END);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers

Token WLInterpreter::assertNext(TokenCode code)
{
	if (!m_tokens.isNext(code))
	{
		throw SyntaxError(code, m_tokens.peek().code);
	}

	return m_tokens.next();
}

////////////////////////////////////////////////////////////////////////////////////////////////
