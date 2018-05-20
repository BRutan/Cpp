/* Main.cpp (exercise 3.5.2)
Description:
	* Solutions to problems a-d for exercise 3.5.2.
*/

#include <iostream>
#include <queue>
#include <vector>
#include "Command.hpp"

int main()
{
	// a) Create comparator for Command to compare two of its instances:
	auto CommandComparison = [](const Command &i, const Command &j) { return i.priority() > j.priority(); };

	// b) Create several instances of command:
	Command c1(func1, 1);
	Command c2(func2, 2);
	std::cout << "c1 is of higher priority than c2: " << CommandComparison(c2, c1) << std::endl;
	// c) Create priority queue of commands and insert c1, c2:
	std::priority_queue<Command, std::vector<Command>, decltype(CommandComparison)> commandPQ(CommandComparison);
	commandPQ.push(c1);
	commandPQ.push(c2);
	// d) Execute each command in priority queue until empty:
	while (!commandPQ.empty())
	{
		(commandPQ.top()).Execute(10);
		commandPQ.pop();
	}

	// We see that c1 is successfully executed before c2.

	system("pause");


	return 0;
}