/* Main.cpp (exercise 2.4.5)
Description:
	* Solutions to exercise 2.4.5.
*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC 
#include <iostream>
#include <list>
#include <memory>
#include "Base.hpp"
#include "Classes.hpp"
#include "Functions.hpp"
#include "Point.hpp"

template<typename T>
using Ptr = std::unique_ptr<T>;

int main()
{
	/* 2.4.5 */
	using SmartFile = std::shared_ptr<std::FILE>;
	// c) Test deleter functions with files:
	SmartFile file1(fopen("test1.txt", "w+"), FileFinalizer_freeFunc);
	SmartFile file2(fopen("test2.txt", "w+"), FileFinalizer_lambda);
	SmartFile file3(fopen("test3.txt", "w+"), FileFinalizer_obj());
	{
		try
		{
			for (std::size_t i = 0; i < 30; i++)
			{
				fputs("abc123\n", &*file1);
				fputs("abc123\n", &*file2);
				fputs("abc123\n", &*file3);
				if (i == 20)
				{
					throw - 1;
				}
			}
		}
		catch (...)
		{
			std::cout << "Exception caught. " << std::endl;
		}
	}
	// Reopen the files:
	file1.reset(fopen("test1.txt", "w+"));
	file2.reset(fopen("test2.txt", "w+"));
	file2.reset(fopen("test3.txt", "w+"));

	system("pause");
	
	
	return 0;
}
