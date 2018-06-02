/* Proposition.hpp (exercise 4.1.1)
Description:
	*




*/




#ifndef PROPOSITION_HPP
#define PROPOSITION_HPP

#include <bitset>
#include <iostream>

class Proposition
{
private:
	std::bitset<1> data;
public:
	///////////////////////////
	// Constructors/Destructor:
	///////////////////////////
	Proposition() noexcept;
	Proposition(bool) noexcept;
	Proposition(const std::bitset<1>&) noexcept;
	Proposition(const Proposition&) noexcept;
	virtual ~Proposition() noexcept;
	///////////////////////////
	// Overloaded Operators:
	///////////////////////////
	explicit operator bool() const noexcept
	{
		return this->data[0];
	}
	Proposition operator==(const Proposition&) const noexcept;
	Proposition& operator!=(const Proposition&) noexcept;
	Proposition operator&(const Proposition&) const noexcept;
	Proposition operator|(const Proposition&) const noexcept;
	Proposition operator^(const Proposition&) const noexcept;
	Proposition& operator=(const Proposition&) noexcept;
	Proposition& operator=(bool) noexcept;
	friend bool operator<(const Proposition &A, const Proposition &B)
	{
		return A.data[0] < B.data[0];
	}
	friend Proposition operator%(const Proposition &A, const Proposition &B) noexcept
	{
		return Proposition(!A | B);
	}
	friend Proposition operator%=(const Proposition &A, const Proposition &B) noexcept
	{
		return Proposition((A % B)&(B % A));
	}
	friend Proposition operator!(const Proposition &A) noexcept
	{
		return !A.data[0];
	}
	friend std::ostream& operator<<(std::ostream &out, const Proposition &in) noexcept
	{
		out << in.operator bool();
		return out;
	}
};

#endif
