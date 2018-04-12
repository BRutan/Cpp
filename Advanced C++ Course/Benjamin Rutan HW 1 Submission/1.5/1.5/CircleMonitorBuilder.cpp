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

#include "CircleMonitorBuilder.hpp"

/////////////////////////////
// Constructors/Destructor:
/////////////////////////////
CircleMonitorBuilder::CircleMonitorBuilder() noexcept										/* Default constructor. */
{

}
CircleMonitorBuilder::CircleMonitorBuilder(const CircleMonitorBuilder &in) noexcept			/* Copy constructor. */
{

}
CircleMonitorBuilder::~CircleMonitorBuilder()									/* Destructor. */
{

}
/////////////////////////////
// Misc Functions:
/////////////////////////////
ShapePointer CircleMonitorBuilder::getShape() const noexcept						/* Returns pointer to generated Circle object. */
{
	return ShapePointer(new Circle());
}
IODevicePointer CircleMonitorBuilder::getIODevice() const noexcept					/* Returns pointer to generated Monitor object. */
{
	return IODevicePointer(new Monitor());
}
/////////////////////////////
// Overloaded Operators:
/////////////////////////////
CircleMonitorBuilder& CircleMonitorBuilder::operator=(const CircleMonitorBuilder &in) noexcept		/* Assignment operator. */
{
	if (this != &in)
	{

	}
	return *this;
}
