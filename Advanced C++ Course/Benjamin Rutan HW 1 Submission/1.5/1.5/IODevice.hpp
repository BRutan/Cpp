/* IODevice.hpp (exercise 1.5.5)
Description:
	* Base class to display different derived Shape classes.
State Variables/Objects:
	*string name: name of the input-output device.
Member Functions:
	// Constructors/Destructor:
	*IODevice(): default constructor.
	*IODevice(const IODevice&): copy constructor.
	*~IODevice(): destructor.
	// Getters:
	*string ToString() const: return the name of the iodevice.
	// Overloaded Operators:
	*void operator<<(const Circle&) const: PVMF to be overridden in derived classes. 
	*void operator<<(const Line&) const: PVMF to be overridden in derived classes.
	*void operator<<(const Point&) const: PVMF to be overridden in derived classes.
*/


#ifndef IODEVICE_HPP
#define IODEVICE_HPP

#include <string>

// Forward declarations for used classes to overcome circular dependency issue:

class Circle;
class Line;
class Point;


// Base class for Interface for displaying CAD objects
class IODevice 
{ 
private:
	///////////////////////////
	// State Variables:
	///////////////////////////
	std::string name;
public: 
	///////////////////////////
	// Constructors/Destructor:
	///////////////////////////
	IODevice() noexcept : name()												/* Default constructor. */
	{

	}
	IODevice(const std::string &in) : name(in)									/* Overloaded constructor. */
	{

	}
	IODevice(const IODevice &in) noexcept : name(in.name)						/* Copy constructor. */
	{

	}
	IODevice(IODevice &&in) noexcept : name(std::move(in.name))					/* Move copy constructor. */
	{

	}
	virtual ~IODevice() noexcept										/* Destructor. */
	{

	}
	///////////////////////////
	// Getters:
	///////////////////////////
	std::string ToString() const noexcept								/* Return name of iodevice. */
	{
		return name;
	}
	///////////////////////////
	// Overloaded Operators:
	///////////////////////////
	virtual void operator << (const Circle& in) const noexcept = 0;
	virtual void operator << (const Line& in) const noexcept = 0;
	virtual void operator << (const Point& in) const noexcept = 0;
};

#endif