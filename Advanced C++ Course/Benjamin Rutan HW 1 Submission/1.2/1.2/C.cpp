/* Circle.hpp (exercise 1.2.1)
Description:
	* Class demonstrating deleting constructors and operators, explicit constructors, as well as the constexpr and noexcept keywords.
State Variables/Objects:
	*vector<double> p_vec: stl vector containing double data.
	* C(const C&): deleted copy constructor to prevent copying.
	* C& operator=(const C&): deleted assignment operator to prevent assignment.
Member Functions:
	// Constructors/Destructor:
	* C(): default constructor.
	* C(C&&): move copy constructor.
	* ~C(): destructor.
	// Member Functions:
	void push_back(double): push element back onto p_vec.
	void print() const: print all values in p_vec.
	void setElement(unsigned, double): set element in p_vec at provided index.
	double getElement(unsigned) const: get the element in p_Vec at passed index.
	void scale(double): multiply all elements of p_vec by a scaling factor.
	// Overloaded Operators:
	C& operator=(C&&): move assignment operator.
*/

#include <iostream>
#include <vector>
#include "C.hpp"

C::~C() noexcept														// Destructor.
{
	std::cout << "Destructor called. " << std::endl;
}
C::C(C &&copy) noexcept : p_vec(std::move(copy.p_vec))					// Move-semantics copy constructor (Problem 3).
{
	std::cout << "Move copy constructor called. " << std::endl;
}
void C::print() const noexcept											// Print each value of p_vec.
{
	std::cout << "{ ";
	for (auto iter = this->p_vec.begin(); iter != this->p_vec.end(); iter++)
	{
		std::cout << *iter << ((iter + 1 != this->p_vec.end()) ? ", " : "" );
	}
	std::cout << " } " << std::endl;
}
void C::push_back(double val) noexcept										// Prepend value to p_vec.
{
	this->p_vec.push_back(val);
}
void C::setElement(unsigned index, double value) 					// Set value of element at passed index.
{
	if (index >= p_vec.size())
	{
		throw - 1;
	}
	else
	{
		p_vec[index] = value;
	}
}
double C::getElement(unsigned index) const							// Get value of p_vec element at passed index.
{
	if (index >= p_vec.size())
	{
		throw - 1;
	}
	else
	{
		return p_vec[index];
	}
}
void C::scale(double scaleFactor) noexcept							// Multiply each element in p_vec by scaling factor.
{
	for (auto iter = this->p_vec.begin(); iter != this->p_vec.end(); iter++)
	{
		*iter *= scaleFactor;
	}
}
/* Overloaded operators. */
C& C::operator=(C &&copy) noexcept							// Move assignment operator (Problem 3).
{
	std::cout << "Move assignment called." << std::endl;
	if (this != &copy)
	{
		this->p_vec = std::move(copy.p_vec);
	}
	return *this;
}
