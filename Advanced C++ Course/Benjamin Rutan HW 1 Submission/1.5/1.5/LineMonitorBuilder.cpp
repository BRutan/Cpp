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

#include "LineMonitorBuilder.hpp"

/////////////////////////////
// Constructors/Destructor:
/////////////////////////////
LineMonitorBuilder::LineMonitorBuilder() noexcept										/* Default constructor. */
{

}
LineMonitorBuilder::LineMonitorBuilder(const LineMonitorBuilder &in) noexcept			/* Copy constructor. */
{

}
LineMonitorBuilder::~LineMonitorBuilder()									/* Destructor. */
{

}
/////////////////////////////
// Misc Functions:
/////////////////////////////
ShapePointer LineMonitorBuilder::getShape() const noexcept							/* Returns pointer to generated Line object. */
{
	return ShapePointer(new Line());
}
IODevicePointer LineMonitorBuilder::getIODevice() const noexcept					/* Returns pointer to generated Monitor object. */
{
	return IODevicePointer(new Monitor());
}
/////////////////////////////
// Overloaded Operators:
/////////////////////////////
LineMonitorBuilder& LineMonitorBuilder::operator=(const LineMonitorBuilder &in) noexcept		/* Assignment operator. */
{
	if (this != &in)
	{

	}
	return *this;
}
