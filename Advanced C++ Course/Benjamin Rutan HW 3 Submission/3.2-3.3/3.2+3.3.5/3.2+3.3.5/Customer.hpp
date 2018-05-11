/* Customer.hpp (exercise 3.2+3.3.5)
Description:
	* Producer class in the Barbershop problem.




*/


#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <chrono>
#include <iostream>
#include <mutex>


class Customer
{
private:
	std::mutex *mut;
public:
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	Customer(std::mutex mut_in) : mut(&mut_in)
	{

	}
	Customer(const Customer&) = delete;
	virtual ~Customer()
	{

	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	void operator()()
	{

	}
};



#endif
