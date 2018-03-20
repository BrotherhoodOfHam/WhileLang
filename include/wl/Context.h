/*
	Program context:

	Encapsulates the state of the program type-system, variables etc.
*/

#pragma once

#include <unordered_map>
#include <ostream>
#include <string>

struct TypeError
{
	std::string type;

	void format(std::ostream& o)
	{
		o << type << " is not a type\n";
	}
};

/*
	Type id's
*/
enum class TypeID
{
	ERR,	//error type
	NAT,	//natural number
	BOOL,	//boolean

	ENUM_SIZE
};

/*
	Operator types
*/
enum class Operator
{
	NOOP,

	//Arithmetic operators
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,

	//Relational operators
	NEQ,
	EQ,
	GT,
	LT,
	GE,
	LE,

	ENUM_SIZE
};

class Context
{
public:

	using Symbol = std::string;
	using Value = uintptr_t;

	struct Variable
	{
		Value value = 0;
		TypeID type = TypeID::ERR;
	};

	/*
		Construct context object
	*/
	Context();

	/*
		Declare a variable of a given type
	*/
	void declareVariable(const Symbol& var, const Symbol& type);

	/*
		Set a variable
	*/
	void setVariable(const Symbol& var, const Value& val);

	/*
		Get a variable
	*/
	const Variable& getVariable(const Symbol& var);

	/*
		Returns true if this type exists
	*/
	bool isType(const Symbol& type);

	/*
		Register accessors
	*/
	void storeValue(Variable val) { m_ctxValue = val; }
	Variable loadValue() const { return m_ctxValue; }

	/*
		Perform a binary operation on two variables
	*/
	Variable binaryOperation(Variable a, Operator op, Variable b);

	/*
		IO commands
	*/

	void iowrite(const Variable& val)
	{
		if (val.type == TypeID::NAT)
		{
			m_stdout << val.value << std::endl;
		}
		else if (val.type == TypeID::BOOL)
		{
			if (val.value == 0)
				m_stdout << "false" << std::endl;
			else
				m_stdout << "true" << std::endl;
		}
	}

	void ioread(const std::string& varName)
	{
		m_stdout << ">";

		std::string temp;
		std::getline(m_stdin, temp);

		const Value val = std::stoull(temp);
		setVariable(varName, val);
	}

	/*
		Debug strings
	*/
	static const char* operatorToString(Operator op);

private:

	std::ostream& m_stdout;
	std::istream& m_stdin;

	//Register
	Variable m_ctxValue;

	std::unordered_map<Symbol, Variable> m_varMap;
};
