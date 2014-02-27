#ifndef UTIL_H
#define UTIL_H

#include <sstream>
using std::stringstream;

template<typename T>
T FromString(string key)
{	
	stringstream sstr(key);
	T ret;
	sstr >> ret;
	return ret;
}

template<> bool FromString<bool>(string key);
template<> int FromString<int>(string key);

template<typename T>
string ToString(T key)
{	
	stringstream sstr;
	sstr << key;
	return sstr.str();
}

string ToString(bool key, string truestring="true", string falsestring="false");

template<typename T>
void SetValue(uchar* pos, T value)
{
	*(T*)pos = value;
}

template<typename T>
T GetValue(uchar* binary, uint pos)
{
	return *(T*)&(binary[pos]);
}

uint EndianSwap(uint n);

#include <ctime>

clock_t ticker();

#endif