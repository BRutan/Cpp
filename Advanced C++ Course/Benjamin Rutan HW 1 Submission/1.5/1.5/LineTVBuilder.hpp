/* LineTVBuilder.hpp (exercise 1.5.5)
Description:
	* Class that "builds" Line class with a TV object.
Member Functions:
	// Constructors/Destructor:
	*LineTVBuilder(): default constructor. Does nothing since Builder has no state.
	*LineTVBuilder(const LineTVBuilder&): copy constructor. Does nothing since Builder has no state.
	*~LineTVBuilder(): destructor.
	// Misc Functions
	ShapePointer getShape() const: return heap generated Circle, to be implemented in getProduct().
	IODevicePointer getIoDevice() const: return heap generated TV, to be implemented in getProduct().
	// Overloaded Operators
	LineTVBuilder& operator=(const LineTVBuilder&): assignment operator. Does nothing since Builder has no state.
*/

#ifndef LINETVBUILDER_HPP
#define LINETVBUILDER_HPP

#include "Builder.hpp"
#include "Line.hpp"
#include "TV.hpp"

class LineTVBuilder : public Builder
{
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	LineTVBuilder() noexcept;										/* Default constructor. */
	explicit LineTVBuilder(const LineTVBuilder&) noexcept;			/* Copy constructor. */
	virtual ~LineTVBuilder();										/* Destructor. */
	/////////////////////////////
	// Accessors + Mutators:
	/////////////////////////////
	ShapePointer getShape() const noexcept;							 /* Returns pointer to generated Line object. */
	IODevicePointer getIODevice() const noexcept;					 /* Returns pointer to generated TV object. */
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	LineTVBuilder& operator=(const LineTVBuilder&) noexcept;		/* Assignment operator. */
};

#endif
