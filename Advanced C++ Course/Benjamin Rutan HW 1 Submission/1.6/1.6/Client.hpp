/* Client.hpp (exercise 1.6.4)
Description:
	* Recreate provided C++ 98 typedef using classes using more modern alias template approach.
*/


#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <algorithm>
#include <iostream>
#include <list>

// C++ 98 approach 
// Data storage types 
template <typename T> 
struct Storage
{
	// Possible ADTs and their memory allocators 
	// typedef std::vector<T, CustomAllocator<T>> type; 
	// typedef std::vector<T, std::allocator<T>> type;
	typedef std::list<T, std::allocator<T>> type;
};

template <typename T> 
class Client 
{ 
// An example of Composition 
private: 
	typename Storage<T>::type data; // typename mandatory 
public: 
	Client(int n, const T& val) : data(n, val) 
	{
	
	}
	void print() const
	{
		std::for_each(data.begin(), data.end(), [](const T& n)
		{
			std::cout << n << ",";
		});
		std::cout << '\n';
	}
};


// Recreated versions of above:
template<typename T>
using Data = std::list<T, std::allocator<T>>;

template<typename T>
class Client_Alias
{
private:
	Data<T> data;
public:
	Client_Alias(int n, const T& val) : data(n, val)
	{

	}
	void print() const 
	{ 
		std::for_each(data.begin(), data.end(), [](const T& n) 
		{ 
			std::cout << n << ","; 
		}); 
		std::cout << '\n'; 
	}
};











#endif