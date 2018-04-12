/* Sealed.hpp (exercise 1.6.1)
Description:
	* Fix the provided code in the module exercise to enable instantiation of Base, Derived and Derived2 classes.
*/

#ifndef SEALED_HPP
#define SEALED_HPP

#include <iostream>

/* 1.6.1 */
// a) Fix the errors in the given code to allow classes to be instantiated:
struct Base 
{ 
	virtual void draw() 
	{ 
		std::cout << "print a base\n"; 
	} 
	// Added const version of above draw() method to ensure that 
	virtual void draw() const
	{

	}
	// Added virtual keyword to let compiler know that print() will be overriden in derived class:
	virtual void print() 
	{
	
	} 
	~Base() 
	{ 
		std::cout << "bye base\n"; 
	} 
};
struct Derived : public Base 
{ 
	Derived() 
	{
	
	} 
	void draw() override 
	{ 
		std::cout << "print a derived\n"; 
	} 
	void draw() const override 
	{
	
	} 
	void print() override 
	{
	
	} 
	~Derived() 
	{ 
		std::cout << "bye derived\n"; 
	} 
};

// Removed final keyword from Derived class to allow it to be inherited by further derived classes:
class Derived2 : public Derived 
{

};

#endif