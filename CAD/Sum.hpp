/* Sum.hpp
-Description:
	*Declare and define template Sum functions.
-Function Catalogue:
	*double Sum(const T&): Return sum of passed STL container.
	*double Sum<map<string,double>(const T&):  Return sum of passed map<string,double>.
	*double Sum(T::const_iterator&, T::const_iterator&): Overloaded Sum function, get sum of elements in between two iterators.
	*double Sum<map<string,double>>(T::const_iterator&, T::const_iterator): Overloaded Sum function, get sum of map elements 
	in between two iterators.
*/

#ifndef SUM_HPP
#define SUM_HPP
#include<map>
#include<string>

template<typename T>
double Sum(const T &cont_in)
{
	double total = 0;
	for (typename T::const_iterator iter = cont_in.begin(); iter != cont_in.end(); iter++)
	{
		total += *iter;
	}
	return total;
}

template<>
double Sum<std::map<std::string, double>>(const std::map<std::string, double> &map_in)
{
	double total = 0;
	for (std::map<std::string, double>::const_iterator iter = map_in.begin(); iter != map_in.end(); iter++)
	{
		total += iter->second;
	}
	return total;
}

template<typename T>
double Sum(typename const T::const_iterator &begin_in, typename const T::const_iterator &end_in)
{
	double total = 0;
	for (typename T::const_iterator iter = begin_in; iter != end_in; iter++)
	{
		total += *iter;
	}
	return total;
}

template<>
double Sum<std::map<std::string, double>>(const std::map<std::string, double>::const_iterator &iter1 , const std::map<std::string, double>::const_iterator &iter2)
{
	double total = 0;
	for (std::map<std::string, double>::const_iterator i = iter1; i != iter2; i++)
	{
		total += i->second;
	}
	return total;
}

#endif
