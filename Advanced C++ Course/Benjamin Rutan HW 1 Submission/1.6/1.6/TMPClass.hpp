/* TMPClass.hpp (exercise 1.6.2)
Description:
	* Create and "seal" (make final so cannot be inherited) TMPClass that uses GOF Template Method pattern to create a polymorphic-type structure enabling transformations on data with specified output.
State Variables/Objects:
	* vector<double> data: contains data to be transformed.
	* InputFunction iFunction: input function that transforms data held in data vector.
	* OutputFunction oFunction: output function that specifies how data should be outputted (for purpose of exercise will be output to stdout).
Member Functions:
	// Constructors/Destructor:
	* TMPClass(std::size_t, double, InputFunction, OutputFunction): Overloaded constructor that sets number of elements in vector, starting value, the inputfunction and outputfunction respectively.
	* TMPClass(const TMPClass&): explicit copy constructor.
	* TMPClass(TMPClass&&): move constructor.
	*~TMPClass(): destructor.
	// Accessors:
	* InputFunction IFunction() const: return the input function associated with the class.
	* OutputFunction OFunction() const: return the output function associated with the class.
	* vector<double> Data() const : return the data stored in the TMPClass instance.
	// Mutators:
	* void IFunction(const InputFunction&): set the input function associated with the class.
	* void OFunction(const OutputFunction&): set the output function associated with the class.
	* void Data(const vector<double>&) : set the data stored in the TMPClass instance.
	// Misc. Methods:
	* void Execute(): execute the InputFunction associated with the class on each unit of data then invoke the OutputFunction.
	// Overloaded Operators:
	* TMPClass& operator=(const TMPClass&): assignment operator.
	* TMPClass& operator=(TMPClass&&): move assignment operator.
*/


#ifndef TMPCLASS_HPP
#define TMPCLASS_HPP

#include <algorithm>
#include <functional>
#include <vector>

using InputFunction = std::function<double()>; 
using OutputFunction = std::function<void(const std::vector<double>&)>;

// Seal the class with 'final' specification to prevent inheritance:
class TMPClass final
{
private:
	///////////////////////////
	// State Variables:
	///////////////////////////
	std::vector<double> data;
	InputFunction iFunction;
	OutputFunction oFunction;
public:
	///////////////////////////
	// Constructors/Destructor:
	///////////////////////////
	TMPClass(std::size_t, double, InputFunction, OutputFunction) noexcept;
	explicit TMPClass(const TMPClass&) noexcept;
	TMPClass(TMPClass&&) noexcept;
	virtual ~TMPClass() noexcept;
	///////////////////////////
	// Accessors:
	///////////////////////////
	InputFunction IFunction() const noexcept;
	OutputFunction OFunction() const noexcept;
	std::vector<double> Data() const noexcept;
	///////////////////////////
	// Mutators:
	///////////////////////////
	void IFunction(const InputFunction&) noexcept;
	void OFunction(const OutputFunction&) noexcept;
	void Data(const std::vector<double>&) noexcept;
	///////////////////////////
	// Misc. Methods:
	///////////////////////////
	void Execute() noexcept;
	///////////////////////////
	// Overloaded Operators:
	///////////////////////////
	TMPClass& operator=(const TMPClass&) noexcept;
	TMPClass& operator=(TMPClass&&) noexcept;
};

#endif
