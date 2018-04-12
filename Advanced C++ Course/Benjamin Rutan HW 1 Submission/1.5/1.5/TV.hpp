/* TV.hpp (exercise 1.5.5)
Description:
	* Base class to display different derived Shape classes.
Member Functions:
	// Constructors/Destructor:
	*Monitor(): default constructor.
	*Monitor(const string&): overloaded constructor.
	*Monitor(const Monitor&): copy constructor.
	*~Monitor(): destructor.
	// Overloaded Operators:
	*void operator<<(const Circle&) const: Display Circle object on monitor.
	*void operator<<(const Line&) const: Display Line object on monitor.
	*void operator<<(const Point&) const: Display Point object on monitor.
*/


#ifndef TV_HPP
#define TV_HPP

#include <iostream>
#include "Circle.hpp"
#include "IODevice.hpp"
#include "Line.hpp"
#include "Point.hpp"

class TV : public IODevice
{
public:
	///////////////////////////
	// Constructors/Destructor: 
	///////////////////////////
	TV() noexcept : IODevice("TV")					/* Default constructor. */
	{

	}
	TV(const TV &in) : IODevice(in)					/* Copy constructor. */
	{

	}
	TV(TV && in) : IODevice(std::move(in))			/* Move constructor. */
	{

	}
	virtual ~TV() noexcept override					/* Destructor. */
	{

	}
	///////////////////////////
	// Overloaded Operators: 
	///////////////////////////
	void operator << (const Circle &in) const noexcept override			/* Display Circle object on TV. */
	{
		std::cout << "Displayed on " << IODevice::ToString() << ": " << in.ToString() << std::endl;
	}
	void operator << (const Line &in) const noexcept override			/* Display Line object on TV. */
	{
		std::cout << "Displayed on " << IODevice::ToString() << ": " << in.ToString() << std::endl;
	}
	void operator << (const Point& in) const noexcept override			/* Display Point object on TV. */
	{
		std::cout << "Displayed on " << IODevice::ToString() << ": " << in.ToString() << std::endl;
	}
};

#endif