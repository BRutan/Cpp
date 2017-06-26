/* PDE.h
Description:
	*Header file for PDE class objects. PDE class is 

Class Method Catalogue:

Class Member Variable Catalogue:

*/

#ifndef PDE_HPP
#define PDE_HPP
#include <string>

namespace Symboliq
{
	public class PDE
	{
	private:
		void Convert(const std::string&);
	public:
		PDE(char*);
		PDE(PDE&);


	};
};

#endif