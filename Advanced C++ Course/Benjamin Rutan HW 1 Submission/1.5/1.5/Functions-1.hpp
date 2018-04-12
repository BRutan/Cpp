/* Functions-1.hpp (exercise 1.5.1)
Description:
	* Define functions used in Problem 5 Exercise 1.
Functions:
	*void printPerson(const Person &person_in): print the elements of the "Person" tuple { Name, Address, DateOfBirth }.
	*void SortPersons<unsigned propertyIndex>(vector<Person> &persons_in, bool descending): sort the passed Person vector based upon some property (0 : Name, 1 : Address, 2 : DateOfBirth), in descending order if possible 
*/


#ifndef FUNCTIONS1_HPP
#define FUNCTIONS1_HPP
#ifndef _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
	#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#endif

#include <boost\date_time.hpp>
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "Exception.hpp"
#include "OutOfBounds.hpp"

/* 1.5.1 */
// a) 
using Person = std::tuple <std::string, std::string, boost::gregorian::date>;
// b) Create function to print elements of Person
void printPerson(const Person &person_in) noexcept
{
	std::cout << "{ ";
	std::cout << "Name: " << std::get<0>(person_in);
	std::cout << ", Address: " << std::get<1>(person_in);
	std::cout << ", Date of Birth: " << std::get<2>(person_in);
	std::cout << " } " << std::endl;
}

// Problem 1: d) Create a function to sort the elements of a list of Persons, depending upon specified characteristic (name, address or date of birth):
template<unsigned propertyIndex>
void SortPersons(std::vector<Person> &persons_in, bool descending)
{
	if (propertyIndex > Person::_Mysize)
	{
		throw Exceptions::OutOfBounds("SortPersons() Error: Out of bounds.");
	}
	bool changed = true;
	unsigned size = persons_in.size();
	Person copy;
	// Sort the Person vector using bubblesort algorithm:
	while (changed)
	{
		changed = false;
		for (unsigned i = 0; i < size; i++)
		{
			for (unsigned j = 0; j < size - i - 1; j++)
			{
				// Get the current element:
				auto first = std::get<propertyIndex>(persons_in[j]);
				auto second = std::get<propertyIndex>(persons_in[j + 1]);
				// Swap the elements if out of order (depending upon ordering preference):
				if (descending && first < second)
				{
					changed = true;
					copy = std::move(persons_in.at(j));
					persons_in.at(j) = std::move(persons_in.at(j + 1));
					persons_in.at(j + 1) = copy;
				}
				else if (!descending && first > second)
				{
					changed = true;
					copy = std::move(persons_in.at(j));
					persons_in.at(j) = std::move(persons_in.at(j + 1));
					persons_in.at(j + 1) = copy;
				}
			}
		}
	}
}

#endif
