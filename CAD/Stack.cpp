/* Stack.cpp
Description:
	*Array<T> template class that has delegated functionality to Stack data structure (FIFO, elements removed and allocated to "top"-most index).
State Objects/Variables:
	*Array<T> coreArray: Array object template for holding Stack elements.
	*unsigned int m_current: Index of final element of Stack.
Class Methods:
	// Constructors/Destructor:
	*Stack(): Default constructor.
	*Stack(unsigned int): Overloaded constructor. Set coreArray's size.
	*Stack(const Stack<T>&): Copy constructor.
	*~Stack(): Destructor.
	// Mutators:
	*T Pop(): Pop the top element of the stack.
	*void Push(const T&): Push new element to top of the stack.
*/

#ifndef STACK_CPP
#define STACK_CPP

#include"Array.hpp"
#include"Stack.hpp"
#include"StackException.hpp"
#include"StackEmptyException.hpp"
#include"StackFullException.hpp"
#include"OutOfBoundsException.hpp"

namespace Containers
{
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	template<typename T, int size>
	Stack<T, size>::Stack() : coreArray(size)									/* Default constructor. */
	{

	}
	template<typename T, int size>
	Stack<T, size>::Stack(const Stack<T,size>& stack_in) : coreArray(stack_in.coreArray), m_current(stack_in.m_current)	/* Copy constructor. */
	{

	}
	template<typename T, int size>
	Stack<T, size>::~Stack()					/* Destructor. */
	{

	}
	////////////////////////////
	// Mutators:
	////////////////////////////
	template<typename T, int size>
	T Stack<T, size>::Pop()					/* Pop element off the top of the stack. */
	{
		try
		{
			return coreArray[--m_current];
		}
		catch(ArrayException &except_in)
		{
			m_current++;
			throw StackEmptyException();
		}
	}
	template<typename T, int size>
	void Stack<T, size>::Push(const T& elem_in)		/* Push new element to top of the stack. */
	{
		try
		{
			coreArray[m_current] = elem_in;
			m_current++;
		}
		catch (ArrayException &except_in)
		{
			throw StackFullException();
		}
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	template<typename T, int size>
	Stack<T, size>& Stack<T,size>::operator=(const Stack<T,size>& stack_in)	/* Assignment operator. */
	{
		if (this != &stack_in)
		{
			coreArray = stack_in.coreArray;
			m_current = stack_in.m_current;
		}
		return *this;
	}
}

#endif