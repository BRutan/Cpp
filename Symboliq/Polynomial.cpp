/* Polynomial.cpp 


*/
#include <algorithm>
#include"DimMismatch.hpp"
#include"FormatExcept.hpp"
#include"Polynomial.hpp"
#include"TypeDefs.hpp"

namespace Symboliq
{
	////////////////////////////////
	// Misc. Private Functions:
	////////////////////////////////
	void Polynomial::Convert(const std::string &str_in)
	{
		if (!possSymbols.size())  // If no symbols loaded, throw exception.
		{
			throw - 1;
		}
		std::strstream ss;
		if (str_in.size() >= MAXPOLYSTRINGSIZE) // If number of characters greater than max size, throw exception.
		{
			ss << MAXPOLYSTRINGSIZE << '\0';
			throw - 1; // Exceptions::PolynomialException("Polynomial Conversion Error: String is too long (Max currently is " + ss.str() + " chars).");
		}
		std::vector<char> validSymbols;
		std::vector<char> badSymbols;
		validSymbols.push_back('+');
		validSymbols.push_back('-');
		validSymbols.push_back('/');
		validSymbols.push_back('*');
		validSymbols.push_back('^');
		ULL i = 0, braces = 0;
		/////////////////////////////////////////
		// Pass 1: checking for invalid symbols and unmatched braces ONLY:
		/////////////////////////////////////////
		while(i != str_in.size())
		{
			while (isspace(str_in[i]) && i < str_in.size())
			{
				i++;
			}
			if (std::find(possSymbols.begin(), possSymbols.end(), str_in[i]) == possSymbols.end() || // Check if char is a polynomial dimension symbol.
				std::find(validSymbols.begin(), validSymbols.end(), str_in[i]) == validSymbols.end()) // Check if char is an operator/arithmetic symbol.
			{
				badSymbols.push_back(str_in[i]); // Add to vector for exception if symbol is invalid.
			}
			// Check for unmatched braces:
			if (str_in[i] == '(')
			{
				braces++;
				i++;
			}
			else if (str_in[i] == ')' )
			{
				// Throw exception if unmatched braces.
				if (braces == 0) 
				{
					throw - 1;
				}
				else
				{
					braces--; 
					i++;
				}
			}
		}
		/////////////////////////////////////////
		// Pass 2: Checking for proper formatting:
		/////////////////////////////////////////
		i = 0;
		while (i != str_in.size())
		{

		}
		// Now that we know the string is formatted correctly, proceed with conversion to Polynomial:
		// Clear contents to overwrite:
		CoreList.Clear();
		std::strstream tempStr;
		ULL tempIndex;
		i = 0;
		while(i != str_in.size())
		{
			if (isspace(str_in[i]))
			{
				i++;
			}
			if (std::find(possSymbols.begin(), possSymbols.end(), str_in[i]) != possSymbols.end()) // If character is a symbol, get the coefficient.
			{
				tempIndex = i + 1;
				i--;
				if (isspace(str_in[i])) // Coefficients are allowed to be followed by a single space ONLY.
				{
					i--;
				}
				// Get the coefficient:
				while ((isdigit(str_in[i]) || str_in[i] == '.') && i >= 0) 
				{
					i--;
				}
				while (i < tempIndex)
				{
					tempStr << str_in[i];
				}
				i = tempIndex;
				while ((std::find(possSymbols.begin(), possSymbols.end(), str_in[i]) != possSymbols.end() || 
					    std::find(validSymbols.begin(), validSymbols.end(), str_in[i]) != validSymbols.end() ||
					    isdigit(str_in[i])) && i < str_in.size())
				{
					tempStr << str_in[i];
					i++;
				}
				// Pass the temporary string to the PolyLinkedList Converter:
				tempStr << '\0';
				CoreList.Append(tempStr.str(), possSymbols);
				i++;
			}
		}
	}

	////////////////////////////////
	// Constructors/Destructor:
	////////////////////////////////
	Polynomial::Polynomial() : CoreList(), levelPrecision(3)								// Default constructor. Creates empty Polynomial.
	{

	}
	Polynomial::Polynomial(const Polynomial& poly_in) : CoreList(poly_in.CoreList), // Copy constructor. 
		levelPrecision(poly_in.levelPrecision)
	{

	}
	Polynomial::Polynomial(const std::string &string_in)				   // Explicit conversion constructor. Converts passed string into a Polynomial.
	{
		Convert(string_in);
	}
	Polynomial::Polynomial(const CharVector &vec_in) : CoreList(), // TODO Overloaded constructor. User passes a vector of possible symbols for the polynomial. 
		levelPrecision()
	{

	}
	Polynomial::Polynomial(const char[]) : CoreList(),				  // TODO Overloaded constructor. User passes a vector of possible symbols for the polynomial. 
		levelPrecision()
	{

	}
	Polynomial::~Polynomial()											  // Destructor.
	{

	}
	////////////////////////////////
	// Mutators:
	////////////////////////////////
	void Polynomial::Precision(ULL new_precision)  	 // Change the decimal precision of Corestring printout.  
	{
		levelPrecision = new_precision;
	}
	////////////////////////////////
	// Accessors:
	////////////////////////////////
	ULL Polynomial::NumTerms() const					// Return number of terms in Polynomial.
	{
		return CoreList.Size();
	}
	ULL Polynomial::Precision() const					// Return levelPrecision.
	{
		return levelPrecision;
	}
	std::string Polynomial::ToString() const							// Return Polynomial in string form to user.
	{
		return CoreList.ToString();
	}
	////////////////////////////////
	// Misc. Methods:
	////////////////////////////////
	LDoubleVector Polynomial::FindRoots(const LDoubleVector&, const LDoubleVector&) const	// Find roots of polynomial in a given coordinate range.
	{
		// Use Newton's method:

	}
	// TODO: Implement means to ensure proper ordering of dimensions (potentially a method that elaborates symbol order).
	long double Polynomial::f(const ValueMap&) const			// Function operator. Return element of co-domain mapped to passed vector.
	{

	}
	////////////////////////////////
	// Overloaded Operators:
	////////////////////////////////
	// Assignment:
	std::string& Polynomial::operator=(const std::string &str_in)			// Polynomial assignment operator via string. Assumes correct symbols are in string. Will discard irrelevant symbols.
	{
		Convert(str_in);
		return ToString();
	}
	Polynomial& Polynomial::operator=(const Polynomial &poly_in)	// Polynomial assignment operator via Polynomial.
	{
		if (this != &poly_in)
		{
			CoreList = poly_in.CoreList;
			levelPrecision = poly_in.levelPrecision;
		}
		return *this;
	}
	// Arithmetic:
	Polynomial Polynomial::operator+(const Polynomial &poly_in) const				// Polynomial addition.
	{
		Polynomial temp(*this);
		temp.CoreList = temp.CoreList + poly_in.CoreList;
		return temp;
	}
	Polynomial Polynomial::operator+(long double scal_in) const						// Add scalar.
	{
		Polynomial temp(*this);
		temp.CoreList = temp.CoreList + scal_in;
		return temp;
	}
	Polynomial Polynomial::operator-(const Polynomial &poly_in) const				// Polynomial subtraction.
	{
		Polynomial temp(*this);
		temp.CoreList = temp.CoreList - poly_in.CoreList;
		return temp;
	}
	Polynomial Polynomial::operator-(long double scal_in) const						// Subtract scalar.
	{
		Polynomial temp(*this);
		temp.CoreList = temp.CoreList - scal_in;
		return temp;
	}
	Polynomial Polynomial::operator*(const Polynomial &poly_in) const				// Polynomial multiplication.
	{
		Polynomial temp(*this);
		temp.CoreList = temp.CoreList * poly_in.CoreList;
		return temp;
	}
	Polynomial Polynomial::operator*(long double scal_in) const						// Polynomial multiplication.
	{
		Polynomial temp(*this);
		temp.CoreList = temp.CoreList * scal_in;
		return temp;
	}
	Polynomial Polynomial::operator/(const Polynomial &poly_in) const				// Polynomial division.
	{
		Polynomial temp(*this);
		temp.CoreList = temp.CoreList / poly_in.CoreList;
		return temp;
	}
	Polynomial Polynomial::operator/(long double scal_in) const						// Polynomial division.
	{
		Polynomial temp(*this);
		temp.CoreList = temp.CoreList / scal_in;
		return temp;
	}
	// Reflexive arithmetic:
	void Polynomial::operator++()								// A++ Polynomial postfix increment.
	{
		CoreList = CoreList + 1;
	}
	void Polynomial::operator--()								// A-- Polynomial postfix decrement.
	{
		CoreList = CoreList - 1;
	}
	void Polynomial::operator+=(const Polynomial &poly_in)			// Polynomial reflexive increment passed Polynomial.
	{
		CoreList = CoreList + poly_in.CoreList;
	}
	void Polynomial::operator+=(long double scal_in)					// Polynomial reflexive increment by passed numeric.
	{
		CoreList = CoreList + scal_in;
	}
	void Polynomial::operator-=(const Polynomial &poly_in)			// Polynomial reflexive decrement by passed numeric.
	{
		CoreList = CoreList - poly_in.CoreList;
	}
	void Polynomial::operator-=(long double scal_in)					// Polynomial reflexive decrement by passed numeric.
	{
		CoreList = CoreList - scal_in;
	}
	void Polynomial::operator*=(const Polynomial &poly_in)			// Polynomial reflexive multiply by Polynomial.
	{
		CoreList = CoreList * poly_in.CoreList;
	}
	void Polynomial::operator*=(long double scal_in)					// Polynomial reflexive multiply by scalar.
	{
		CoreList = CoreList * scal_in;
	}
	void Polynomial::operator/=(const Polynomial &poly_in)			// Polynomial divide self by another Polynomial.
	{
		CoreList = CoreList / poly_in.CoreList;
	}
	void Polynomial::operator/=(long double scal_in)			// Polynomial divide self by scalar.
	{
		CoreList = CoreList / scal_in;
	}
	// Boolean compares:
	bool Polynomial::operator==(const Polynomial &poly_in) const		// Polynomial logical equality.
	{
		return CoreList == poly_in.CoreList;
	}
	bool Polynomial::operator!=(const Polynomial &poly_in) const		// Polynomial logical inequality.
	{
		return CoreList != poly_in.CoreList;
	}
}