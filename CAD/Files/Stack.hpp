/* Stack.hpp
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

#ifndef STACK_HPP
#define STACK_HPP

#include"Array.hpp"

namespace Containers
{
	template<typename T, int size>
	class Stack
	{
	private:
		Array<T> coreArray;			/* Array template to store data. */
		unsigned int m_current;		/* Number of elements on the stack. */
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		Stack();					/* Default constructor. */
		Stack(const Stack<T, size>&);		/* Copy constructor. */
		virtual ~Stack();					/* Destructor. */
		////////////////////////////
		// Mutators:
		////////////////////////////
		T Pop();					/* Pop element off the top of the stack. */
		void Push(const T&);		/* Push new element to top of the stack. */
		////////////////////////////
		// Overloaded Operators:
		////////////////////////////
		Stack<T,size>& operator=(const Stack<T, size>&);	/* Assignment operator. */
	};
}

#ifndef STACK_CPP
#include"Stack.cpp"
#endif

#endif