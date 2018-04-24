/* Functions.hpp (exercise 2.8.1, 2.8.4 etc)

　
*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <bitset>
#include <vector>
#include <string>

/* 2.8.4 */
// Misc functions: 

// Convert unsigned long long to vector bitset:
void ConvertULLToVectorBitset(std::vector<bool> &in, unsigned long long value)
{
	std::size_t currIndex = 0;
	while (value)
	{
		in[currIndex] = value % 2;
		value /= 2;
	}
}
// Convert vector bitset to string:
std::string VectorBitsetToString(const std::vector<bool> &in)
{
	std::string output;
	for (auto i : in)
	{
		output += (i) ? "1" : "0";
	}
	return output;
}
// Perform bitwise AND between two same-sized vector bitsets:
std::vector<bool> AND(const std::vector<bool> &lhs, const std::vector<bool> &rhs)
{
	if (lhs.size() != rhs.size())
	{
		throw -1;
	}
	std::vector<bool> output(lhs);
	for (std::size_t i = 0; i < lhs.size(); i++)
	{
		output[i] = lhs[i] & rhs[i];
	}
	return output;
}
// Perform bitwise OR between two same-sized vector bitsets:
std::vector<bool> OR(const std::vector<bool> &lhs, const std::vector<bool> &rhs)
{
	if (lhs.size() != rhs.size())
	{
		throw - 1;
	}
	std::vector<bool> output(lhs);
	for (std::size_t i = 0; i < lhs.size(); i++)
	{
		output[i] = lhs[i] | rhs[i];
	}
	return output;
}
// Perform bitwise XOR between two same-sized vector bitsets:
std::vector<bool> XOR(const std::vector<bool> &lhs, const std::vector<bool> &rhs)
{
	if (lhs.size() != rhs.size())
	{
		throw - 1;
	}
	std::vector<bool> output(lhs);
	for (std::size_t i = 0; i < lhs.size(); i++)
	{
		output[i] = lhs[i] ^ rhs[i];
	}
	return output;
}

// b) Create function to compute intersection of two vectors:
std::vector<bool> Intersection(const std::vector<bool> &first, const std::vector<bool> &second)
{
	// Set the number of elements in the output set as the size of the larger set:
	std::size_t outputSize = (first.size() > second.size()) ? first.size() : second.size();
	std::size_t smallerSize = (first.size() > second.size()) ? second.size() : first.size();
	std::vector<bool> output(outputSize, false);

	// Determine all common indices:
	for (std::size_t i = 0; i < outputSize; i++)
	{
		if (i < smallerSize)
		{
			output.push_back(first[i] & second[i] || !first[i] & !second[i]);
		}
		else
		{
			output.push_back(0);
		}
	}
	return output;
}

　
　
　
#endif 

　
