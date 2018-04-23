/*


*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <bitset>
#include <vector>
#include <string>

template<int N>
std::bitset<N> CreateBitsetFromString(const std::string &str_in, std::size_t startIndex = 0)
{
	return std::bitset<N>(str_in.substr(startIndex, N));
}

/* 2.8.4 */
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
			output.push_back(first[i] and second[i] || !first[i] and !second[i]);
		}
		else
		{
			output.push_back(0);
		}
	}
	return output;
}






#endif 

