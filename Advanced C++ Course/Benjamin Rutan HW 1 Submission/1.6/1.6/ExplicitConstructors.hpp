/* ExplicitConstructors.hpp (exercise 1.6.3)
Description:
	* Declare and define Struct B to test impact of omitting and including certain constructors and operators. 
*/

#ifndef EXPLICITCONSTRUCTORS_HPP
#define EXPLICITCONSTRUCTORS_HPP


struct B 
{ 
private:
	long double i;
public:
	B(int)
	{

	}
	/* explicit B(int) 
	{
	
	} */
	explicit B(int, int) 
	{
	
	} 
	explicit operator int() const 
	{ 
		return 0; 
	} 
};





#endif