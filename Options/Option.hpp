/* Option.hpp
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
	*double AltPrice() const: Return price of alternate form of option using Put-Call Parity (holds for all options).
	*long double FiniteDiffApprox(string, double, unsigned, double): Calculate Nth order approximation (n <= 66) for option Greek.
	*virtual double Price() const: PVMF, make Option an abstract base class.
	*string Parameters() const: Return string detail of parameters and their values.
*/

#ifndef OPTION_HPP
#define OPTION_HPP

#include<map>
#include<string>

typedef std::map<std::string, double> ParamMap;

namespace Options
{
	class Option
	{
	private:
		ParamMap params;							/* Maps s, k, t, r, b, sigma to their values. */
		bool isCall;								/* 0 -> Put, 1 -> Call. */
	public:
		Option(double t, double s, double k, double b, double r, double sigma, bool isCall);	/* Overloaded Constructor. Set all parameters. */
		Option(const Option&);						/* Copy Constructor. */
		virtual ~Option();							/* Destructor. */
		//////////////////////////
		// Accessors:
		//////////////////////////
		bool Type() const;							/* Return type (Call/Put). */
		double Param(const std::string &key) const;	/* Return value of passed parameter. */
		//////////////////////////
		// Mutators:
		//////////////////////////
		void TypeToggle();							/* Alter type (Call/Put). */
		void Param(const std::string &key, double); /* Alter value of passed parameter. */
		//////////////////////////
		// Misc. Methods:
		double FiniteDiff(const std::string &key, double value, unsigned Order, double h); /* Approximation for Option Greeks using finite difference method. */
		virtual double Price() const = 0;			/* PVMF: make Option the base class. */
		std::string Description() const;			/* Return string detailing option parameters, their values and the option's type. */
		//////////////////////////
		// Overloaded Operators:
		//////////////////////////
		Option &operator=(const Option&);			/* Assignment Operator. */
	};
}

#endif
