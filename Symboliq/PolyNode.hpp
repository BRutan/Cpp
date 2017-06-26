/* PolyNode.hpp											TODO: Perhaps use private/public schema, create accessors/mutators?
Description:
	*Doubly-linked node for PolyLinkedList.
State Variables:
	*long double coeff: Coefficient in the current Polynomial term.
	*SymbolList Symbols: 
Method Catalogue:
	*
*/

#ifndef POLYNODE_HPP
#define POLYNODE_HPP

#include"SymLinkedList.hpp"

namespace Symboliq
{
	struct PolyNode
	{
		long double coeff;												// Coefficient in the current Polynomial term.
		SymLinkedList *Symbols;											// List of symbols in current Polynomial term.
		PolyNode *left, *right;											// Left and right linked PolyNodes.
		PolyNode(): coeff(0), Symbols(NULL), left(NULL), right(NULL)	// Default Constructor.
		{
			
		}
		PolyNode(const PolyNode &in): coeff(in.coeff), left(NULL), right(NULL), Symbols(new SymLinkedList(*in.Symbols)) 	// Copy Constructor.
		{
			
		}
		virtual ~PolyNode()											// Destructor.
		{
			if (Symbols)
			{
				delete Symbols;
			}
		}
		PolyNode& operator=(const PolyNode &in)						// Assignment Operator.
		{
			if (this != &in)
			{
				coeff = in.coeff;
				if (!Symbols && in.Symbols) // If this->Symbols has NOT been allocated but in.Symbols HAS been allocated.
				{
					Symbols = new SymLinkedList(*in.Symbols);
				}
				else if (in.Symbols)
				{
					*Symbols = *in.Symbols;
				}
				else
				{
					Symbols = NULL;
				}
			}
			return *this;
		}
	};
}
#endif

