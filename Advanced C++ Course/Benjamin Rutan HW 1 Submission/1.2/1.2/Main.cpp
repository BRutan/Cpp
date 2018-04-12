/* MAin.cpp (exercise 1.2):
Description:
	* Solution to problems 1-3.
*/
#include <algorithm>
#include <chrono>
#include <complex>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include "C.hpp"
#include "Functions.hpp"

int main()
{
	/* Problem 1: */
	// Test the C class:
	////// TODO: add class that can use constexpr? (https://www.quantnet.com/threads/constexpr-specifier.24334/ ask for clarification).
	// Notes: 
	// 1. Private and deleted functions cannot be used since inaccessible.
	// 2. constexpr keyword not usable for any function since void was not considered a literal type in C++11, while in C++14 it is. 
	// 3. 
	C test1, test2;
	for (int i = 0; i < 20; i++)
	{
		test1.push_back(i);
		test2.push_back(-i);
	}
	test1.setElement(0, 3.0);
	test1.print();
	std::cout << "test1[0] = " << test1.getElement(0) << std::endl;
	test2.scale(3.0);
	test2.print();

	/* Problem 2: */
	// a) Create two separate strings, move the rvalue output of string + operator into the rValueTest variable:
	std::string test3("abc123"), test4("456");
	std::string&& rValueTest = test3 + test4;
	std::cout << rValueTest << std::endl;
	// b) Test move with vectors, compared speed with copy constructor and assignment operator:
	std::vector<double> vec1, vec2;
	for (unsigned long long i = 0; i < 2000000; i++)
	{
		vec1.push_back(i);
		vec2.push_back(i);
	}
	// Move the vector and calculate time taken:
	std::chrono::duration<double> elapsedTime;
	auto start = std::chrono::system_clock::now();
	std::vector<double>&& moveVec = std::move(vec1);
	auto end = std::chrono::system_clock::now();
	elapsedTime = end - start;
	std::cout << "Move vector time: " << elapsedTime.count() * 1000 << " milliseconds." << std::endl;
	// Get the time taken to copy whole vector:
	start = std::chrono::system_clock::now();
	std::vector<double> vec3(vec1);
	end = std::chrono::system_clock::now();
	elapsedTime = end - start;
	std::cout << "Copy vector time: " << elapsedTime.count() * 1000 << " milliseconds." << std::endl;
	// Get time taken to assign whole vector (note: in this case move takes half the time of assignment and copying): 
	start = std::chrono::system_clock::now();
	vec2 = vec1;
	end = std::chrono::system_clock::now();
	elapsedTime = end - start;
	std::cout << "Assign vector time: " << elapsedTime.count() * 1000 << " milliseconds." << std::endl;
	// c) Test the Swap function and Swap function that uses move semantics: 
	///// TODO: need to answer how many temporary copies are created in the SwapCopyStyle function.
	// https://blog.smartbear.com/c-plus-plus/c11-tutorial-introducing-the-move-constructor-and-the-move-assignment-operator/
	start = std::chrono::system_clock::now();
	SwapCopyStyle(vec1, vec2);
	end = std::chrono::system_clock::now();
	elapsedTime = end - start;
	std::cout << "Time to swap large vectors without move semantics: " << elapsedTime.count() * 1000 << " milliseconds" << std::endl;
	start = std::chrono::system_clock::now();
	SwapCopyStyle_MoveSemantics(std::move(vec1), std::move(vec2));
	end = std::chrono::system_clock::now();
	elapsedTime = end - start;
	std::cout << "Time to swap large vectors with move semantics: " << elapsedTime.count() * 1000 << " milliseconds" << std::endl;
	// Conclusion: move semantic swapping is several orders of magnitude faster than classical assignment and copying.
	
	/* Problem 3: */
	// b) Test move assignment and move copy operators:
	C test6, test7;
	for (unsigned i = 0; i < 20; i++)
	{
		test6.push_back(i);
	}
	//Test move assignment (can ensure is called via using std::move):
	test7 = std::move(test6);
	test7.print();
	// Test move copy constructor (can ensure it is called by using std::move()):
	C test8(std::move(test7));
	test8.print();
	// c) Passing an lvalue into a constructor or assignment operator will call the classical copy constructor or assignment operator, NOT the move copy constructor or move assignment operator.
	
	system("pause");

	return 0;
}