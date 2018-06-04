/* Proposition.cpp (exercise 4.1.4)
Description:
	*


*/

#include "Proposition.hpp"

///////////////////////////
// Constructors/Destructor:
///////////////////////////
Proposition::Proposition() noexcept : data()
{

}
Proposition::Proposition(bool input) noexcept : data(input)
{

}
Proposition::Proposition(const std::bitset<1> &input) noexcept : data(input)
{

}
Proposition::Proposition(const Proposition &input) noexcept : data(input.data)
{

}
Proposition::~Proposition() noexcept
{

}
///////////////////////////
// Overloaded Operators:
///////////////////////////
Proposition Proposition::operator==(const Proposition &input) const noexcept
{
	return Proposition(this->data == input.data);
}
Proposition& Proposition::operator!=(const Proposition &input) noexcept
{
	if (this != &input)
	{
		this->data[0] != input.data[0];
	}
	return *this;
}
Proposition Proposition::operator&(const Proposition &input) const noexcept
{
	return Proposition(this->data[0] & input.data[0]);
}
Proposition Proposition::operator|(const Proposition &input) const noexcept
{
	return Proposition(this->data[0] | input.data[0]);
}
Proposition Proposition::operator^(const Proposition &input) const noexcept
{
	return Proposition(this->data[0] ^ input.data[0]);
}
Proposition& Proposition::operator=(const Proposition &input) noexcept
{
	if (this != &input)
	{
		data[0] = input.data[0];
	}
	return *this;
}
Proposition& Proposition::operator=(bool input) noexcept
{
	data[0] = input;
	return *this;
}
