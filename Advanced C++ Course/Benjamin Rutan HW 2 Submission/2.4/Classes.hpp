/* Classes.hpp (exercise 2.4.2)
Description:
	* Test the shared_ptr smart pointer class.
*/

#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <memory>
#include "Point.hpp"

class C1 
{
private: 
	//double* d; OLD WAY 
	std::shared_ptr<Point> d; 
public: 
	C1(std::shared_ptr<Point> value) : d(value) 
	{

	} 
	virtual ~C1() 
	{ 
		std::cout << "\nC1 destructor\n";
	} 
	void print() const 
	{ 
		std::cout << "Value " << *d; 
	} 
};

class C2 
{
private:
	//double* d; OLD WAY 
	std::shared_ptr<Point> d;
public:
	C2(std::shared_ptr<Point> value) : d(value)
	{

	}
	virtual ~C2()
	{
		std::cout << "\nC1 destructor\n";
	}
	void print() const
	{
		std::cout << "Value " << *d;
	}
};

　
#endif
