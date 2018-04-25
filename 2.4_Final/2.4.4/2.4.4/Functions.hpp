/* Functions.hpp
Description:
	* 
*/
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <algorithm>
#include <cstdio>
#include <functional>
#include <list>
#include <memory>
#include "Base.hpp"


/* 2.4.4 */
// b) Define factory function to create Derived classes in a shared_ptr list of Base classes:

std::shared_ptr<Base> DerivedFactory()
{
	return std::shared_ptr<Base>(new Derived());
}

/* 2.4.5 */
// b) Create free function and stored lambda function that serve as "deleter" function, in this case
// which ensures file gets closed if exception is thrown.
void FileFinalizer_freeFunc(std::FILE *file_in)
{
	// Close the file:
	(fclose(file_in) != EOF) ? std::cout << "File has been closed." << std::endl : std::cout << "File failed to close." << std::endl;
}
auto FileFinalizer_lambda = [](std::FILE *file)-> void
{ 
	// Close the file:
	(fclose(file) != EOF) ? std::cout << "File has been closed." << std::endl : std::cout << "File failed to close." << std::endl; 
};

struct FileFinalizer_obj
{
public:
	void operator()(std::FILE *file)
	{
		(fclose(file) != EOF) ? std::cout << "File has been closed." << std::endl : std::cout << "File failed to close." << std::endl;
	}
};

#endif
