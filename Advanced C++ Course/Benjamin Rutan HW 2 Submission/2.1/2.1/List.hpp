/* List.hpp (exercise 2.1.2)
Description:
	* Example classes to test type traits functionality in Main.cpp.
*/
#ifndef LIST_HPP
#define LIST_HPP

struct Node
{
	int data;
	Node *left, *right;
	Node(int value) : data(value)
	{

	}
};

class List
{
public:
	Node *head;
	List() : head(new Node(3))
	{

	}
	~List()
	{
		delete head;
	}
	void f()
	{

	}
};

#endif
