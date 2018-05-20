/* Functions.hpp (exercise 3.5.3)
Description:
	*


*/


#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <list>
#include <string>

/* 3.5.3 */
// b) Write function to get number of elements in forward_list, since does not have member function:
template<typename T>
std::size_t ListSize(const std::forward_list<T> &list_in)
{
	return std::distance(list_in.begin(), list_in.end());
}

// d) Write functions to erase values after given position, in range of iterators:


template<typename T>
void Erase(std::forward_list<T> &list_in, std::size_t position)
{
	list_in.erase_after(
}

template<typename T>
void Erase(std::forward_list<T>::iterator &start, std::forward_list<T>::iterator &end)
{

}

// Function to easily write contents of forward list to stdout:
template<typename T>
std::ostream& operator<<(std::ostream &s, std::forward_list<T> &list_in)
{
	std::size_t count = 1;
	std::size_t size = ListSize(list_in);
	s << "{ ";
	for (auto &i : list_in)
	{
		s << i << ((count++ != size) ? "," : "}\n");
	}
	return s;
}

#endif