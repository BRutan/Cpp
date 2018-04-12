/* Functions.hpp (exercise 1.3.1)
Description:
	* Define template functions that use variadic template and function parameters.
Functions:
	* void print(const T& arg, const Types&... args): top-level print function that prints all of the varying number of passed parameters.
	* void print(const T& arg): "tail" function of above variadic function, provides a stop when final parameter has been reached.
*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

// a) Create the template variadic parameter function with parameter pack:
template<typename T, typename... Types>
void print(const T& arg, const Types&... args) // Recursively call each argument passed. 
{
	std::cout << arg << ", ";
	print(args...);
}
// b) Create the termination/tail function: 
template<typename T>
void print(const T &arg)
{
	std::cout << arg << std::endl;
}


#endif
