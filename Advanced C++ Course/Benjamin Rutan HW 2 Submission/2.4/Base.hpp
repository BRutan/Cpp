/* Base.hpp (exercise 2.4.4)
Description:
	* Base class to be implemented in Main.cpp in list.
*/

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{ 
// Base class
private:
public:
	Base() { }
	virtual void print() const = 0;
protected:
	virtual ~Base() 
	{ 
		std::cout << "Base destructor\n\n"; 
	}
};

class Derived : public Base
{ 
// Derived class
private:
public:
	Derived() : Base() 
	{ 

	}
	~Derived() 
	{ 
		std::cout << "Derived destructor\n"; 
	}
	void print() const 
	{ 
		std::cout << "derived object\n"; 
	}
};

#endif
