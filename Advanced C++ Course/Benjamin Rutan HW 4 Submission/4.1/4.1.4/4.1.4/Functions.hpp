/* Functions.hpp (exercise 4.1.4)



*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <functional>
#include <stdexcept>
#include "Matrix.hpp"
#include "Proposition.hpp"

using value_type = Proposition;
template <std::size_t NR, std::size_t NC>
	using BitMap = Matrix<value_type, NR, NC>;
template <std::size_t NR, std::size_t NC>
	using BitMap2 = std::array<std::bitset<NC>, NR>;
using BitFunction = std::function<Proposition(const Proposition&, const Proposition&)>;

template<std::size_t NR, std::size_t NC>
BitMap<NR, NC> mask(const BitMap<NR, NC> &bm1, const BitMap<NR, NC> &bm2, const BitFunction &masker)
{
	BitMap<NR, NC> output;
	for (std::size_t i = 0; i < NR; i++)
	{
		for (std::size_t j = 0; i < NR; i++)
		{
			output(i, j) = masker(bm1, bm2);
		}
	}
	return output;
}

template<std::size_t NR, std::size_t NC>
void initialise(BitMap2<NR, NC> &input, std::size_t rowNum, const std::string &str_input)
{
	if (rowNum >= NR)
	{
		throw std::out_of_range("");
	}
	for (std::size_t col = 0; col < NC; col++)
	{
		input[col][rowNum] = str_input[col] - '0';
	}
}

#endif