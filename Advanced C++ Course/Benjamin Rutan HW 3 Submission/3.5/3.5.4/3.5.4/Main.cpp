/* Main.cpp (exercise 3.5.4)
Description:
	* Solutions to problems a-d for exercise 3.5.4.
*/

#include <iostream>
#include <string>
#include "SynchronisedQueue.hpp"

int main()
{
	/* 3.5.4 */
	// d) Test the new class:
	SynchronisedQueue<std::string> queue;
	queue.Enqueue("first");
	queue.Enqueue("second");
	queue.Enqueue("third");
	std::size_t size = queue.Size();
	for (std::size_t i = 0; i < size; i++)
	{
		std::cout << queue.Dequeue() << std::endl;
	}

	system("pause");

	return 0;
}