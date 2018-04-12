/* TMPClass.cpp (exercise 1.6.2)
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

#include <algorithm>
#include "TMPClass.hpp"

///////////////////////////
// Constructors/Destructor:
///////////////////////////
TMPClass::TMPClass(std::size_t n, double sValue, InputFunction iFunction_in, OutputFunction oFunction_in) noexcept : iFunction(iFunction_in), oFunction(oFunction_in), data(n)
{
	// Use range-based for loop to set value of each element of the data vector to the starting value (sValue):
	for (auto& elem : data)
	{
		elem = sValue;
	}
}
TMPClass::TMPClass(const TMPClass& in) noexcept : iFunction(in.iFunction), oFunction(in.oFunction), data(in.data)
{

}
TMPClass::TMPClass(TMPClass&& in) noexcept : iFunction(in.iFunction), oFunction(in.oFunction), data(std::move(in.data))
{

}
TMPClass::~TMPClass() noexcept
{

}
///////////////////////////
// Accessors:
///////////////////////////
InputFunction TMPClass::IFunction() const noexcept
{
	return this->iFunction;
}
OutputFunction TMPClass::OFunction() const noexcept
{
	return this->oFunction;
}
std::vector<double> TMPClass::Data() const noexcept
{
	return this->data;
}
///////////////////////////
// Mutators:
///////////////////////////
void TMPClass::IFunction(const InputFunction& iFunction_in) noexcept
{
	iFunction = iFunction_in;
}
void TMPClass::OFunction(const OutputFunction& oFunction_in) noexcept
{
	oFunction = oFunction_in;
}
void TMPClass::Data(const std::vector<double>& data_in) noexcept
{
	data = data_in;
}
///////////////////////////
// Misc. Methods:
///////////////////////////
void TMPClass::Execute() noexcept
{
	// Execute the input function on each element of the vector, then execute the output function:
	auto f = [&](double elem) { return elem * this->iFunction(); };
	std::transform(data.begin(), data.end(), data.begin(), f);
	oFunction(data);
}
///////////////////////////
// Overloaded Operators:
///////////////////////////
TMPClass& TMPClass::operator=(const TMPClass& in) noexcept
{
	if (this != &in)
	{
		this->iFunction = in.iFunction;
		this->oFunction = in.oFunction;
		this->data = in.data;
	}
	return *this;
}
TMPClass& TMPClass::operator=(TMPClass&& in) noexcept
{
	if (this != &in)
	{
		this->iFunction = std::move(in.iFunction);
		this->oFunction = std::move(in.oFunction);
		this->data = std::move(in.data);
	}
	return *this;
}
