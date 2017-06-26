/* SymNode.hpp							
-Description:
	*Node for SymLinkedList. 
-Variable Catalogue:
	*PolyLinkedList power: 
	
*/


#ifndef SYMNODE_HPP
#define SYMNODE_HPP

#include"PolyNode.hpp"
#include"PolyLinkedList.hpp"
#include"TypeDefs.hpp"

namespace Symboliq
{
	struct SymNode
	{
		PolyLinkedList *power;											// Exponent of current variable.
		char symbol;													// Symbol of current variable.
		SymNode *left, *right;											// Left and right nodes.
		SymNode() : left(NULL), power(NULL), right(NULL), symbol()  	// Default constructor.
		{

		}
		SymNode(const SymNode &in) : power(new PolyLinkedList(*in.power)), symbol(in.symbol), left(NULL), right(NULL) // Copy constructor.
		{

		}
		SymNode& operator=(const SymNode &in)							// Assignment operator.
		{
			if (this != &in)
			{
				if (!power)
				{
					power = new PolyLinkedList(*in.power);
				}
				else
				{
					*power = *in.power;
				}
				symbol = in.symbol;
			}
			return *this;
		}
		virtual ~SymNode()												// Destructor.
		{
			if (power)
			{
				delete power;
			}
		}

	};
}

#endif
