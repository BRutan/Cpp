/* Main.cpp (exercise 3.5.1)
Description:
	* Solutions to problems a-c for exercise 3.5.1.
*/

#include <functional>
#include <iostream>
#include <queue>

int main()
{
	/* 3.5.1 */
	// a) Create priority queue using std::vector and std::less: 
	std::priority_queue<long long> pq1;
	pq1.push(66); pq1.push(22); pq1.push(44);
	std::cout << "Testing priority_queue<long long, std::vector<long long>, std::less<long long>>: " << std::endl;
	std::cout << "Pushed 66, 22, 44. " << std::endl;
	std::cout << "pq1 top element: " << pq1.top() << std::endl;
	pq1.pop(); pq1.push(11); pq1.push(22); pq1.push(33); pq1.pop();
	std::cout << "Pushed 11, 22, 33." << std::endl;
	std::cout << "pq1 : { ";
	while (pq1.empty() == false)
	{
		std::cout << pq1.top() << ((pq1.size() > 1) ? ", " : " }\n");
		pq1.pop();
	}

	// b) Test above code using std::deque and std::greater:
	std::priority_queue<long long, std::deque<long long>, std::greater<long long>> pq2;
	pq2.push(66); pq2.push(22); pq2.push(44); 
	std::cout << "Testing priority_queue<long long, std::deque<long long>, std::greater<long long>>: " << std::endl;
	std::cout << "Pushed 66, 22, 44. " << std::endl;
	std::cout << "pq2 top element: " << pq2.top() << std::endl;
	pq2.pop(); pq2.push(11); pq2.push(22); pq2.push(33); pq2.pop();
	std::cout << "Pushed 11, 22, 33." << std::endl;
	std::cout << "pq2 : { ";
	while (pq2.empty() == false)
	{
		std::cout << pq2.top() << ((pq2.size() > 1) ? ", " : " }\n");
		pq2.pop();
	}

	// c) Use lambda function instead of std::greater<long long>:
	auto comp = [&](long long a, long long b) { return a > b; };
	std::priority_queue<long long, std::deque<long long>, decltype(comp)> pq3(comp);
	pq3.push(66); pq3.push(22); pq3.push(44);
	std::cout << "Testing priority_queue<long long, std::deque<long long>, lambda>: " << std::endl;
	std::cout << "Pushed 66, 22, 44. " << std::endl;
	std::cout << "pq3 top element: " << pq3.top() << std::endl;
	pq3.pop(); pq3.push(11); pq3.push(22); pq3.push(33); pq3.pop();
	std::cout << "Pushed 11, 22, 33." << std::endl;
	std::cout << "pq3 : { ";
	while (pq3.empty() == false)
	{
		std::cout << pq3.top() << ((pq3.size() > 1) ? ", " : " }\n");
		pq3.pop();
	}

	// Note: output is identical using lambda:

	system("pause");

	return 0;
}