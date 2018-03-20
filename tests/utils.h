/*
	Testing utils
*/

#pragma once

#include <string>
#include <sstream>

inline std::stringstream wrapStream(const std::string& text)
{
    std::stringstream ss;
    ss << text;
    return std::move(ss);
}
