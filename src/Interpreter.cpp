/*
	Interpreter class
*/

#include <iostream>

#include "wl/Interpreter.h"
#include "wl/SyntaxError.h"

#include "wl/AST/ProgramDeclaration.h"

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
		//Build Abstract Syntax Tree
		m_syntaxTree.reset(new ProgramDeclaration(m_tokens));


		/*
		//program keyword
		m_tokens.nextAssert(TOKEN_PROGRAM);

		//Parse variable declarations
		parseDeclarationList();

		//Evaluate program code
		evalCode();
		*/
	}
	catch (SyntaxError e)
	{
		e.format(log());
		return EX_ERROR;
	}

	return EX_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////

/*
	Evaluate variable declaration list

	<declaration-list> ::= <declaration> | <declaration> <declaration-list>
*/
void WLInterpreter::parseDeclarationList()
{
	while (!m_tokens.isNext(TOKEN_BEGIN))
	{
		parseDeclaration();
	}
}

/*
	Evaluate variable declaration

	<declaration> ::= var <identifier-list> : <type>;
*/
void WLInterpreter::parseDeclaration()
{
	std::vector<std::string> varNames;
	std::string typeName;

	m_tokens.nextAssert(TOKEN_VAR);

	/*
		Extract variable names
	*/
	parseIdentifierList(varNames);

	m_tokens.nextAssert(TOKEN_COLON);

	//Extract type name
	typeName = m_tokens.nextAssert(TOKEN_IDENTIFIER).symbol;

	//Forward declare all variables
	for (const auto& name : varNames)
	{
		m_ctx.declareVariable(name, typeName);
	}
	
	//consume ;
	m_tokens.nextAssert(TOKEN_SEPARATOR);
}

void WLInterpreter::parseIdentifierList(std::vector<std::string>& ids)
{
	while (true)
	{
		ids.push_back(m_tokens.nextAssert(TOKEN_IDENTIFIER).symbol);

		if (m_tokens.isNext(TOKEN_COMMA))
		{
			m_tokens.next();
		}
		else
		{
			return;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////

void WLInterpreter::evalCode()
{
	m_tokens.nextAssert(TOKEN_BEGIN);

	while (!m_tokens.isNext(TOKEN_END))
	{
		evalCommand();
	}

	m_tokens.next();
}

/*
	Evaluate command:

	<command-list> ::= <command>; | <command>; <command-list>

	<command> ::= <IO> | <statement>

	<statement> ::= skip | <assignment> | <conditional> | <iteration>
	<IO> ::= <IO-read> | <IO-write>
*/
void WLInterpreter::evalCommand()
{
	switch (m_tokens.peek().code)
	{
		//statements
		case TOKEN_SKIP:       m_tokens.next();   break; //no-op
		case TOKEN_IDENTIFIER: evalAssignment();  break; //assignment
		case TOKEN_IF:         evalConditional(); break; //conditional
		case TOKEN_WHILE:      evalIteration();   break; //iteration
		//IO commands
		case TOKEN_READ:       evalIORead();      break;
		case TOKEN_WRITE:      evalIOWrite();     break;
	}

	m_tokens.nextAssert(TOKEN_SEPARATOR);
}

/*
	Evaluate assignment operation

	<assignment> ::= <identifier> := <expression>
*/
void WLInterpreter::evalAssignment()
{
	const std::string id = m_tokens.nextAssert(TOKEN_IDENTIFIER).symbol;

	m_tokens.nextAssert(TOKEN_OP_ASSIGN);

	while (!m_tokens.isNext(TOKEN_SEPARATOR)) m_tokens.next();
	//m_ctx.setVariable("", std::to_string(evalExpression()));

	std::cout << "ASSIGNMENT\n";
}

/*
	Evaluate iteration statement:

	while <boolean-expression> do <command-list> od
*/
void WLInterpreter::evalIteration()
{
	m_tokens.nextAssert(TOKEN_WHILE);

	while (!m_tokens.isNext(TOKEN_OD))
	{
		m_tokens.next();
	}

	m_tokens.next();

	std::cout << "ITERATION\n";
}

/*
	Evaluate conditional statement:

	if <boolean-expression> then <command-list> else <command-list> fi
*/
void WLInterpreter::evalConditional()
{
	m_tokens.nextAssert(TOKEN_IF);

	while (!m_tokens.isNext(TOKEN_FI))
	{
		m_tokens.next();
	}

	m_tokens.next();

	std::cout << "CONDITIONAL\n";
}

/*
	Evaluate write command:

	<IO-write> ::= write <identifier-list>
*/
void WLInterpreter::evalIOWrite()
{
	std::vector<std::string> varNames;

	m_tokens.nextAssert(TOKEN_WRITE);

	parseIdentifierList(varNames);
}

/*
	Evaluate read command:

	<IO-read> ::= read <identifier-list>
*/
void WLInterpreter::evalIORead()
{
	std::vector<std::string> varNames;

	m_tokens.nextAssert(TOKEN_READ);

	m_tokens.nextAssert(TOKEN_OPEN_BRACKET);
	parseIdentifierList(varNames);
	m_tokens.nextAssert(TOKEN_CLOSE_BRACKET);
}

////////////////////////////////////////////////////////////////////////////////////////////////
