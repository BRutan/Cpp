/* Functions.hpp (exercise 3.4.3)
Description:
	* Function to test promise objects in exercise 3.4.3.
*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <future>

void testPromise(std::promise<double> result)
{
	double output = 0;
	for (unsigned i = 0; i < 100; i++)
		output++;
	result.set_value(output);
}


#endif
