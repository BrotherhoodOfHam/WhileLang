/*
	Char types header, for classifying character types
*/

#pragma once

#include <string>
#include <cstdint>

enum CharClass : char
{
	CHAR_CLASS_OTHER,
	CHAR_CLASS_LETTER,
	CHAR_CLASS_DIGIT,
	CHAR_CLASS_WHITESPACE,
};

/*
	Char class lookup table
*/
class CharTypes
{
private:

	enum { CLASS_TABLE_SIZE = 256 };

	//Class table
	CharClass m_table[CLASS_TABLE_SIZE];

	CharTypes()
	{
		//Other class
		memset(m_table, CHAR_CLASS_OTHER, CLASS_TABLE_SIZE);
			
		//Letter class
		for (uint32_t i = 0; i <= ('z' - 'a'); i++)
		{
			m_table[(uint32_t)'a' + i] = CHAR_CLASS_LETTER;
			m_table[(uint32_t)'A' + i] = CHAR_CLASS_LETTER;
		}

		//Digit class
		for (char c = '0'; c <= '9'; c++)
		{
			m_table[c] = CHAR_CLASS_DIGIT;
		}

		//Whitespace class
		m_table[' '] = CHAR_CLASS_WHITESPACE;
		m_table['\t'] = CHAR_CLASS_WHITESPACE;
		m_table['\n'] = CHAR_CLASS_WHITESPACE;
		m_table['\r'] = CHAR_CLASS_WHITESPACE;
	}

public:

	static CharClass classify(char c)
	{
		static const CharTypes s_types;
		return s_types.m_table[c];
	}
};
