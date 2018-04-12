/* Main.cpp (exercise 2.1.1)
Description:
	* Provides solutions to exercise 2.1.1-2.1.4.

*/



#include "Functions.hpp"

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

int main()
{
	/* 2.1.1: */
	// a) Test the Is functions to determine if passed type is a pointer, non-pointer, lvalue reference or rvalue reference.
	std::nullptr_t nullPtr = nullptr;
	int *pointer = new int(4);
	int lvalue = 12;
	IsNullPointer(nullPtr);
	IsPointer(pointer);
	IsLValueReference(&lvalue);
	IsRValueReference(std::move(lvalue));
	// b) Test the IsMemberFunctionPointer and IsNonStaticMemberObject functions:
	List test;
	IsMemberFunctionPointer(&List::f);
	IsNonStaticMemberObject(&List::head);
	/* 2.1.2: */
	// Test the Print() bridger function:
	Print(pointer);
	Print(lvalue);
	/* 2.1.3: */




	system("pause");

	return 0;
}