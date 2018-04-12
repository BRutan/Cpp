/* LineTVBuilder.cpp (exercise 1.5.5)
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

#include "LineTVBuilder.hpp"

LineTVBuilder::LineTVBuilder() noexcept										/* Default constructor. */
{
	
}
LineTVBuilder::LineTVBuilder(const LineTVBuilder &in) noexcept				/* Copy constructor. */
{

}
LineTVBuilder::~LineTVBuilder()												/* Destructor. */
{

}
/////////////////////////////
// Mutator + Accessors:
/////////////////////////////
ShapePointer LineTVBuilder::getShape() const noexcept								/* Returns pointer to generated Line object. */
{
	return ShapePointer(new Line());
}
IODevicePointer LineTVBuilder::getIODevice() const noexcept					/* Returns pointer to generated TV object. */
{
	return IODevicePointer(new TV());
}
/////////////////////////////
// Overloaded Operators:
/////////////////////////////
LineTVBuilder& LineTVBuilder::operator=(const LineTVBuilder& in) noexcept		/* Assignment operator. */
{
	if (this != &in)
	{
	
	}
	return *this;
}