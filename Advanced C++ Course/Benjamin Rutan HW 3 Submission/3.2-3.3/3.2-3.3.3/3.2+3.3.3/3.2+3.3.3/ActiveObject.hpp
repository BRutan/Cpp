/* ActiveObject.hpp (exercise 3.2+3.3.3)
Description:
	* Stores threads allocated on heap, ensures joined when thread goes out of scope.
Class Members:
	*thread *storedThread: pointer to thread allocated on heap.
Class Methods:
	// Constructors/Destructor:
	*ActiveObject(): assigns nullptr to stored thread.
	*ActiveObject(thread *thread_in): assign thread allocated on heap (but not an existing pointer) to stored thread.
	*ActiveObject(const ActiveObject&): deleted copy constructor.
	*~ActiveObject(): joins the thread if it is finished.
	// Misc. Functions:
	bool HasThread(): returns true if non-nullptr thread is assigned.
	// Overloaded Operators:
	ActiveObject& operator=(const ActiveObject&): deleted assignment operator.
*/

#ifndef ACTIVEOBJECT_HPP
#define ACTIVEOBJECT_HPP

#include <memory>
#include <thread>

class ActiveObject
{
private:
	std::thread *storedThread;
public:
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	ActiveObject() : storedThread(nullptr)								/* Default constructor. Construct a thread pointing to n*/
	{

	}
	ActiveObject(std::thread *thread_in) : storedThread(thread_in)		/* Overloaded constructor. Assign thread allocated on heap to ActiveObject. */
	{

	}
	ActiveObject(const ActiveObject &in) = delete;						/* Deleted copy constructor. */
	virtual ~ActiveObject()												/* Join thread if is joinable when object goes out of scope, then free allocated memory on heap. */
	{
		if (storedThread->joinable())
		{
			storedThread->join();
		}
		// Free resources:
		delete storedThread;
	}
	////////////////////////////
	// Misc. Methods:
	////////////////////////////
	bool HasThread()													/* Return true if object is storing pointer to active thread. */
	{
		return storedThread != 0;
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	ActiveObject& operator=(const ActiveObject &in) = delete;			/* Deleting assignment operator to enforce 1-1 relationship. */
};


#endif
