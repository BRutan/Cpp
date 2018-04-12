/* Builder.hpp (exercise 1.5.5)
Description:
	* Builder base class that "builds" derived Shape objects with derived IODevice objects.
Member Functions:
	// Constructors/Destructor:
	*Builder(): default constructor. Does nothing since Builder has no state.
	*Builder(const Builder&): copy constructor. Does nothing since Builder has no state.
	*~Builder(): destructor.
	// Misc Functions
	ShapePointer getShape() const: PVMF to be overwritten in derived builder classes. Return heap generated Circle, to be implemented in getProduct().
	IODevicePointer getIoDevice() const: PVMF to be overwritten in derived builder classes. Return heap generated TV, to be implemented in getProduct().
	// Overloaded Operators
	Builder& operator=(const Builder&): assignment operator. Does nothing since Builder has no state.
*/


#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <memory>
#include <tuple>
#include "IODevice.hpp"
#include "Shape.hpp"

using ShapePointer = std::shared_ptr<Shape>; 
using IODevicePointer = std::shared_ptr<IODevice>;

// A Builder hierarchy that builds shapes and io devices
class Builder 
{ 
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Builder() noexcept;										/* Default constructor. */
	Builder(const Builder&) noexcept;							/* Copy constructor. */
	virtual ~Builder();										/* Destructor. */ 
	/////////////////////////////
	// Misc Functions
	/////////////////////////////
	std::tuple<ShapePointer, IODevicePointer> getProduct() const noexcept; /* Return tuple containing the generated shape and device pointers. */
	virtual ShapePointer getShape() const noexcept = 0;					/* PVMF to be overloaded in derived classes. Returns pointer to Shape object. */
	virtual IODevicePointer getIODevice() const noexcept = 0;				/* PVMF to be overloaded in derived classes. Returns pointer to IODevice object. */
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	Builder& operator=(const Builder&) noexcept;			/* Assignment operator. */
};






#endif