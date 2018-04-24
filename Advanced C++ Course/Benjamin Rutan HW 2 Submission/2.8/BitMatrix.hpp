/* BitMatrix.hpp (exercise 
Description:
	* Template matrix of bitsets.
Class Methods:
	* BitMatrix(): 

　
　
　
*/

#ifndef BITMATRIX_HPP
#define BITMATRIX_HPP

#include <bitset>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

template<std::size_t rows, std::size_t cols>
class BitMatrix
{
private:
	std::bitset<rows * cols> data;
	const static constexpr std::size_t numCols = cols;
	const static constexpr std::size_t numRows = rows;
public:
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	BitMatrix() : data()											/* Default Constructor. */
	{

	}
	BitMatrix(unsigned long long convert) : data(convert)			/* Overloaded Constructor. Convert integral value to bitset. */
	{

	}
	explicit BitMatrix(const BitMatrix &input) : data(input.data)	/* Explicit Copy Constructor. */
	{

	}
	virtual ~BitMatrix()											/* Destructor. */
	{

	}
	////////////////////////////
	// Accessors:
	////////////////////////////
	std::size_t Rows() const										/* Return number of rows. */
	{
		return numRows;
	}
	std::size_t Columns() const										/* Return number of columns. */
	{
		return numCols;
	}
	bool At(std::size_t rowIndex, std::size_t colIndex) const		/* Get element at index. */
	{
		if (rowIndex > numRows - 1 || colIndex > numCols - 1)
		{
			std::stringstream ss;
			ss << "Parameters [" << rowIndex << ", " << colIndex << "] are out of range. ";
			throw std::out_of_range(ss.str());
		}
		return data[rowIndex * numCols + colIndex];
	}
	////////////////////////////
	// Mutators:
	////////////////////////////
	BitMatrix& reset()													/* Reset all bits to 0. */
	{
		for (std::size_t i = 0; i < numRows * numCols; i++)
		{
			data[i] = 0;
		}
		return *this;
	}
	BitMatrix& flip()														/* Flip all bits. */
	{
		for (std::size_t i = 0; i < numRows * numCols; i++)
		{
			data[i] = !data[i];
		}
		return *this;
	}
	////////////////////////////
	// Misc. Methods:
	////////////////////////////
	bool none() const												/* Return true if none of the bits are flipped. */
	{
		for (std::size_t i = 0; i < numRows * numCols; i++)
		{
			if (data[i])
			{
				return false;
			}
		}
		return true;
	}
	bool all() const												/* Return true if all of the bits are flipped. */
	{
		for (std::size_t i = 0; i < numRows * numCols; i++)
		{
			if (!data[i])
			{
				return false;
			}
		}
		return true;
	}
	bool any() const												/* Return true if any of the bits are flipped. */
	{
		return !this->none();
	}
	std::size_t trueCount() const									/* Return number of bits that are 1. */
	{
		std::size_t output = 0;
		for (std::size_t i = 0; i < numRows * numCols; i++)
		{
			if (data[i])
			{
				output++;
			}
		}
		return output;
	}
	std::string ToString() const									/* Return binary representation of BitMatrix. */
	{
		std::string output;
		for (std::size_t row = 0; row < numRows; row++)
		{
			for (std::size_t col = 0; col < numCols; col++)
			{
				output = ((data[row * numCols + col]) ? '1' : '0') + output;
			}
			output = '\n' + output;
		}
		return output;
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	BitMatrix& operator=(const BitMatrix &rhs)																								/* Assignment operator. */
	{
		if (this != rhs)
		{
			this->data = rhs.data;
		}
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const BitMatrix &in)					/* Ostream operator. */
	{
		os << in.ToString();
		return os;
	}
	// Bitwise operators:
	BitMatrix& operator&(const BitMatrix &rhs)								/* Bitwise AND operator. */
	{
		this->data &= rhs.data;
		return *this;
	}
	BitMatrix& operator|(const BitMatrix &rhs)								/* Bitwise OR operator. */
	{
		this->data |= rhs.data;
		return *this;
	}
	BitMatrix& operator^(const BitMatrix &rhs)								/* Bitwise XOR operator. */
	{
		this->data ^= rhs.data;
		return *this;
	}
};

#endif
