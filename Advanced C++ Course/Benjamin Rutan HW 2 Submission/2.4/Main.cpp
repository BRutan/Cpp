/* Main.cpp (problem 2.4)

Description:

	*


*/


　

　

#include <iostream>

#include <list>

#include <memory>

#include "Base.hpp"

#include "Classes.hpp"

#include "Point.hpp"


template<typename T>

using Ptr = std::unique_ptr<T>;


int main()

{

	// b) Replace provided code with code that uses smart pointer classes:

	try

	{ // Block with raw pointer lifecycle


		std::unique_ptr<double> d(new double(1.0));

		std::unique_ptr<Point> pt(new Point(1.0, 2.0)); // Two-d Point class

		throw 1;

		// Dereference and call member functions 

		*d = 2.0; (*pt).X(3.0);		// Modify x coordinate 

		(*pt).Y(3.0);				// Modify y coordinate 

		

		// Can use operators for pointer operations 

		pt->X(3.0); // Modify x coordinate 

		pt->Y(3.0); // Modify y coordinate

		// Pointers will now be implicitly deleted once removed from scope.

	}

	catch (...)

	{

		std::cout << "Exception caught." << std::endl;

	}

	// c) Experiment with unique_ptr class:

	double *p = new double(3.0);

	// Ptr<double> up_1(p), up_2(p), up_3;

	// Initializing two different unique_ptrs to same pointer will trigger a breakpoint in code.

	// Assign a unique ptr to another unique ptr:

	// up_3 = up_2;

	// Transfer ownership:

	// up_3 = std::move(up_1);


	/* 2.4.2 */

	// a, b, c) Test the C1 and C2 classes that both use the same shared_ptr as a member:

	Point *test = new Point();

	std::shared_ptr<Point> input(test);

	{

		C1 class1(input);

		C2 class2(input);

		class1.print(); std::cout << std::endl;

		class2.print(); std::cout << std::endl;

		std::cout << "Number of entities using input shared ptr (in scope): " << input.use_count() << std::endl;

	}

	std::cout << "Number of entities using input shared ptr (out of scope): " << input.use_count() << std::endl;


	// d) Test shared ptr:

	double *test2 = new double(5);

	std::shared_ptr<double> sp1(test2), sp2;


	// Transfer ownership:

	sp2 = std::move(sp1);

	std::cout << "Transferred pointer ownership from sp1 to sp2." << std::endl;

	// Determine if shared pointer is only owner:

	std::cout << "sp2 is unique: " << sp2.unique() << std::endl;

	sp2.swap(sp1);

	std::cout << "Swapped pointer from sp2 to sp1." << std::endl;

	std::cout << "sp2 was previous owner: " << sp1.owner_before(sp2) << std::endl;

	// Give up ownership:

	/// TODO:


	/* 2.4.3 */

	// a-b) Implement provided code using unique_ptr<>. Code gave run-time error originally due to

	// a run-time access violation since auto_ptr d has been deleted when ownership is transferred. 

	

	std::unique_ptr<double> d(new double(1.0));


	// Dereference

	*d = 2.0;


	// Change ownership of unique_ptr

	// (after assignment, d is undefined)

	

	std::unique_ptr<double> d2(d.release());

	*d2 = 3.0;

	d.reset();

	std::cout << "Unique values: " << *d.get() << ", " << *d2.get();

	//////////// TODO: read unique ptr slides.


	/* 2.4.4 */

	//a) Create list of smart pointers to Base:

	// Below code fails to compile because list uses single link, thus sharing pointer 

	// ownership which is in violation of unique_ptr's implementation.

	// std::list<std::unique_ptr<Base>> uniquePtrBaseList;

	std::list<std::shared_ptr<Base>> sharedPtrBaseList;


	// b) Implement factory function to create instances of Derived and then add them to list:


　

	system("pause");


	return 0;

}
