/*
	Parsing context:
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
enum class Type
{
	ERR,	//error type
	NAT,	//natural number
	BOOL,	//boolean
};

class Context
{
public:

	using Symbol = std::string;
	using Value = std::string;

	struct Variable
	{
		Value value;
		Type type;
	};

	/*
		Construct context object
	*/
	Context() {}

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
	const Variable& variable(const Symbol& var);

	/*
		Returns true if this type exists
	*/
	bool isType(const Symbol& type);

private:

	std::unordered_map<Symbol, Variable> m_varMap;
};
