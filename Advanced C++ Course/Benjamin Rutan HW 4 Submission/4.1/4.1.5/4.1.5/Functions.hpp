/* Functions.hpp (exercise 4.1.5)
Description:
	*


*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <complex>
#include <functional>
#include <numeric>
#include "Matrix.hpp"
#include "Vector.hpp"

template<typename T, std::size_t N>
T inner_product(const Vector<T, N> &v1, const Vector<T, N> &v2, T initValue)
{
	for (std::size_t i = 0; i < N; i++)
	{
		initValue += v1[i] * v2[i];
	}
	return initValue;
}

template <typename T>
	using BinaryFunction = std::function <T(const T &t1, const T &t2)>;

template<typename T, std::size_t N>
T inner_product(const Vector<T, N> &v1, const Vector<T, N> &v2, T initValue, const BinaryFunction<T> &op1, const BinaryFunction<T> &op2)
{
	for (std::size_t i = 0; i < N; i++)
	{
		initValue += op1(initValue, op2(v1[i], v2[i]));
	}
	return initValue;
}

template<typename T, std::size_t N, std::size_t M>
Matrix<T, N, M> outer_product(const Vector<T, N> &v1, const Vector<T, M> &v2)
{
	Matrix<T, N, M> output;
	for (std::size_t i = 0; i < N; i++)
	{
		for (std::size_t j = 0; j < M; j++)
		{
			output(i, j) = v1[i] * v2[j];
		}
	}
	return output;
}
/*
template<T, std::size_t N, std::size_t M>
Matrix<std::complex<T>, N, M> outer_product(const Vector<T, N> &v1, const Vector<T, M> &v2)
{
	Matrix<T, N, M> output;
	for (std::size_t i = 0; i < N; i++)
	{
		for (std::size_t j = 0; j < M; j++)
		{
			output(i, j) = v1[i] * v2[j];
		}
	}
	return output;
}
*/

#endif
