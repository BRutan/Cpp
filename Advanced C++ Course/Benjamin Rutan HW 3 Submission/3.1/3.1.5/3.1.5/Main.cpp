/* Main.cpp (exercise 3.1.5)
Description:
	* Solutions to exercise 3.1.5.
*/

#include <atomic>
#include <iostream>

int main()
{
	// a) Create atomic objects:
	std::atomic<long long> llAtomic;
	std::atomic<bool> boolAtomic;
	std::atomic<int> intAtomic;

	// b) Determine which atomic types are lock-free:
	std::cout << "atomic<long long> is lock free: " << llAtomic.is_lock_free() << std::endl;
	std::cout << "atomic<bool> is lock free: " << boolAtomic.is_lock_free() << std::endl;
	std::cout << "atomic<int> is lock free: " << intAtomic.is_lock_free() << std::endl;

	// c) Atomically replace value of one atomic object by another atomic object:
	std::atomic<long long> llAtomic2(320);
	llAtomic.store(400);
	std::cout << "value1: " << llAtomic2.load() << ", value2: " << llAtomic.load() << std::endl;
	llAtomic2.exchange(llAtomic);
	std::cout << "After exchange(): value1: " << llAtomic2.load() << ", value2: " << llAtomic.load() << std::endl;

	// d) Atomically load an atomic object and return current value:
	std::atomic<long long> llAtomic3 = std::atomic_load(&llAtomic2);
	std::cout << "atomic_load(value1): " << llAtomic3.load() << std::endl;

	system("pause");

	return 0;
}