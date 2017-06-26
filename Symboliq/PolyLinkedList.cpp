/* PolyLinkedList.cpp (TODO 5.12.2017: Define operators, potentially scrap [] overloading (too slow). )
-Description:		  (-Update sorting method to account for PolyLinkedLists as exponents (Idea: Set Degree() for exponents that actually a symbol to ULLMAX, i.e. automatically place at end of list.)
	*				  (-Update where Symbols is held (put into SymLinkedList? or Polynomial?))


*/
#include <locale>
#include "PolyLinkedList.hpp"
#include "TypeDefs.hpp"

namespace Symboliq
{
	///////////////////////////////
	// Misc. Private Functions:
	///////////////////////////////
/**/void PolyLinkedList::Append(const std::string &str_in, const CharVector &symbols_in)
	{
	// Note: Polynomial.Convert() handles the formatting check, thus at this stage we assume the string is correctly formatted. 
		ULL i = 0, tempIndex;
		std::strstream coeff, symbolsAndExponents;
		bool isPositive;
		PolyNode *newNode = new PolyNode;
		std::vector<char> validSymbols;
		validSymbols.push_back('+');
		validSymbols.push_back('-');
		validSymbols.push_back('/');
		validSymbols.push_back('*');
		validSymbols.push_back('^');
		if (str_in[0] == '+' || isdigit(str_in[0]))
		{
			isPositive = true;
		}
		else if (str_in[0] == '-')
		{
			isPositive = false;
		}
		while (i != str_in.size()) // Convert string to PolyNode.
		{
			while (isspace(str_in[i]) && i < str_in.size())
			{
				i++;
			}
			if (std::find(symbols_in.begin(), symbols_in.end(), str_in[i]) != symbols_in.end() || i == str_in.size()) // If character is a Polynomial symbol OR the end has been reached.
			{
				// Get the coefficient.
				tempIndex = i + 1;
				i--;
				if (isspace(str_in[i])) // One space ONLY is allowed between coefficient and symbols portion of polynomial term.
				{
					i--;
				}
				while (isdigit(str_in[i]) || str_in[i] == '.')
				{
					i--;
				}
				while (i < tempIndex)
				{
					coeff << str_in[i];
					i++;
				}
				coeff << '\0';
				i = tempIndex;
				newNode->coeff = std::stoull(coeff.str());
				// Get the list of symbols with respective exponents:
				while ((std::find(symbols_in.begin(), symbols_in.end(), str_in[i]) != symbols_in.end() ||
					std::find(validSymbols.begin(), validSymbols.end(), str_in[i]) != validSymbols.end() ||
					isdigit(str_in[i]) || str_in[i] == '.') && i < str_in.size())
				{
					symbolsAndExponents << str_in[i]; 
					i++;
				}
				symbolsAndExponents << '\0';
				newNode->Symbols->Convert(symbolsAndExponents.str(), symbols_in);
				Push_Back(newNode);
			}
		}
	}
/**/void PolyLinkedList::Consolidate()																// Consolidate the current PLL object (add like terms).
	{
		// Assumes that the 
		// If no terms or only one term, return since nothing to consolidate.
		if (numTerms == 1 || numTerms == 0)
			return;
		PolyNode *temp1, *temp2, *leftNodeHolder, *rightNodeHolder, *deleteNodeHolder;
		bool hasChanged;
		do
		{
			hasChanged = false;
			temp1 = start;
			do
			{
				temp2 = temp1->right;
				do
				{
					// If the SymbolLinkedLists are the same, then combine the two terms. 
					if (temp1->Symbols == temp2->Symbols)
					{
						hasChanged = true;
						temp1->coeff += temp2->coeff;

						deleteNodeHolder = temp2;
						rightNodeHolder = deleteNodeHolder->right;
						leftNodeHolder = deleteNodeHolder->left;
						leftNodeHolder->right = rightNodeHolder;
						rightNodeHolder->left = leftNodeHolder;
						temp2 = rightNodeHolder;
						numTerms--;

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
	///////////////////////////////
	// Constructors/Destructor:
	///////////////////////////////
	PolyLinkedList::PolyLinkedList(const PolyLinkedList &list_in) : numTerms(list_in.numTerms), start(new PolyNode(*list_in.start)),			// Copy Constructor. 
		end(new PolyNode(*list_in.end))
	{

	}
	PolyLinkedList::~PolyLinkedList()										// Destructor.
	{
		for (ULL i = 0; i < numTerms; i++)
		{
			delete &(*this)[i];
		}
	}
	///////////////////////////////
	// Mutators:
	///////////////////////////////
	void PolyLinkedList::Clear()														// Clear all elements from list.
	{
		if (!start)
			return;
		else if (!end)
		{
			delete start;
		}
		PolyNode *temp = end;
		PolyNode *deleteNode;
		while (temp)
		{
			deleteNode = temp;
			temp = temp->left;
			delete deleteNode;
		}
	}
/**/void PolyLinkedList::Insert(const PolyNode &node_in, unsigned long long index)	// TODO: Insert PolyNode at passed index
	{
		if (index >= numTerms)
		{
			return;
		}

		PolyNode *temp;

	}
	void PolyLinkedList::Push_Back(const PolyNode& node_in)				// Append PolyNode to "start".
	{
		PolyNode *newNode = new PolyNode;
		newNode->coeff = node_in.coeff;
		newNode->Symbols = node_in.Symbols;
		numTerms++;
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
/**/void PolyLinkedList::Push_Back(LD coeff_in, const SymLinkedList& list_in)		// Overloaded Push_Back. 
	{
		PolyNode *newNode = new PolyNode;
		newNode->coeff = coeff_in;
		*newNode->Symbols = list_in;
		numTerms++;
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
/**/void PolyLinkedList::Push_Front(const PolyNode& node_in)						// Append PolyNode to "end".
	{
		PolyNode *newNode = new PolyNode;
		newNode->coeff = node_in.coeff;
		*newNode->Symbols = *node_in.Symbols;
		numTerms++;
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
/**/void PolyLinkedList::Push_Front(long double coeff_in, const SymLinkedList& list_in)		// Overloaded Push_Front.
	{
		PolyNode *newNode = new PolyNode;
		newNode->coeff = coeff_in;
		*newNode->Symbols = list_in;
		numTerms++;
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
/**/void PolyLinkedList::Swap(ULL index1, ULL index2)		// Swap two poly nodes. 
	{
		if (index1 >= numTerms || index2 >= numTerms)
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
	ULL PolyLinkedList::Size() const						// Return Size of list. 
	{
		return numTerms;
	}
	/**/std::string PolyLinkedList::ToString() const							// Return string description of PolyLinkedList.
	{
		if (numTerms == 0)
		{
			return "";
		}
		std::strstream ss;
		ULL currPosition = 0;
		PolyNode *tempNode = start;
		while (tempNode)
		{
			if (tempNode->coeff < 0)
			{
				ss << " - " << -tempNode->coeff << tempNode->Symbols->ToString();
			}
			else if (tempNode->coeff == 0)
			{
				tempNode = tempNode->right;
			}
			else
			{
				if (currPosition == 0)
				{
					ss << tempNode->coeff << tempNode->Symbols->ToString();
				}
				else
				{
					ss << " + " << tempNode->coeff << tempNode->Symbols->ToString();
				}
			}
			tempNode = tempNode->right;
			currPosition++;
		}
		return ss.str();
	}
	///////////////////////////////
	// Misc. Methods:
	///////////////////////////////
/**/long double PolyLinkedList::f(const ValueMap &values)
	{

	}
	///////////////////////////////
	// Overloaded Operators:
	///////////////////////////////
/**/PolyLinkedList& PolyLinkedList::operator=(const PolyLinkedList& list_in) // Assignment Operator.
	{
		if (this != &list_in)
		{
			// Delete the old list:
			Clear();
			PolyNode *temp = list_in.start;
			while(temp)
			{
				Push_Front(*temp);
				temp = temp->right;
			}
		}
		return *this;
	}
/**/PolyLinkedList PolyLinkedList::operator+(const PolyLinkedList &poly_in) const		// Add another PolyLinkedList.
	{
		// Concatenate current list's Symbols vector with passed list's Symbols vector.
		CharVector::iterator it;
		// Check for existence of matching PolyNode (has same Symbols SymLinkedList):
		PolyLinkedList tempLL(*this);
		PolyNode *temp1, *temp2;

		temp1 = poly_in.start;
		temp2 = tempLL.start;
		// Perform the addition (requires that Symbols SymLinkedList in each PolyNode be sorted in ASCII order):
		do
		{
			do
			{
				if (temp1->Symbols == temp2->Symbols)
				{
					temp1->coeff += temp2->coeff;
					break;
				}
				temp2 = temp2->right;
			} while (temp2);
			Push_Front(*temp1);
			temp1 = temp1->right;
		} while (temp1);

		return tempLL;
	}
	PolyLinkedList PolyLinkedList::operator+(LD val_in) const					// Add scalar.
	{
		// Requires that each PolyNode's SymLinkedList be sorted (descending order by 'power'). 
		PolyLinkedList tempLL(*this);
		PolyNode *temp1 = tempLL.start;
		ULL i = 0;
		// Find a constant in current list. If no constant exists then insert constant term (has an empty SymLinkedList and a power of 0): 
		do
		{
			if (temp1->Symbols->Degree() == 0)
			{
				temp1->coeff += val_in;
				return tempLL;
			}
			else if (temp1->right->Symbols.Degree < 0) // If hit a term with a negative power, suggests no constant term, thus insert constant term
			{										   // before the negative term.
				PolyNode *newNode = new PolyNode;
				newNode->coeff = val_in;
				Insert(newNode, i);
				return tempLL;
			}
			temp1 = temp1->right;
			i++;
		} while (temp1);
		// Insert new term 
		PolyNode *newNode = new PolyNode;
		newNode->coeff = val_in;
		newNode->left = end;
		end->right = newNode;
		end = newNode;
	}
	PolyLinkedList PolyLinkedList::operator*(const PolyLinkedList &poly_in) const		// Multiply by PolyLinkedList.
	{
		// Concatenate current list's Symbols vector with passed list's Symbols vector.
		if (!start || poly_in.start)
		{
			return *this;
		}

		CharVector::iterator it;
		possSymbols.reserve(possSymbols.size + poly_in.possSymbols.size);
		possSymbols.insert(possSymbols.end(), poly_in.possSymbols.begin(), poly_in.possSymbols.end());

		it = std::unique(possSymbols.begin(), possSymbols.end());
		possSymbols.resize(std::distance(possSymbols.begin(), it));

		PolyLinkedList tempLL;

		PolyNode *left = start, *right = poly_in.start, *placeHolder;
		PolyNode *newOut;

		// Use FOIL method:
		while (left)
		{
			placeHolder = right;
			while (right)
			{
				newOut = new PolyNode;
				newOut->coeff = left->coeff * right->coeff;
				newOut->Symbols = *(left->Symbols) * (*(right->Symbols));	// Call the * operator for SymLinkedList.

				right = right->right;
			}
			left = left->right;
			right = placeHolder->right;
		}
		return tempLL;
	}
	PolyLinkedList PolyLinkedList::operator*(LD val_in) const					// Multiply all terms by scalar.
	{
		// Create list copy:
		PolyLinkedList tempLL(*this);
		if (!val_in) // If val_in is 0, clear copy and return.
		{
			tempLL.Clear();
			return tempLL;
		}
		else if (!tempLL.start)
		{
			return tempLL;
		}
		PolyNode *temp = tempLL.start;
		while (temp)
		{
			temp->coeff *= val_in;
			temp = temp->right;
		}
		return tempLL;
	}
	PolyLinkedList PolyLinkedList::operator-(const PolyLinkedList &poly_in) const		// Add another PolyLinkedList.
	{

	}
	PolyLinkedList PolyLinkedList::operator-(LD val_in) const					// Add scalar.
	{

	}
	PolyLinkedList PolyLinkedList::operator/(const PolyLinkedList &poly_in) const		// Divide by PolyLinkedList.
	{

	}
	PolyLinkedList PolyLinkedList::operator/(LD val_in) const					// Divide by scalar.
	{

	}
	bool PolyLinkedList::operator==(const PolyLinkedList &list_in) const					// Equivalence Operator. 
	{
		// Assumes that left and right operands are consolidated, else will return false even if
		// the two lists are the same following consolidation.

		if (numTerms == 0 || numTerms != list_in.numTerms)
		{
			return false;
		}
		else
		{
			bool hasMatch, *trackedMatches;
			// trackMatches is used to keep track of the terms in list_in that have been matched previously.
			trackedMatches = new bool[numTerms];
			for (ULL i = 0; i < numTerms; i++)
			{
				hasMatch = false;
				// Search the terms in the other list for a match:
				for (ULL j = i + 1; j < numTerms; j++)
				{
					if ((*this)[i].coeff == list_in[i].coeff && (*this)[i].Symbols == list_in[i].Symbols && !trackedMatches[j])
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
	bool PolyLinkedList::operator!=(const PolyLinkedList& list_in) const					// Inequivalence Operator.
	{
		// Assumes that left and right operands are consolidated, else will return false even if
		// the two lists are the same following consolidation.

		if (numTerms == 0 || numTerms != list_in.numTerms)
		{
			return true;
		}
		else
		{
			bool hasMatch, *trackedMatches;
			// trackMatches is used to keep track of the terms in list_in that have been matched previously.
			trackedMatches = new bool[numTerms];
			for (ULL i = 0; i < numTerms; i++)
			{
				hasMatch = false;
				// Search the terms in the other list for a match:
				for (ULL j = i + 1; j < numTerms; j++)
				{
					if ((*this)[i].coeff == list_in[i].coeff && (*this)[i].Symbols == list_in[i].Symbols && !trackedMatches[j])
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
	const PolyNode& PolyLinkedList::operator[](ULL index) const		  // Read-only access.
	{
		if (index > numTerms)
		{
			return;
		}
		else if (index > numTerms / 2)
		{
			PolyNode *tempNode = end;
			for (ULL i = numTerms - 1; i != index; i--)
			{
				tempNode = tempNode->left;
			}
			return *tempNode;
		}
		else
		{
			PolyNode *tempNode = start;
			for (ULL i = 0; i != index; i++)
			{
				tempNode = tempNode->right;
			}
			return *tempNode;
		}
	}
	PolyNode& PolyLinkedList::operator[](ULL index)						// Write access.
	{
		if (index > numTerms)
		{
			return;
		}
		else if (index > numTerms / 2)
		{
			PolyNode *tempNode = end;
			for (ULL i = numTerms - 1; i != index; i--)
			{
				tempNode = tempNode->left;
			}

			return *tempNode;
		}
		else
		{
			PolyNode *tempNode = start;
			for (ULL i = 0; i != index; i++)
			{
				tempNode = tempNode->right;
			}

			return *tempNode;
		}
	};

	
/**/PolyLinkedList PolyLinkedList::operator-(const PolyLinkedList &list_in) const
	{
		if (!list_in.start)
		{
			return *this;
		}
		PolyNode *tempNodeLeft, *tempNodeRight, *rightPH;
		PolyLinkedList temp(*this);
		tempNodeLeft = temp.start;
		tempNodeRight = in.start;
		while(tempNodeRight)
		{
		
		}
		return temp;
	}
	// Reflexive arithmetic:
/**/void PolyLinkedList::operator+=(const PolyLinkedList &list_in)				// Reflexive addition.
	{
		
		if (!list_in.start)
		{
			return;
		}

	}
/**/void PolyLinkedList::operator-=(const PolyLinkedList &list_in)				// Reflexive subtraction.
	{

	}
/**/void PolyLinkedList::operator*=(const PolyLinkedList &list_in)				// Reflexive multiplication.
	{

	}
/**/void PolyLinkedList::operator/=(const PolyLinkedList &list_in)				// Reflexive division.
	{

	}
}
