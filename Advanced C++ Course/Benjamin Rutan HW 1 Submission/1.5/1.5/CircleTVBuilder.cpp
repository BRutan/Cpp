/* CircleTVBuilder .hpp (exercise 1.5.5)
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

#include "CircleTVBuilder.hpp"

/////////////////////////////
// Constructors/Destructor:
/////////////////////////////
CircleTVBuilder::CircleTVBuilder() noexcept																	/* Default constructor. */
{

}
CircleTVBuilder::CircleTVBuilder(const CircleTVBuilder &in) noexcept : Builder(in)
{

}
CircleTVBuilder::~CircleTVBuilder()																			/* Destructor. */
{

}
/////////////////////////////
// Misc Functions:
/////////////////////////////
ShapePointer CircleTVBuilder::getShape() const noexcept						/* Returns pointer to generated Circle object. */
{
	return ShapePointer(new Circle());
}
IODevicePointer CircleTVBuilder::getIODevice() const noexcept				/*  Returns pointer to generated TV object. */
{
	return IODevicePointer(new TV());
}
/////////////////////////////
// Overloaded Operators:
/////////////////////////////
CircleTVBuilder& CircleTVBuilder::operator=(const CircleTVBuilder &in) noexcept			/* Assignment operator. */
{
	if (this != &in)
	{
		
	}
	return *this;
}