/* Main.cpp (exercise 3.4.1)
Description:
	* Solutions to problems a-e for exercise 3.4.1.
*/

#include <iostream>
#include "Functions.hpp"

int main()
{
	// b) Use std::Async to launch func1 and func2:
	std::async(func1);
	std::future<double> output = std::async(func2, 4.0, 5.0);
	std::cout << "func2(4,5) output with no launch policy: " << output.get() << std::endl;

	// c) Test trying to get std::future more than once:
	// Note: can only get the result of future object once, or else a run-time exception is thrown.
	// output.get();

	// d) Test above code using std::launch::async launch policy:
	std::async(std::launch::async, func1);
	output = std::async(std::launch::async, func2, 4.0, 5.0);

	std::cout << "func2(4,5) output with launch::async policy: " << output.get() << std::endl;
	// Note: no difference between using launch::async and no launch policy.

	// e) Use deferred/lazy launch policy with func, test result:
	output = std::async(std::launch::deferred, func2, 4.0, 5.0);
	std::cout << "func2(4,5) output with launch::deferred policy: " << output.get() << std::endl;

	system("pause");

	return 0;
}