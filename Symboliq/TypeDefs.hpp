/* TypeDefs.hpp
-Description:
	*Create common typedefs for all files to assist reading.

*/


#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

#include<algorithm>
#include<cctype>
#include<map>
#include<string>
#include<strstream>
#include<vector>

#define MAXEXPSIZE 40 // Max number of chars in exponent.
#define MAXCOEFFSIZE 20 // Max number of digits in exponent.
#define MAXPOLYSTRINGSIZE 255 // Max number of characters in Polynomial string.
#define MAXPOLYTERMS 100 // Max number of terms in PolyLinkedList.

namespace Symboliq
{
	typedef unsigned long long ULL;
	typedef long double LD;
	typedef std::vector<std::string> StringVector;
	typedef std::vector<char> CharVector;
	typedef std::vector<long double> LDoubleVector;
	typedef std::vector<ULL> ULLVector;
	typedef std::map<std::string, long double> ValueMap;
}

#endif
