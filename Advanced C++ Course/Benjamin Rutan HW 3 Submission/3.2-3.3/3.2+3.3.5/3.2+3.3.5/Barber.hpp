/* Barber.hpp (exercise 3.2+3.3.5)
Description:
	* 


*/



#ifndef BARBER_HPP
#define BARBER_HPP

#include <iostream>
#include <mutex>


class Barber
{
private:
	std::mutex *mut;
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Barber(std::mutex mut_in) : mut(&mut_in)
	{

	}
	virtual ~Barber()
	{

	}
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	void operator()()
	{

	}

};


#endif
