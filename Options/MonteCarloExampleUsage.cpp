/* MonteCarloExampleUsage.cpp
-Description:
	* Test the Monte Carlo class and compare output to exact price given by Black-Scholes-Merton equation.
*/

#include <iostream>
#include "MonteCarlo.hpp"
#include "MonteCarloExcept.hpp"
#include "EuropeanOption.hpp"
#include "Option.hpp"
#include "OptionExcept.hpp"

int main()
{
	// Test MonteCarlo class and compare Price output to exact price given by Black-Scholes equation:
	Options::EuropeanOption euroOpt(3, 30, 40, .03, .03, .3, true);
	Options::MonteCarlo newMC(3, 30, 40, .03, .03, .3, 10000, 1000, true);

	double price = newMC.Price();
	std::cout << euroOpt.Description() << std::endl;
	std::cout << "Monte Carlo Generated Price (using Euler-Maruyama): " << price << std::endl;
	std::cout << "Black-Scholes price: " << euroOpt.Price() << std::endl;

	system("pause");

	return 0;

}