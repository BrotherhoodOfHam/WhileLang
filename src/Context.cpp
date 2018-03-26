/*
	Program context
*/

#include <iostream>

#include "wl/Context.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Context::Context() :
	m_stdout(std::cout),
	m_stdin(std::cin)
{}

Context::Context(std::ostream& out, std::istream& in) :
	m_stdout(out),
	m_stdin(in)
{}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Type-System functions
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Context::declareVariable(const Symbol& var, const Symbol& type)
{
	using namespace std;

	Variable v;
	v.type = TypeID::ERR;

	if (type == "nat")
		v.type = TypeID::NAT;
	else if (type == "bool")
		v.type = TypeID::BOOL;

	m_varMap[var] = v;
}

void Context::setVariable(const Symbol& var, const Value& val)
{
	using namespace std;

	auto i = m_varMap.find(var);
	
	if (i != m_varMap.end())
	{
		i->second.value = val;
	}
}

const Context::Variable& Context::getVariable(const Symbol& var)
{
	return m_varMap[var];
}

bool Context::isType(const Symbol& type)
{
	return (type == "nat") || (type == "bool");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Context::Variable Context::binaryOperation(Variable a, Operator op, Variable b)
{
	Value v = 0;

	switch (op)
	{
		case Operator::ADD: v = a.value + b.value; break;
		case Operator::SUB: v = a.value - b.value; break;
		case Operator::MUL: v = a.value * b.value; break;
		case Operator::DIV: v = a.value / b.value; break;
		case Operator::MOD: v = a.value % b.value; break;

		case Operator::NEQ: v = a.value != b.value; break;
		case Operator::EQ:  v = a.value == b.value; break;
		case Operator::GT:  v = a.value >  b.value; break;
		case Operator::LT:  v = a.value <  b.value; break;
		case Operator::GE:  v = a.value >= b.value; break;
		case Operator::LE:  v = a.value <= b.value; break;
	}

	Variable temp;
	temp.type = a.type;
	temp.value = v;
	return temp;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const char* Context::operatorToString(Operator op)
{
	const char* debugStrings[] = 
	{
		"",

		"+",
		"-",
		"*",
		"/",
		"%",

		"!=",
		"==",
		">",
		"<",
		">=",
		"<=",
	};

	return debugStrings[(size_t)op];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
