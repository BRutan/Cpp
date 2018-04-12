/* Main.cpp (exercise 1.3)
Description:
	* Solutions to problems 1-2.
*/
#include <bitset>
#include <iostream>
#include <list>
#include "Functions.hpp"
#include "Shapes.hpp"

int main()
{
	// c) Test the print variadic parameter function:
	int j = 1; double d = 2.0;
	print(j); print(d); print(j, d); print(d, j);
	std::cout << "3 params: \n";
	print(d, j, std::bitset<8>(233));

	/* Problem 2: */
	// a) Test free rotate function:
	Circle circle; 
	Line line; 
	Valve valve;
	double factor = 2.0;
	rotate(factor, circle); 
	rotate(factor, circle, line); 
	rotate(factor, circle, valve); 
	rotate(factor * 2, circle, valve, line);

	// c) We cannot include valves in the alternative solution since Valves do not inherit the Shape base class.
	// The variadic approach however only requires that the class has a rotate function. 
	
	system("pause");

	return 0;
}