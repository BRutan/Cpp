/* Command.hpp (exercise 3.5.2)
Description:
	* Class used to execute commands in priority queue.
*/

#include <boost/thread/thread.hpp>
#include <functional>
#include <iostream>

using FunctionType = std::function<double(double)>;

class Command
{
private:
	long ID;
	FunctionType algo;
public:
	///////////////////////////
	// Constructors/Destructor:
	///////////////////////////
	Command(const FunctionType &algorithm, long priority) : algo(algorithm), ID(priority)
	{

	}
	Command(const Command &in) : algo(in.algo), ID(in.ID)
	{

	}
	virtual ~Command()
	{

	}
	///////////////////////////
	// Misc Methods:
	///////////////////////////
	void Execute(double x) const
	{
		// Introduce delay to simulate heavy algorithm:
		boost::this_thread::sleep(boost::posix_time::millisec(5000));
		std::cout << algo(x) << std::endl;
	}
	int priority() const
	{
		return ID;
	}
	///////////////////////////
	// Overloaded Operators:
	///////////////////////////
	Command& operator=(const Command &in)
	{
		if (this != &in)
		{
			this->ID = in.ID;
			this->algo = in.algo;
		}
		return *this;
	}
};

// Function for use with Command:
double func1(double input)
{
	return input * 5;
}
double func2(double input)
{
	return input / 5;
}

