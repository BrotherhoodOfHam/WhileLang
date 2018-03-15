/*
	Parsing context
*/

#include "wl/Context.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Context::declareVariable(const Symbol& var, const Symbol& type)
{
	using namespace std;

	Variable v;
	v.type = Type::ERR;

	if (type == "nat")
		v.type = Type::NAT;
	else if (type == "bool")
		v.type = Type::BOOL;

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

const Context::Variable& Context::variable(const Symbol& var)
{
	return m_varMap[var];
}

bool Context::isType(const Symbol& type)
{
	return (type == "nat") || (type == "bool");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
