/*
	WhileLang interpreter class

	Evaluates and executes a given WhileLang program.
*/

#pragma once

#include <istream>
#include <ostream>
#include <memory>

#include "Context.h"
#include "Tokenizer.h"
#include "AST.h"

enum ExitCode
{
	EX_SUCCESS = 0,
	EX_ERROR   = -1,
};

class WLInterpreter
{
public:

	/*
		Construct an interpreter for the given input program
	*/
	WLInterpreter(std::istream& program);

	/*
		Execute the given program
	*/
	ExitCode execute();

	/*
		Access logging stream
	*/
	void setLog(std::ostream& logstream) { m_log = &logstream; }
	std::ostream& log() { return *m_log; }

private:

	//Parsing functions
	void parseDeclarationList();
	void parseDeclaration();
	void parseIdentifierList(std::vector<std::string>& ids);
	
	//Code evaluation
	void evalCode();
	void evalCommand();
	//Statements
	void evalAssignment();
	void evalIteration();
	void evalConditional();
	//IO commands
	void evalIOWrite();
	void evalIORead();

	std::ostream* m_log;

	std::unique_ptr<AST> m_syntaxTree;

	Context m_ctx;
	Tokenizer m_tokens;
};
