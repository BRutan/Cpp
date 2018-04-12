/* Shape_Classic.hpp (exercise 1.4.4) 
Description:
	* Solution to exercise 1.4.4.
Classes:
	Shape: base class to be derived in Circle class.
	* State Variables:
	- VoidFunctionType pVMFEmulator: stored function that returns nothing, operating on passed double parameter.
	* Member Functions
	//Constructors/Destructor:
	- Shape(const VoidFunctionType&): copy constructor, assigns passed void(double) function to pVMFEmulator.
	-~Shape(): destructor.
	// Misc. Functions:
	void rotate(double): function to be overwritten in derived classes. Passes double param to pVMFEmulator state function variable.
	Circle: derived class that overwrites rotate(double d) function.
	* Member Functions:
	// Constructors/Destructor:
	- Circle(const VoidFunctionType&): assign passed void(double) function to stored pVMFEmulator in base class.
	- ~Circle(): destructor.
	// Misc. Functions:
	void rotate(double): overwrite base rotate function. Prints statement signifying Circle::rotate has been called and passes double param to pVMFEmulator state function variable.

*/

#ifndef SHAPECLASSIC_HPP
#define SHAPECLASSIC_HPP

#include <functional>
#include <iostream>

using VoidFunctionType = std::function<void(double)>;
namespace Classic
{
	// Class hierarchy 
	class Shape
	{
	protected:
		VoidFunctionType pVMFEmulator;
	public:
		Shape(const VoidFunctionType &emulator) : pVMFEmulator(emulator)
		{

		}
		virtual ~Shape() = 0;		  // Using pure virtual destructor to keep Shape base class abstract.	
		virtual	void rotate(double d) // Problem 4: Modify the rotate pvmf in the Shape base class so that it calls f.  
		{
			pVMFEmulator(d);
		}
	};
	Shape::~Shape() // Compulsory to define the pure virtual destructor in the base class to prevent linker issues.
	{

	}

	class Circle : public Shape
	{
	public:
		Circle(const VoidFunctionType &emulator) : Shape(emulator)
		{

		}
		virtual ~Circle()
		{

		}
		void rotate(double d) override
		{
			std::cout << "Circle.rotate(" << d << ") called:";
			Shape::pVMFEmulator(d);
		}
	};
}

#endif
