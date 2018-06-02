/*



*/


#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

template<typename T, std::size_t Rows, std::size_t Cols>
class Matrix
{
private:
	T data[Rows * Cols];
public:
	//////////////////////////////
	// Constructors/Destructor:
	//////////////////////////////
	Matrix()
	{
		for (std::size_t i = 0; i < Rows * Cols; i++)
		{
			data[i] = T();
		}
	}
	Matrix(const T &input)
	{
		for (std::size_t i = 0; i < Rows * Cols; i++)
		{
			data[i] = input;
		}
	}
	virtual ~Matrix()
	{

	}
	//////////////////////////////
	// :
	//////////////////////////////

};


#endif