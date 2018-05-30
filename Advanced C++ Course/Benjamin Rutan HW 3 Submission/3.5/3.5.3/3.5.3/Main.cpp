/* Main.cpp (exercise 3.5.3)
Description:
	* Solutions to problems a-e for exercise 3.5.3.
*/

#include <array>
#include <forward_list>
#include <functional>
#include <iostream>
#include <list>
#include "Functions.hpp"

int main()
{
	// a) Create default list, list with n elements and given value, and list build from an initializer list:
	std::forward_list<double> fList1;
	std::forward_list<double> fList2(50, 3);
	std::forward_list<double> fList3{ 0, 1, 2, 3, 4 };
	std::array<double, 2> arr1 = { 1.0, 2.0 };
	// b) Test the ListSize() function:
	std::cout << "list3 size: " << ListSize<double>(fList3) << std::endl;

	// c) Create code to insert values after given position based on value, value and count, two iterators and initialiser list:
	std::forward_list<double>::iterator iter;
	iter = fList3.insert_after(fList3.begin(), 1.0); 
	std::cout << fList3 << std::endl;
	iter = fList3.insert_after(iter, 2, 4.0); 
	std::cout << fList3 << std::endl;
	iter = fList3.insert_after(iter, arr1.begin(), arr1.end()); 	
	std::cout << fList3 << std::endl;
	iter = fList3.insert_after(iter, { 4.0, 5.0 });
	std::cout << fList3 << std::endl;
	// d) Test Erase functions:
	Erase(fList3, 4);
	std::cout << fList3 << std::endl;
	Erase(fList3, fList3.begin(), std::next(fList3.begin(), 2));
	std::cout << fList3 << std::endl;

	// e) Create examples to show how splice and merge functionality work:
	std::forward_list<double> ones(10, 1.0);
	std::forward_list<double> twos(10, 2.0);
	std::forward_list<double> misc(1, 0.0);
	std::forward_list<double>::iterator iter2 = misc.begin();
	for (double i = 0.0; i < 4.0; i++)
	{
		iter2 = misc.insert_after(iter2, i + .5);
	}
	std::cout << ones << std::endl;
	std::cout << twos << std::endl;
	// Merge ones and twos lists without predicate:
	ones.merge(twos);
	std::cout << ones << std::endl;
	// Merge using predicate:
	ones.sort(std::less<double>());
	misc.sort(std::less<double>());
	ones.merge(misc, std::less<double>());
	std::cout << ones << std::endl;
	// Note: twos, misc are empty now.

	// Test splice functionality:
	std::forward_list<double> fives(10, 5.0);
	std::forward_list<double> sixes(10, 6.0);
	std::forward_list<double> sevens(10, 7.0);
	std::cout << fives << std::endl;
	std::cout << sixes << std::endl;
	std::cout << sevens << std::endl;

	fives.splice_after(fives.before_begin(), sixes);
	std::cout << fives << std::endl;
	fives.splice_after(fives.begin(), sevens);
	std::cout << fives << std::endl;
	// Note: sixes, sevens are empty now.

	system("pause");

	return 0;
}