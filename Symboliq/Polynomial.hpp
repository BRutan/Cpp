/* Polynomial.hpp TODO : Consider using polymorphism with PolyLinkedList 
Description:




*/

#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include"PolyLinkedList.hpp"
#include"TypeDefs.hpp"

namespace Symboliq
{
	class Polynomial
	{
	private:
		////////////////////////////////
		// State Variables:
		////////////////////////////////
		PolyLinkedList CoreList;										// Linked list of polynomial terms (composition).
		std::vector<char> possSymbols;									// Vector of possible symbols the Polynomial can have.
		unsigned long long levelPrecision;								// Level of decimal precision for display purposes.
		void Convert(const std::string&);								// Convert passed string into a Polynomial.
	public:
		////////////////////////////////
		// Constructors/Destructor:
		////////////////////////////////
		Polynomial();													// Default constructor. 
		Polynomial(const Polynomial&);									// Copy constructor. 
		Polynomial(const CharVector&);									// Overloaded constructor. User passes vector of possible symbols for the polynomial. 
		Polynomial(const char[]);										// Overloaded constructor. User passes an array of possible symbols for the polynomial. 
		explicit Polynomial(const std::string&);						// Explicit conversion constructor.
		virtual ~Polynomial();											// Destructor.
		////////////////////////////////
		// Mutators:
		////////////////////////////////
		void Precision(ULL);								// Change the decimal precision of Corestring printout.  
		////////////////////////////////
		// Accessors:
		////////////////////////////////
		unsigned long long NumTerms() const;							// Return number of terms in the Polynomial.
		unsigned long long Precision() const;							// Return levelPrecision.
		std::string ToString() const;									// Return Polynomial in string form to user.
		////////////////////////////////
		// Misc Methods:
		////////////////////////////////
		LDoubleVector FindRoots(const LDoubleVector&, const LDoubleVector&) const;	// Find roots of polynomial in a given coordinate range. 
		// TODO: use template.
		long double f(const ValueMap&) const;			// Function operator. Return element of co-domain mapped to passed vector.
		////////////////////////////////
		// Overloaded Operators:
		////////////////////////////////
		// Assignment:
		std::string& operator=(const std::string&);						// Polynomial assignment operator via string. Assumes correct symbols are in string. Will discard irrelevant symbols.
		Polynomial& operator=(const Polynomial&);						// Polynomial assignment operator via Polynomial.
		// Arithmetic:
		Polynomial operator+(const Polynomial&) const;					// Polynomial addition. 
		Polynomial operator+(long double) const;						// Add scalar.
		Polynomial operator-(const Polynomial&) const;					// Polynomial subtraction or negation.
		Polynomial operator-(long double) const;						// Subtract by scalar.
		Polynomial operator*(const Polynomial&) const;					// Polynomial multiplication.
		Polynomial operator*(long double) const;						// Multiply by scalar.
		Polynomial operator/(const Polynomial&) const;					// Polynomial division.
		Polynomial operator/(long double) const;						// Polynomial division.
		// Reflexive arithmetic:
		void operator++();												// A++ Polynomial postfix increment.
		void operator--();												// A-- Polynomial postfix decrement.
		void operator+=(const Polynomial&);								// Polynomial reflexive increment passed Polynomial.
		void operator+=(long double);									// Polynomial reflexive increment by passed numeric.
		void operator-=(const Polynomial&);								// Polynomial reflexive decrement by passed numeric.
		void operator-=(long double);					                // Polynomial reflexive decrement by passed numeric.
		void operator*=(const Polynomial&);								// Polynomial reflexive multiply by Polynomial.
		void operator*=(long double);					                // Polynomial reflexive multiply by scalar.
		void operator/=(const Polynomial&);								// Polynomial divide self by n.
		void operator/=(long double);									// Polynomial divide self by scalar.
		// Calculus:

		// Boolean compares:
		bool operator==(const Polynomial&) const;						// Polynomial logical equality.
		bool operator!=(const Polynomial&) const;						// Polynomial logical inequality.
		// Friend non-member operators:
		friend Polynomial operator-(const Polynomial &poly_in)			// Polynomial negation. 
		{
			return -poly_in.CoreList;
		}
		friend Polynomial operator++(const Polynomial &poly_in)			// Polynomial prefix increment by one.
		{
			return poly_in + 1;
		}
		friend Polynomial operator--(const Polynomial &poly_in)			// Polynomial prefix decrement by one.
		{
			return poly_in - 1;
		}
	};
	/////////////////////////////////////
	// Overloaded Operators (non-member):
	/////////////////////////////////////
	// IOstream operators:
	std::ostream& operator<<(std::ostream& os, const Polynomial& poly_in)	// Outstream operator.
	{
		os << poly_in.ToString();
		return os;
	}
	std::istream& operator>>(std::istream& is, Polynomial& poly_in)			// Instream operator.
	{
		std::string toConvert;
		is >> toConvert;
		poly_in = toConvert;
		return is;
	}
};
#endif