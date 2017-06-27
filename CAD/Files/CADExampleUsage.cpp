/* CADTest.cpp
-Description:
	*Test all functionality of files in the Files folder.
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Array.hpp"
#include "ArrayException.hpp"
#include "Circle.hpp"
#include "LessThan.hpp"
#include "Line.hpp"
#include "NumericArray.hpp"
#include "OutOfBoundsException.hpp"
#include "Point.hpp"
#include "PointArray.hpp"
#include "Shape.hpp"
#include "SizeMismatch.hpp"
#include "Stack.hpp"
#include "StackEmptyexception.hpp"
#include "StackException.hpp"
#include "StackFullException.hpp"
#include "Sum.hpp"

int main()
{
// Test Array - Line classes:
	Containers::Array<double> arr_1(20);
	for (unsigned i = 0; i < arr_1.Size(); i++)
	{
		arr_1.SetElement(i, 3.14);
	}
	std::cout << "arr_1 elements:";
	for (unsigned i = 0; i < arr_1.Size(); i++)
	{
		std::cout << " " << i;
		if (i != arr_1.Size() - 1)
		{
			std::cout << ", ";
		}
	}

	try
	{
		arr_1.SetElement(arr_1.Size() + 1, 2.00);
	}
	catch (Containers::ArrayException &except)
	{
		std::cout << except.GetMessage() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unhandled exception encountered. " << std::endl;
	}
	
	CAD::Circle circ1(20, 20);
	CAD::Circle circ2;
	circ1.Radius(30);
	std::cout << circ1 << std::endl;
	std::cout << "Area: " << circ1.Area() << std::endl;
	std::cout << "Centerpoint: " << circ1.CenterPoint() << std::endl;
	std::cout << "Circumference: " << circ1.Circumference() << std::endl;
	std::cout << "Diameter: " << circ1.Diameter() << std::endl;
	
	circ2 = circ1;
	std::cout << "Circle 2 (assigned): " << circ2 << std::endl;
	// Sum all elements in arr_1 using LessThan predicate functor:
	std::vector<double> vec1;
	for (unsigned i = 0; i < 20; i++)
	{
		vec1.push_back(0.00 + i);
	}
	std::cout << "Testing functors: " << std::endl;
	std::cout << "Count of all elements less than 5: " << std::count_if(vec1.begin(), vec1.end(), LessThan(5)) << std::endl;
	
	CAD::Line line1(CAD::Point(3, 3), CAD::Point(4, 4));
	CAD::Line line2;

	std::cout << line1 << std::endl;
	std::cout << "Length: " << line1.Length() << std::endl;
	std::cout << "Point1: " << line1.P1() << std::endl;
	std::cout << "Point2: " << line1.P2() << std::endl;

	line2 = line1;
	std::cout << "Line 2 (assigned): " << line2 << std::endl;

	// Test NumericArray - SizeMismatch classes:
	Containers::NumericArray<double> numArray1(20);
	Containers::NumericArray<double> numArray2(20);
	Containers::NumericArray<double> numArray3(10);
	for (unsigned i = 0; i < numArray1.Size(); i++)
	{
		numArray1.SetElement(i, 0.0 + i);
	}
	numArray2 = numArray1;
	std::cout << "Testing NumericArray: " << std::endl;
	std::cout << "Dot Product: " << numArray1.DotProduct(numArray2) << std::endl;
	try
	{
		std::cout << numArray1.DotProduct(numArray3) << std::endl;
	}
	catch (Containers::ArrayException &except)
	{
		std::cout << except.GetMessage() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unhandled exception encountered. " << std::endl;
	}

	// Test Stack - Sum classes:
	Containers::Stack<double, 10> stack1;
	for (unsigned i = 0; i < 10; i++)
	{
		stack1.Push(0.0 + i);
	}
	std::cout << "Testing Stack: " << std::endl;
	try
	{
		stack1.Push(10.0);
	}
	catch (Containers::StackException &except)
	{
		std::cout << except.GetMessage() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unhandled exception encountered. " << std::endl;
	}
	std::cout << "Stack contents: " << std::endl;
	for (unsigned i = 0; i < 10; i++)
	{
		std::cout << " " << stack1.Pop();
		if (i != 9)
		{
			std::cout << ", ";
		}
		else
		{
			std::cout << std::endl;
		}
	}
	try
	{
		stack1.Pop();
	}
	catch (Containers::StackException &except)
	{
		except.GetMessage();
	}
	catch (...)
	{
		std::cout << "Unhandled exception encountered. " << std::endl;
	}
	std::vector<double> vec2;
	std::map<std::string, double> map1;
	for (unsigned i = 0; i < 20; i++)
	{
		vec2.push_back(0.0 + i);
		map1.emplace("" + i, 0.0 + i);
	}
	std::cout << "Testing Sum template function: " << std::endl;
	std::cout << Sum<std::vector<double>>(vec2) << std::endl;
	std::cout << Sum<std::map<std::string, double>>(map1) << std::endl;

	system("pause");

	return 0;
}