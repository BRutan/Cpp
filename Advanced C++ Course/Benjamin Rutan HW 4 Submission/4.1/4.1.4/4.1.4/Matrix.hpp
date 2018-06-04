/* Matrix.hpp (exercise 4.1.4)
Description:
	* Stack allocated matrix class. 
*/

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <stdexcept>

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
	Matrix(const T &input) noexcept
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
	// Overloaded Operators:
	//////////////////////////////
	const T& operator()(std::size_t i, std::size_t j) const						/* Read access. */
	{
		if (i >= Rows || j >= Cols)
		{
			throw std::out_of_range("");
		}
		return data[i*Cols + j];
	}
	T& operator()(std::size_t i, std::size_t j)
	{
		if (i >= Rows || j >= Cols)
		{
			throw std::out_of_range("");
		}
		return data[i*Cols + j];
	}
	friend Matrix operator-(Matrix<T, Rows, Cols> matrix)					/* Unary minus. */
	{
		for (std::size_t i = 0; i < Rows * Cols; i++)
		{
			matrix.data[i] *= -matrix.data[i];
		}
		return matrix;
	}
	friend Matrix operator*(T scalar, Matrix<T, Rows, Cols> matrix)			/* Premultiplication. */
	{
		for (std::size_t i = 0; i < Rows * Cols; i++)
		{
			matrix.data[i] *= scalar;
		}
		return matrix;
	}
	friend std::ostream& operator<<(std::ostream &out, const Matrix<T, Rows, Cols> &in)
	{
		out << "\n{ ";
		for (std::size_t i = 0; i < Rows; i++)
		{
			out << ((i > 0) ? "  " : "");
			for (std::size_t j = 0; j < Cols; j++)
			{
				out << in(i,j) << ((j < Cols - 1) ? "," : "");
			}
			out << ((i < Rows - 1)? "\n":"");
		}
		out << " }";
		return out;
	}
};


#endif