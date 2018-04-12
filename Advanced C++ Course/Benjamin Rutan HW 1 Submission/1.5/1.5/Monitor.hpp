/* Monitor.hpp (exercise 1.5.5)
Description:
	* Base class to display different derived Shape classes.
State Variables/Objects:
	*string name: name of the input-output device.
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
#ifndef MONITOR_HPP
#define MONITOR_HPP

#include <iostream>
#include "IODevice.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"

class Monitor : public IODevice
{
public:
	///////////////////////////
	// Constructors/Destructor: 
	///////////////////////////
	Monitor() noexcept : IODevice("Monitor")						/* Default constructor. */
	{

	}
	Monitor(const Monitor &in) noexcept : IODevice(in)				/* Copy constructor. */
	{

	}
	Monitor(Monitor &&in) : IODevice(std::move(in))					/* Move copy constructor. */
	{

	}
	virtual ~Monitor() override										/* Destructor. */
	{

	}
	///////////////////////////
	// Overloaded Operators: 
	///////////////////////////
	void operator << (const Circle &in) const noexcept override		/* Display Circle on Monitor. */
	{
		std::cout << "Displayed on " << IODevice::ToString() << ": " << in.ToString() << std::endl;
	}
	void operator << (const Line &in) const noexcept override		/* Display Line on Monitor. */
	{
		std::cout << "Displayed on " << IODevice::ToString() << ": " << in.ToString() << std::endl;
	}
	void operator << (const Point& in) const noexcept override		/* Display Point on Monitor. */
	{
		std::cout << "Displayed on " << IODevice::ToString() << ": " << in.ToString() << std::endl;
	}
};

#endif
