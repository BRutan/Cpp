/* Option.cpp
-Description:
	*Base class for derived option classes (AmericanPerpetualOption, EuropeanOption, etc).
-State Variables:
	*map<string, double> params: associative container for each variable used in option pricing (s, k, t, r, b, sigma).
	*bool isCall: true if Call, false if Put.
-Member Functions:
	// Constructors:
	*Option(): Default constructor. Set all parameters to 0.
	*Option(double, double, double, double, double, double, bool): Set parameters to corresponding passed values.
	*Option(const Option&): Copy constructor.
	// Accessors:
	*bool Type(): Return type of option (true means Call, false means Put).
	*double Param(string): Return passed parameter's value.
	// Mutators:
	*void TypeToggle(): Switch option to alternate type.
	*void Param(string, double): Set parameter to new passed value.
	// Misc Methods:
	*long double FiniteDiffApprox(string, double, unsigned, double): Calculate Nth order approximation (n <= 66) for option Greek.
	*virtual double Price() const: PVMF, make Option an abstract base class.
	*string Parameters() const: Return string detail of parameters and their values.
*/

#include<map>
#include<string>
#include<strstream>
#include"Option.hpp"
#include"OptionExcept.hpp"

namespace Options
{
	//////////////////////////
	// Accessors:
	//////////////////////////
	Option::Option(double t, double s, double k, double b, double r, double sigma, bool isCall_in):	/* Overloaded Constructor. Set all parameters. */
		isCall(isCall_in)
	{
		if (t <= 0 || s <= 0 || k <= 0 || sigma <= 0)
		{
			throw Exceptions::OptionExcept("Option Constructor Error: All parameters (except b and r) must be > 0.");
		}
		// Place parameters with associative key into params map:
		params.emplace("t", t);
		params.emplace("s", s);
		params.emplace("k", k);
		params.emplace("b", b);
		params.emplace("r", r);
		params.emplace("sigma", sigma);
	}
	Option::Option(const Option &in) : params(in.params), isCall(in.isCall) /* Copy Constructor. */
	{

	}
	Option::~Option()							/* Destructor. */
	{

	}
	//////////////////////////
	// Accessors:
	//////////////////////////
	bool Option::Type() const					/* Return type (Call/Put). */
	{
		return isCall;
	}
	double Option::Param(const std::string &key) const
	{
		try
		{
			return params.at(key); // Throws out_of_range exception if key is not initialized. 
		}
		catch (...)
		{
			throw Exceptions::OptionExcept("Option::Param() Error: Parameter \"" + key + "\" is invalid.");
		}
	}
	//////////////////////////
	// Mutators:
	//////////////////////////
	void Option::TypeToggle()					/* Alter type (Call/Put). */
	{
		isCall = !isCall;
	}
	void Option::Param(const std::string &key, double val_in) /* Set value of passed parameter. */
	{
		try
		{
			params.at(key) = val_in; // Throws out_of_range exception if key is not initialized. 
		}
		catch (...)
		{
			throw Exceptions::OptionExcept("Option::Param() Error: Parameter \"" + key + "\" is invalid.");
		}
		if (key != "b" && key != "r" && val_in <= 0)
		{
			throw Exceptions::OptionExcept("Option::Param() Error: Parameter \"" + key + "\" must be > 0.");
		}
		
	}
	//////////////////////////
	// Misc. Methods:
	//////////////////////////
	double Option::FiniteDiff(const std::string &key, double paramValue, unsigned Order, double h) /* Approximation for Option Greeks using central finite difference method (up to 2nd order). */
	{ 
		// Handle bad inputs:
		if (h <= 0)
		{
			throw Exceptions::OptionExcept("Option::FiniteDiff() Error: h must be > 0.");
		}
		else if (paramValue <= 0)
		{
			throw Exceptions::OptionExcept("Option::FiniteDiff() Error: Value must be > 0.");
		}
		try // Throw exception if key is not in params map:
		{
			params.at(key);
		}
		catch (...)
		{
			throw Exceptions::OptionExcept("Option::FiniteDiff() Error: Parameter \"" + key + "\" is invalid.");
		}
		// Calculate central finite difference approximation of option "Greeks". 
		// TODO: Generalize for Nth order. 
		double outVal = 0, oldVal;
		if (Order == 0)      // Return Price(). 
		{
			oldVal = params[key];
			params.at(key) = paramValue;
			outVal = Price();
			params.at(key) = oldVal; // Reset target parameter's value to previous value. 
			return outVal;
		}
		else if (Order == 1) // Return approximation of first order Greek. 
		{
			oldVal = params[key];
			params.at(key) = paramValue + h;
			outVal += Price() / (2 * h);
			params.at(key) = paramValue - h;
			outVal -= Price() / (2 * h);
			params.at(key) = oldVal; // Reset target parameter's value to previous value. 
			return outVal;
		}
		else if (Order == 2) // Return approximation of second order Greek. 
		{
			oldVal = params[key];
			params.at(key) = paramValue + h;
			outVal += Price() / (h * h);
			params.at(key) = paramValue;
			outVal -= 2 * Price() / (h * h);
			params.at(key) = paramValue - h;
			outVal += Price() / (h * h);
			params.at(key) = oldVal; // Reset target parameter's value to previous value. 
			return outVal;
		}
		else // If Order > 2 throw exception. 
		{
			throw Exceptions::OptionExcept("Option::FiniteDiff() Error: Max order is 2.");
		}
	}
	std::string Option::Description() const /* Return string detailing option parameters, their values and the option's type. */
	{
		std::strstream ss;
		for (std::map<std::string, double>::const_iterator i = params.begin(); i != params.end(); i++)
		{
			ss << i->first << ": " << i->second << " ";
		}
		ss << "Type: " << ((isCall) ? "Call" : "Put");
		ss << '\0';

		return ss.str();
	}
	//////////////////////////
	// Overloaded Operators:
	//////////////////////////
	Option& Option::operator=(const Option &in)	/* Assignment Operator. */
	{
		if (this != &in)
		{
			params = in.params;
			isCall = in.isCall;
		}
		return *this;
	}
}