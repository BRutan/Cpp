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
#ifndef C_HPP
#define C_HPP

#include <iostream>
#include <vector>

class C
{
private:
	std::vector<double> p_vec;
	explicit C(const C&) noexcept = delete;			// Setting copy constructor to private (Problem 1) .
	C& operator=(const C&) noexcept = delete;		// Setting assignment operator to private (Problem 1).
public:
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	C() noexcept = default;							// Default constructor implemented by compiler (using default keyword).
	explicit C(C&&) noexcept;					// Move-semantics copy constructor (Problem 3).
	~C() noexcept;									// Destructor.
	////////////////////////////
	// Member functions:
	////////////////////////////
	void push_back(double) noexcept;				// Prepend passed value to p_vec.
	void print() const noexcept;					// Print all values in p_vec.
	void setElement(unsigned, double);				// Set element at index's value (order is (index, value))
	double getElement(unsigned) const;				// Get element at passed index.
	void scale(double) noexcept;					// Multiply each element in p_vec by a scaling factor.
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	C& operator=(C&&) noexcept;				// Move assignment operator (Problem 3).  
	
};

#endif