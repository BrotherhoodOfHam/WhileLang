/*
	WhileLang interpreter class

	Evaluates and executes a given WhileLang program.
*/

#pragma once

#include <istream>
#include <ostream>

#include "Context.h"
#include "Tokenizer.h"

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

	Token assertNext(TokenCode code);

	void evaluateHeader();
	void evaluateDeclarationList();
	void evaluateDeclaration();
	void evaluateCode();

	std::ostream* m_log;

	Context m_ctx;
	Tokenizer m_tokens;
};
