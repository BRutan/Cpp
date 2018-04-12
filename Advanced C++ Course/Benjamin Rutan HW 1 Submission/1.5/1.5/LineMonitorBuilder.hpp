/* LineMonitorBuilder.hpp (exercise 1.5.5)
Description:
	* Class that "builds" Line class with a Monitor object.
Member Functions:
	// Constructors/Destructor:
	*LineMonitorBuilder(): default constructor. Does nothing since Builder has no state.
	*LineMonitorBuilder(const LineMonitorBuilder&): copy constructor. Does nothing since Builder has no state.
	*~LineMonitorBuilder(): destructor.
	// Misc Functions
	ShapePointer getShape() const: return heap generated Line, to be implemented in getProduct().
	IODevicePointer getIoDevice() const: return heap generated Monitor, to be implemented in getProduct().
	// Overloaded Operators
	LineTVBuilder& operator=(const LineTVBuilder&): assignment operator. Does nothing since Builder has no state.
*/

#ifndef LINEMONITORBUILDER_HPP
#define LINEMONITORBUILDER_HPP

#include "Builder.hpp"
#include "Line.hpp"
#include "Monitor.hpp"

class LineMonitorBuilder : public Builder
{
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	LineMonitorBuilder() noexcept;												/* Default constructor. */
	explicit LineMonitorBuilder(const LineMonitorBuilder&) noexcept;			/* Copy constructor. */
	virtual ~LineMonitorBuilder();									/* Destructor. */
	/////////////////////////////
	// Misc Functions:
	/////////////////////////////
	ShapePointer getShape() const noexcept;							/* Returns pointer to Line object. */
	IODevicePointer getIODevice() const noexcept;					/* Returns pointer to Monitor object. */
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	LineMonitorBuilder& operator=(const LineMonitorBuilder&) noexcept;		/* Assignment operator. */
};

#endif
