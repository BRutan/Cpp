/* Functions.hpp (exercise 3.2+3.3.2)
Description:
	* Function to test race condition with smart pointers.
*/


#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <chrono>
#include <memory>
#include <thread>
#include "X.hpp"

/* 3.2+3.3.2 */
// a) Create modify function to test race condition with shared pointers:
void Modify(PointerType &p, double newVal)
{
	// Wait random amount of time:
	//std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 10));
	p->val = newVal;
	std::cout << p->val << std::endl;
}

#endif