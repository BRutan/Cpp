/*


*/

#ifndef FORMATEXCEPT_HPP
#define FORMATEXCEPT_HPP

#include<algorithm>
#include<string>
#include<vector>
#include"SymLLException.hpp"

namespace Symboliq
{
	namespace Exceptions
	{
		class FormatExcept : public SymLLException
		{
		private:
			std::vector<unsigned long long> indices;
			std::string errorString;
		public:
			///////////////////////////////
			// Constructors/Destructor:
			///////////////////////////////
			FormatExcept(std::string errorString_in) : errorString(errorString_in), indices()
			{

			}
			FormatExcept(std::string errorString_in, std::vector<unsigned long long> indices_in) : errorString(errorString_in), 
			indices(indices_in)
			{

			}
			virtual ~FormatExcept()
			{

			}
			///////////////////////////////
			// Mutators:
			///////////////////////////////
			void Append(unsigned long long index_in)	// Append an additional index to the indices list. 
			{
				indices.push_back(index_in);
				std::sort(indices.begin(), indices.end());	// Sort the indices.
			}
			///////////////////////////////
			// Misc. Methods:
			///////////////////////////////
			std::string GetMessage()					// Return detailed message regarding formatting issues of passed string that was intended
			{											// to be converted into a Polynomial object. 

			}
			///////////////////////////////
			// Overloaded Operators:
			///////////////////////////////
			FormatExcept& operator=(const FormatExcept &in)
			{
				if (this != &in)
				{
					errorString = in.errorString;
					indices = in.indices;
				}
				return *this;
			}
			unsigned long long operator[](unsigned long long index) const				   // Read-only access. 
			{
				return indices[index];
			}
			std::vector<unsigned long long>::iterator operator[](unsigned long long index) // Write access.
			{
				return indices.begin() + index;
			}
		};
	}
}

#endif
