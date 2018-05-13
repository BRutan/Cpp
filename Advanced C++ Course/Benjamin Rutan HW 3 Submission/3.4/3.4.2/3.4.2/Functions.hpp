/* Functions.hpp (exercise 3.4.2)
Description:
	* Functions to test std::shared_future<double>.
*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

// Define infinite loop function to test with shared_future<>::wait_for():
double infFunc()					
{
	while (true)
	{

	}
	return 0.0;
}

double func1(double a, double b)
{
	return a * b;
}



#endif
