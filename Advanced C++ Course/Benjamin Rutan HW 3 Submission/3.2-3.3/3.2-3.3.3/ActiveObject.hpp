/* ActiveObject.hpp (exercise 3.2+3.3.3)
Description:
	* 



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
	ActiveObject() : storedThread(nullptr)
	{

	}
	ActiveObject(std::thread *thread_in) : storedThread(thread_in)
	{

	}
	ActiveObject(const ActiveObject &in) : storedThread(in.storedThread)
	{

	}
	virtual ~ActiveObject()												/* Join thread if is joinable when object goes out of scope. */
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
	bool HasThread()
	{
		return storedThread;
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	ActiveObject& operator=(const ActiveObject &in)
	{
		if (this != &in)
		{
			if (this->storedThread->joinable())
				storedThread->join();
			delete this->storedThread;
			this->storedThread = in.storedThread;
		}
		return *this;
	}
};


#endif
