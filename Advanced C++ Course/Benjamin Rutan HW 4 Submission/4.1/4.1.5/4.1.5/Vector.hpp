/* Vector.hpp (exercise 4.1.5)
Description:
	* Compile time vector, sitting on stack.




*/

#ifndef VECTOR_HPP
#define VECTOR_HPP



#include <array>
#include <functional>
#include <iostream>
#include <string>
#include <stdexcept>

template<typename T, std::size_t Size>
class Vector
{
private:
	T data[Size];
public:
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	Vector() noexcept 					/* Default constructor. Set all elements to their default value. */
	{
		for (std::size_t i = 0; i < Size; i++)
		{
			data[i] = T();
		}
	}
	Vector(const T &val) noexcept 		/* Overloaded constructor. Set all values in vector. */
	{
		for (std::size_t i = 0; i < Size; i++)
		{
			data[i] = val;
		}
	}
	virtual ~Vector() noexcept						/* Destructor. */
	{

	}
	////////////////////////////
	// Misc Functions:
	////////////////////////////
	void modify(const std::function<T(T&)> &f) noexcept			/* Modify all values of Vector using function. */
	{
		std::transform(&data[0], &data[Size - 1], &data[0], f);
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	const T& operator[](std::size_t index) const				/* Read value at index. */
	{
		if (index >= Size)
		{
			throw std::out_of_range("");
		}
		return data[index];
	}
	T& operator[](std::size_t index)					/* Write value at index. */
	{
		if (index >= Size)
		{
			throw std::out_of_range("");
		}
		return data[index];
	}
	Vector& operator=(const Vector &input)				/* Assignment operator. */
	{
		if (this != &input)
		{
			this->data = input.data;
		}
		return *this;
	}
	friend Vector operator-(const Vector &A) noexcept   /* Unary minus. Negate all elements of vector. */
	{
		Vector output;
		for (std::size_t i = 0; i < Size; i++)
		{
			output[i] = -A[i];
		}
		return output;
	}
	friend Vector operator-(const Vector &A, const Vector &B) noexcept		/* Vector subtraction. */
	{
		Vector output;
		for (std::size_t i = 0; i < Size; i++)
		{
			output[i] = A[i] - B[i];
		}
		return output;
	}
	friend Vector operator+(const Vector &A, const Vector &B) noexcept		/* Vector addition. */
	{
		Vector output;
		for (std::size_t i = 0; i < Size; i++)
		{
			output[i] = A[i] + B[i];
		}
		return output;
	}
	template <typename F>
	friend Vector operator*(const F &scalar, const Vector &B) noexcept		/* Scalar premultiplication . */
	{
		Vector output;
		for (std::size_t i = 0; i < Size; i++)
		{
			output[i] = scalar * B[i];
		}
		return output;
	}
	friend std::ostream& operator<<(std::ostream &output, const Vector &input)	/* Print vector to stdout. */
	{
		output << "{ ";
		for (std::size_t i = 0; i < Size; i++)
		{
			output << input.data[i] << ((i < Size - 1)? ", ": " }");
		}
		return output;
	}
};

#endif
