/* Main.cpp (exercise 4.1.5) TODO specialize for std::complex
Description:
	*


*/

#include <complex>
#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "Functions.hpp"


int main()
{
	/* 4.1.5 */
	Vector<int, 12> vec1(20), vec2(40);
	// b) Test first variant of inner_product:
	std::cout << "Vec1 (inner product) Vec2: " << inner_product(vec1, vec2, 0) << std::endl;

	// c) Test second variant of inner_product:
	BinaryFunction<int> add = [](int a, int b) { return a + b; };
	BinaryFunction<int> multiply = [](int a, int b) { return a * b; };
	int output = inner_product(vec1, vec2, 0, add, multiply);
	std::cout << "Vec1 (inner product) Vec2 using add and multiple binary operators: " << output << std::endl;
	// d) Test outer_product: 
	Vector<int, 4> vec3(5);
	Vector<int, 3> vec4(3);
	Matrix<int, 4, 3> outputMatrix = outer_product(vec3, vec4);
	std::cout << "Vec3: " << vec3 << std::endl;
	std::cout << "Vec4: " << vec4 << std::endl;
	std::cout << "Vec3 (outer product) Vec4: " << outputMatrix << std::endl;
	// e) Test outer_product with std::complex specialization:

	system("pause");

	return 0;
}