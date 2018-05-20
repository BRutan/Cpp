/*



*/

#include <forward_list>
#include <iostream>
#include <list>
#include "Functions.hpp"

int main()
{
	// a) Create default list, list with n elements and given value, and list build from an initializer list:
	std::forward_list<double> fList1;
	std::forward_list<double> fList2(50, 3);
	std::forward_list<double> fList3{ 0, 1, 2, 3, 4 };
	
	// b) Test the ListSize() function:
	std::cout << "list3 size: " << ListSize<double>(fList3) << std::endl;

	// c) Test 
	fList3.insert_after(fList3.begin(), 1);
	std::cout << fList3 << std::endl;
	fList3.insert_after(fList3.begin(), 12, 4.0);
	std::cout << fList3 << std::endl;
	fList3.insert_after(fList3.begin(), 
	std::cout << fList3 << std::endl;




	system("pause");

	return 0;
}