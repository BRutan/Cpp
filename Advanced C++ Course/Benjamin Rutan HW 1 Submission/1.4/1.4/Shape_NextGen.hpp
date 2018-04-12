/* Shapes_NextGen.hpp (exercise 1.4.5): 
Description:
	* Next generation polymorphism through use of templates and stored functions.
State Variables:
	*std::function<RType(const PType&) function: stored function with template return type RType and template parameter type PType.
Member Functions:
	// Constructors/Destructor:
	* Shape(const std::function<RType(const PType&)): overloaded constructor, assigns the member function to passed function object.
	* ~Shape(): destructor.
	// Setters:
	* void SetFunction(const std::Function<RType(const PType&)>): assign stored function to passed function.
	// Misc Functions:
	* RType Execute(const PType&): return the output of the stored function using passed parameter as function's parameter.
*/

#ifndef SHAPENEXTGEN_HPP
#define SHAPENEXTGEN_HPP

#include <functional>

// a) Create single Shape class with embedded command-style function wrapper to emulate polymorphism
namespace NextGen
{
	template<typename RType, typename PType>
	class Shape
	{
	private:
		std::function<RType(const PType&)> function;
	public:
		///////////////////////////////
		// Constructors/Destructor:
		///////////////////////////////
		Shape(const std::function<RType(const PType&)> function_in) noexcept : function(function_in)
		{

		}
		virtual ~Shape() noexcept
		{
			
		}
		///////////////////////////////
		// Setters:
		///////////////////////////////
		void SetFunction(std::function<RType(const PType&)> function_in) noexcept
		{
			function = function_in;
		}
		///////////////////////////////
		// Misc Functions:
		///////////////////////////////
		RType Execute(const PType& val)
		{
			return function(val);
		}
	};
}

#endif
