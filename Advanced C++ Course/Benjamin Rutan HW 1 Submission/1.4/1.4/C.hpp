/* C.hpp (exercise 1.4.3)
Description:
	* Solution to exercise 1.4.3.
State Variables/Objects:
	*double _data: stored double.
Member Functions:
	// Constructors/Destructor:
	*C(const double & data): overloaded constructor, sets stored _data.
	// Misc. Methods:
	*double translate(const double &factor) const: return copy of stored data plus the factor.
	*double translate2(const double&, const double&) const: return copy of stored data plus two passed factors.
	*static double Square(const double&): return copy of factor * factor.
	// Overloaded Operators:
	*double operator()(const double&): return copy of _data + passed factor.
*/

#ifndef C_HPP
#define C_HPP

/* 1.4.3: Modify the member functions to conform to FunctionType<double> (alias for std::function) <*/

class C 
{ // Function object with extra member functions
private: 
	double _data; 
public: 
 	C(const double &data) : _data(data) {}
	double operator () (const double &factor) const
	{ 
		return _data + factor; 
	}
	double translate(const double &factor) const
	{ 
		return _data + factor; 
	}
	double translate2(const double &factor1, const double &factor2) const
	{ 
		return _data + factor1 + factor2; 
	} 
	static double Square(const double &x) 
	{ 
		return x * x; 
	}
};

#endif
