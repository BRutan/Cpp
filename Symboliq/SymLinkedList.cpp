/* SymLinkedList.cpp (TODO 5.12.2017: Potentially use Consolidate() within operators as opposed to handling search for matching symbols.)



*/


#include"BadSymbolsException.hpp"
#include"FormatExcept.hpp"
#include"SymLinkedList.hpp"
#include"TypeDefs.hpp"

namespace Symboliq
{
	///////////////////////////////
	// Misc. Private Functions:
	///////////////////////////////
/**/void SymLinkedList::Quicksort(ULL left, ULL right)							// Quicksort algorithm.
	{
		ULL i = left, j = right;
		SymNode *pivot = &operator[](left / 2 + right / 2), *temp;
		while (i < j)
		{
			while ((*this)[i].power > pivot->power)
			{
				i++;
			}
			while ((*this)[j].power < pivot->power)
			{
				j--;
			}
			if (i <= j)
			{
				Swap(i, j);
				i++;
				j--;
			}
			if (left < j)
				Quicksort(left, j);
			if (i < right)
				Quicksort(i, right);
		}
	}
	void SymLinkedList::Convert(const std::string &str_in, const CharVector &symbols_in)				// Convert passed string into a SymLinkedList.
	{
		// Notes:
		// Assumes no spaces.
		// Assumed to have proper formatting at this stage.
		SymNode *newNode;
		std::strstream exponent;
		ULL i = 0;
		while (i < str_in.size)
		{
			if (std::find(symbols_in.begin(), symbols_in.end(), str_in[i]) != symbols_in.end())
			{
				exponent = std::strstream();
				newNode = new SymNode;
				newNode->symbol = str_in[i];
				i++;
				if (str_in[i] == '^') // If symbol has an exponent, get and pass to converter.
				{
					i++;
					while ((std::find(symbols_in.begin(), symbols_in.end(), str_in[i]) != symbols_in.end() ||
						isdigit(str_in[i]) || str_in[i] == '.') && i < str_in.size)
					{
						exponent << str_in[i];
						i++;
					}
					exponent << '\0';
					newNode->power->Append(exponent.str(), symbols_in);
					Push_Back(newNode);
				}
			}
		}
		// Sort characters in SymLinkedList based upon ASCII order descending:
		Quicksort(0, numSymbols - 1);
	}
	///////////////////////////////
	// Constructors/Destructor:
	///////////////////////////////
	SymLinkedList::SymLinkedList() : start(NULL), end(NULL), numSymbols(0)				         // Default Constructor.
	{

	}
	SymLinkedList::SymLinkedList(const SymLinkedList& list_in) : start(NULL), end(NULL),  // Copy Constructor.
		numSymbols(list_in.numSymbols)
	{
		for (ULL i = 0; i < numSymbols; i++)
		{
			Push_Front(list_in[i]);
		}
	}
	SymLinkedList::~SymLinkedList()														// Destructor. 
	{
		// Delete all the elements of the SymbolLinkedList object:
		if (numSymbols != 0)
		{
			SymNode *temp1 = start, *temp2;
			while (temp1)
			{
				temp2 = temp1;
				temp1 = temp1->right;
				delete temp2;
			}
		}	
	}
	///////////////////////////////
	// Mutators:
	///////////////////////////////
	void SymLinkedList::Clear()															// Clear all elements from list.
	{
		if (!start)
			return;
		else if (!end)
		{
			delete start;
		}
		SymNode *temp = end;
		SymNode *deleteNode;
		while (temp)
		{
			deleteNode = temp;
			temp = temp->left;
			delete deleteNode;
		}
	}
	void SymLinkedList::Consolidate()														// Combine like variables (ex: x^5x^4 -> x^9).
	{
		// If no terms or only one term, return since nothing to consolidate.
		if (numSymbols == 1 || !numSymbols)
			return;
		SymNode *temp1, *temp2, *leftNodeHolder, *rightNodeHolder, *deleteNodeHolder;
		bool hasChanged;
		do // Stopping condition: when no changes have been made. 
		{
			hasChanged = false;
			temp1 = start;
			do
			{
				temp2 = temp1->right;
				do
				{
					// If the power and symbol are the same, then combine the two SymNodes:
					if (temp1->power == temp2->power && temp1->symbol == temp2->symbol)
					{
						hasChanged = true;
						*temp1->power += *temp2->power;

						deleteNodeHolder = temp2;
						rightNodeHolder = deleteNodeHolder->right;
						leftNodeHolder = deleteNodeHolder->left;
						leftNodeHolder->right = rightNodeHolder;
						rightNodeHolder->left = leftNodeHolder;
						temp2 = rightNodeHolder;
						numSymbols--;

						delete deleteNodeHolder;
					}
					else
					{
						temp2 = temp2->right;
					}
				} while (temp2);
				temp1 = temp1->right;
			} while (temp1);
		} while (hasChanged);
	}
	void SymLinkedList::Push_Back(SymNode *node_in)
	{

	}
	void SymLinkedList::Push_Back(const SymNode& node_in)					// Append PolyNode to back of list.
	{
		SymNode *newNode = new SymNode;
		newNode->symbol = node_in.symbol;
		*newNode->power = *node_in.power;
		numSymbols++;
		if (!end) // If end hasn't been allocated yet:
		{
			end = newNode;
		}
		else if (!start) // start hasn't been allocated yet:
		{
			start = newNode;
			start->right = end;
			end->left = start;
		}
		else // If start AND end have been allocated:
		{
			newNode->right = start;
			start = newNode;
		}
	}
	void SymLinkedList::Push_Back(const PolyLinkedList &exponent, char symbol_in)						// Overloaded Push_Back. 
	{
		SymNode *newNode = new SymNode;
		newNode->symbol = symbol_in;
		*newNode->power = exponent;
		numSymbols++;
		if (!end) // If end hasn't been allocated yet:
		{
			end = newNode;
			end->right = NULL;
		}
		else if (!start) // start hasn't been allocated yet:
		{
			start = newNode;
			start->right = end;
			start->left = NULL;
			end->left = start;
		}
		else // If start AND end have been allocated:
		{
			newNode->right = start;
			newNode->left = NULL;
			start = newNode;
		}
	}
	void Symboliq::SymLinkedList::Push_Front(const SymNode& node_in)				// Append PolyNode to front of list.
	{
		SymNode *newNode = new SymNode;
		newNode->symbol = node_in.symbol;
		newNode->power = node_in.power;
		numSymbols++;
		if (!start) // If end hasn't been allocated yet:
		{
			start = newNode;
		}
		else if (!end) // start hasn't been allocated yet:
		{
			end = newNode;
			end->right = NULL;
			end->left = start;
			start->right = end;
		}
		else // If start AND end have been allocated:
		{
			newNode->left = end;
			newNode->right = NULL;
			end = newNode;
		}
	}
	void SymLinkedList::Push_Front(const PolyLinkedList &exponent, char symbol_in)	// Overloaded Push_Front.
	{
		SymNode *newNode = new SymNode;
		newNode->symbol = symbol_in;
		*newNode->power = exponent;
		numSymbols++;
		if (!start) // If end hasn't been allocated yet:
		{
			start = newNode;
		}
		else if (!end) // start hasn't been allocated yet:
		{
			end = newNode;
			end->right = NULL;
			end->left = start;
			start->right = end;
		}
		else // If start AND end have been allocated:
		{
			newNode->left = end;
			newNode->right = NULL;
			end = newNode;
		}
	}
/**/void SymLinkedList::Swap(ULL index1, ULL index2)		// Swap symbols in the SymbolLinkedList.	
	{
		if (index1 >= numSymbols || index2 >= numSymbols)
		{
			return;
		}
		else
		{


		}
	}
	///////////////////////////////
	// Accessors:
	///////////////////////////////
/**/LD SymLinkedList::Degree() const									// Return degree of the symbols list (greatest exponent, assumes list is sorted).
	{
		if (!start)
		{
			return 0;
		}
		return start->power;
	}
	ULL SymLinkedList::Size() const							// Get numSymbols in the list.
	{
		return numSymbols;
	}
/**/std::string SymLinkedList::ToString() const
	{
		if (numSymbols == 0)
			return "";
		std::strstream ss;
		SymNode *tempNode = start;
		while (tempNode)
		{
			ss << tempNode->symbol << "^" << tempNode->power;
			tempNode = tempNode->right;
		}
		return ss.str();
	}
	///////////////////////////////
	// Misc. Methods:
	///////////////////////////////
	bool SymLinkedList::Find(char char_in)												// Return true if char is in list.
	{
		SymNode *temp = start;
		bool isPresent = false;
		while (temp)
		{
			if (temp->symbol == char_in)
			{
				isPresent = true;
				break;
			}
			temp = temp->right;
		}
		return isPresent;
	}
	///////////////////////////////
	// Overloaded Operators:
	///////////////////////////////
/**/SymLinkedList& Symboliq::SymLinkedList::operator=(const SymLinkedList& list_in)		// Assignment Operator.
	{
		if (this != &list_in)
		{
			// Delete the old list:
			Clear();
			numSymbols = list_in.numSymbols;
			for (ULL i = 0; i < numSymbols; i++)
			{
				Push_Front(list_in[i]);
			}
		}
		return *this;
	}
/**/SymLinkedList SymLinkedList::operator*(const SymLinkedList &list_in)		// Multiply two SymLinkedLists.
	{
		if (list_in.numSymbols == 0)
		{
			return SymLinkedList();
		}
		SymLinkedList tempLL(*this);
		SymNode *temp;
		for (ULL i = 0; i < list_in.Size(); i++)
		{
			tempLL.Push_Back(list_in[i]);
		}
		// Consolidate, sort in descending order then return:
		tempLL.Consolidate();
		tempLL.Quicksort(0, tempLL.Size() - 1);

		return tempLL;
	}
/**/SymLinkedList SymLinkedList::operator/(const SymLinkedList &list_in)	// Divide two SymLinkedLists.
	{
		SymLinkedList tempLL(*this);
		for (ULL i = 0; i < list_in.Size(); i++)
		{
			tempLL.Push_Back(-list_in[i].power, list_in[i].symbol);
		}
		// Consolidate, sort in descending order then return:
		tempLL.Consolidate();
		tempLL.Quicksort(0, tempLL.Size() - 1);

		return tempLL;
	}
/**/bool SymLinkedList::operator==(const SymLinkedList &list_in) const			// Boolean equivalence operator.
	{
		// Assumes that left and right operands are consolidated, else will return false even if
		// the two lists are the same following consolidation.

		if (numSymbols == 0 || numSymbols != list_in.numSymbols)
		{
			return false;
		}
		else
		{
			bool hasMatch, *trackedMatches;
			// trackMatches is used to keep track of the terms in list_in that have been matched previously.
			trackedMatches = new bool[numSymbols];
			for (ULL i = 0; i < numSymbols; i++)
			{
				hasMatch = false;
				// Search the terms in the other list for a match:
				for (ULL j = i + 1; j < numSymbols; j++)
				{
					if ((*this)[i].symbol == list_in[i].symbol && (*this)[i].power == list_in[i].power && !trackedMatches[j])
					{
						trackedMatches[j] = true;
						hasMatch = true;
					}
				}
				// If no matching term, return false:
				if (!hasMatch)
				{
					return false;
				}
			}
			// If get through all of the loop iterations, return true:
			return true;
		}
	}
	bool SymLinkedList::operator!=(const SymLinkedList& list_in) const							// Boolean Inequivalence operator.
	{
		// Assumes that left and right operands are consolidated, else will return false even if
		// the two lists are the same following consolidation.

		if (numSymbols == 0 || numSymbols != list_in.numSymbols)
		{
			return true;
		}
		else
		{
			bool hasMatch, *trackedMatches;
			// trackMatches is used to keep track of the terms in list_in that have been matched previously.
			trackedMatches = new bool[numSymbols];
			for (ULL i = 0; i < numSymbols; i++)
			{
				hasMatch = false;
				// Search the terms in the other list for a match:
				for (ULL j = i + 1; j < numSymbols; j++)
				{
					if ((*this)[i].symbol == list_in[i].symbol && (*this)[i].power == list_in[i].power && !trackedMatches[j])
					{
						hasMatch = true;
						trackedMatches[j] = true;
					}
				}
				// If no matching term, return true:
				if (!hasMatch)
				{
					delete trackedMatches;
					return true;
				}
			}
			delete trackedMatches;
			return false;
		}
	}
	const SymNode& SymLinkedList::operator[](ULL index) const	// Read-only access.
	{
		if (index > numSymbols)
		{
			return;
		}
		else if (index > numSymbols / 2)
		{
			SymNode *tempNode = end;
			for (ULL i = numSymbols - 1; i != index; i--)
			{
				tempNode = tempNode->left;
			}
			return *tempNode;
		}
		else
		{
			SymNode *tempNode = start;
			for (ULL i = 0; i != index; i++)
			{
				tempNode = tempNode->right;
			}
			return *tempNode;
		}
	}
	SymNode& SymLinkedList::operator[](ULL index)				// Write access.
	{
		if (index > numSymbols)
		{
			return;
		}
		else if (index > numSymbols / 2)
		{
			SymNode *tempNode = end;
			for (ULL i = numSymbols - 1; i != index; i--)
			{
				tempNode = tempNode->left;
			}
			return *tempNode;
		}
		else
		{
			SymNode *tempNode = start;
			for (ULL i = 0; i != index; i++)
			{
				tempNode = tempNode->right;
			}

			return *tempNode;
		}
	}
}