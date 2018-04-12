/* CircleMonitorBuilder.hpp (exercise 1.5.5)
Description:
	* Class that "builds" Circle class with a Monitor object.
Member Functions:
	// Constructors/Destructor:
	*CircleMonitorBuilder(): default constructor. Does nothing since Builder has no state.
	*CircleMonitorBuilder(const CircleMonitorBuilder&): copy constructor. Does nothing since Builder has no state.
	*~CircleMonitorBuilder(): destructor.
	// Misc Functions
	ShapePointer getShape() const: return heap generated Circle, to be implemented in getProduct().
	IODevicePointer getIoDevice() const: return heap generated Monitor, to be implemented in getProduct().
	// Overloaded Operators
	CircleMonitorBuilder& operator=(const CircleMonitorBuilder&): assignment operator. Does nothing since Builder has no state.
*/

#ifndef CIRCLEMONIOTORBUILDER_HPP
#define CIRCLEMONIOTORBUILDER_HPP

#include "Builder.hpp"
#include "Circle.hpp"
#include "Monitor.hpp"

class CircleMonitorBuilder : public Builder
{
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	CircleMonitorBuilder() noexcept;												/* Default constructor. */
	explicit CircleMonitorBuilder(const CircleMonitorBuilder&) noexcept;			/* Copy constructor. */
	virtual ~CircleMonitorBuilder();								/* Destructor. */
	/////////////////////////////
	// Misc Functions:
	/////////////////////////////
	ShapePointer getShape() const noexcept;							/* Returns pointer to generated Circle object. */
	IODevicePointer getIODevice() const noexcept;					/* Returns pointer to generated Monitor object. */
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	CircleMonitorBuilder& operator=(const CircleMonitorBuilder&) noexcept;		/* Assignment operator. */
};

#endif
