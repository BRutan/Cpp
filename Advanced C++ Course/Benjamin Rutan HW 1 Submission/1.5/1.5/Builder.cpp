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

#include "Builder.hpp"

/////////////////////////////
// Constructors/Destructor:
/////////////////////////////
Builder::Builder() noexcept							/* Default constructor. */
{

}
Builder::Builder(const Builder &in) noexcept		/* Copy constructor. */
{

}
Builder::~Builder()									/* Destructor. */
{

}
/////////////////////////////
// Accessors + Mutators:
/////////////////////////////
std::tuple<ShapePointer, IODevicePointer> Builder::getProduct()	const noexcept													/* Return tuple containing the contained shape and device pointers. */
{
	return std::make_tuple<ShapePointer, IODevicePointer>(this->getShape(), this->getIODevice());
}
/////////////////////////////
// Overloaded Operators:
/////////////////////////////
Builder& Builder::operator=(const Builder &in) noexcept					/* Assignment operator. */
{
	if (this != &in)
	{
		
	}
	return *this;
}