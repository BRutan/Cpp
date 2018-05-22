/* StopWatch.hpp (exercise 3.5.6)
Description:
	* Class is used to more simply time functions. 
*/

#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <chrono>

class StopWatch
{
private:
	std::chrono::high_resolution_clock::time_point now;
	double time;
	bool started;
	StopWatch(const StopWatch&);
	StopWatch& operator=(const StopWatch&);
public:
	StopWatch() : now(), time(0), started()
	{

	}
	void StartStopWatch()
	{
		now = std::chrono::high_resolution_clock::now();
		started = true;
	}
	void StopStopWatch()
	{
		// If StopWatch has not been started then skip:
		if (started)
		{
			time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - now).count();
		}
	}
	void Reset()
	{
		time = 0;
		started = false;
	}
	double GetTime() const
	{	
		return time;
	}
};




#endif
