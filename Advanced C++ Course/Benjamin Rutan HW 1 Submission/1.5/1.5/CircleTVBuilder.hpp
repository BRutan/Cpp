/* CircleTVBuilder.hpp (exercise 1.5.5)
Description:
	* Class that "builds" Circle class with a TV object. 
Member Functions:
	// Constructors/Destructor:
	*CircleTVBuilder(): default constructor. Does nothing since Builder has no state.
	*CircleTVBuilder(const CircleTVBuilder &): copy constructor. Does nothing since Builder has no state.
	*~CircleTVBuilder(): destructor.
	// Misc Functions
	ShapePointer getShape() const: return heap generated Circle, to be implemented in getProduct().
	IODevicePointer getIoDevice() const: return heap generated TV, to be implemented in getProduct().
	// Overloaded Operators
	CircleTVBuilder& operator=(const CircleTVBuilder&): assignment operator. Does nothing since Builder has no state.
*/

#ifndef CIRCLETVBUILDER_HPP
#define CIRCLETVBUILDER_HPP

#include <memory>
#include <tuple>
#include "Builder.hpp"
#include "Circle.hpp"
#include "TV.hpp"

class CircleTVBuilder : public Builder
{
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	CircleTVBuilder() noexcept;												/* Default Constructor. */
	explicit CircleTVBuilder(const CircleTVBuilder &) noexcept;				/* Copy Constructor. */
	virtual ~CircleTVBuilder() noexcept;									/* Destructor. */
	/////////////////////////////
	// Misc Functions:
	/////////////////////////////
	ShapePointer getShape() const noexcept;							/* Returns pointer to generated Circle object. */
	IODevicePointer getIODevice() const noexcept;					/* Returns pointer to generated TV object. */
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	CircleTVBuilder & operator=(const CircleTVBuilder &) noexcept;			/* Assignment operator. */
};

#endif