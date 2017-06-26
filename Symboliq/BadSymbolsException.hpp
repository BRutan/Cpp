/* BadSymbolsException.hpp
Description:
	*Derived class on SymLLException base class. Returns message detailing bad symbols passed ... 
State Variables/Objects:


*/

#ifndef BADSYMBOLSEXCEPTION_HPP
#define BADSYMBOLSEXCEPTION_HPP

#include<algorithm>
#include<iterator>
#include<string>
#include<strstream>
#include<vector>

namespace Symboliq
{
	namespace Exceptions
	{
		class BadSymbolsException : public SymLLException
		{
		private:
			std::vector<unsigned long long> indices;
			std::string errorString;
		public:
			///////////////////////////////
			// Constructors/Destructor:
			///////////////////////////////
			BadSymbolsException(const std::string &in, std::vector<unsigned long long> &indices_in) :			 // Overloaded Constructor.
			indices(indices_in), errorString(in)
			{
				
			}
			BadSymbolsException(const BadSymbolsException &in) : indices(in.indices), errorString(in.errorString) // Copy Constructor.
			{

			}
			virtual ~BadSymbolsException()																 // Destructor.
			{

			}
			///////////////////////////////
			// Accessors:
			///////////////////////////////
			std::vector<unsigned long long> Indices() const												 // Return vector of indices. 
			{
				return indices;
			}
			unsigned long long Size() const																 // Return size of index vector.
			{
				return indices.size;
			}
			///////////////////////////////
			// Misc. Methods:
			///////////////////////////////
			std::string GetMessage() const																 // Return detailed message of errors.
			{ 
				// Ensure indices only has unique values:
				std::vector<unsigned long long>::iterator it = std::unique(indices.begin(), indices.end());   
				indices.resize(std::distance(myvector.begin(), it)); 
				std::sort(indices.begin(), indices.end());
				// Create the error message:
				std::strstream ssTop, ssBot;
				std::vector<unsigned long long> temp;
				// TODO 5.4.2017: accommodate putting '^' under indices that are within 2 units from each other via using temp vector:
				for (std::vector<unsigned long long>::const_iterator i = indices.begin();
					i != indices.end(); i++)
				{
					if (*i == 0)
					{
						ssTop << errorString[*i] << errorString[*i + 1] << errorString[*i + 2] << "...";
						ssBot << '^' << "   ";
					}
					else if (*i == 1)
					{
						ssTop << errorString[*i - 1] << errorString[*i] << errorString[*i + 1] << "...";
						ssBot << " ^ ...";
					}
					else
					{
						for (unsigned long long j = *i - 2; j < *i + 2; j++)
						{
							ssTop << errorString[j];
						}
						for (unsigned long long j = *i - 2; j < *i + 2; j++)
						{
							if (j != *i)
							{
								ssBot << ' ';
							}
							else
							{
								ssBot << '^';
							}
						}
						ssTop << "...";
						ssBot << "...";
					}
				}
				// TODO : Fix***********
				return ssTop.str() + '\n' + ssBot.str();
			}
			///////////////////////////////
			// Overloaded Operators:
			///////////////////////////////
			BadSymbolsException& operator=(const BadSymbolsException &in)	// Assignment operator.
			{
				if (this != &in)
				{
					errorString = in.errorString;
					indices = in.indices;
				}
				return *this;
			}
			unsigned long long operator[](unsigned long long index)	const	// Read only access.
			{
				return indices[index];
			}
			std::vector<unsigned long long>::iterator& operator[](unsigned long long index)			// Write access.
			{
				return indices.begin() + index;
			}
		};
	}
}

#endif
