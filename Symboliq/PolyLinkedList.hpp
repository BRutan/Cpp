/* PolyLinkedList.hpp 
-Description:
	*




*/


#ifndef POLYLINKEDLIST_HPP
#define POLYLINKEDLIST_HPP

#include"PolyNode.hpp"
#include"SymLinkedList.hpp"
#include"TypeDefs.hpp"

namespace Symboliq
{
	class PolyLinkedList
	{
	private:
		////////////////////////////////	
		// State Variables:
		////////////////////////////////
		PolyNode *start, *end;									// First and last nodes.
		void Consolidate();										// Combine like terms (ex: 4x^5x^2 + 3x^5x^2 = 7x^5x^2).
		ULL numTerms;											// Number of terms in the LinkedList.
	public:
		///////////////////////////////
		// Constructors/Destructor:
		///////////////////////////////
		PolyLinkedList();										// Default constructor. Make empty linked list.
		PolyLinkedList(const PolyLinkedList&);					// Copy constructor.
		virtual ~PolyLinkedList();								// Destructor.
		///////////////////////////////
		// Mutators:
		///////////////////////////////
		void Append(const std::string&, const CharVector&);		// Convert passed string into a polynomial using passed Symbols list.
		void Clear();											// Clear all elements of list.
		void Insert(const PolyNode&, ULL index);				// Insert PolyNode at passed index.		
		void Push_Back(const PolyNode&);						// Append PolyNode to back of list.
		void Push_Back(PolyNode*);								// Append PolyNode pointer to back of list.
		void Push_Back(LD, const SymLinkedList&);				// Overloaded Push_Back. 
		void Push_Front(PolyNode*);						// Append PolyNode to front of list.
		void Push_Front(LD, const SymLinkedList&);				// Overloaded Push_Front.
		void Swap(ULL, ULL);									// Swap two poly nodes. Args: node1, node2.
		///////////////////////////////
		// Accessors:
		///////////////////////////////
		ULL Size() const;										// Return Size of list. 
		std::string ToString() const;							// Return string description of PolyLinkedList(ex: "8z^5x^4 + 10y^3").
		///////////////////////////////
		// Misc. Methods:
		///////////////////////////////
		LD f(const ValueMap&);			// Return element of codomain mapped to passed vector. 
		///////////////////////////////
		// Overloaded Operators:
		///////////////////////////////
		PolyLinkedList& operator=(const PolyLinkedList&);				// Assignment Operator.
		// Arithmetic:
		PolyLinkedList operator+(const PolyLinkedList&) const;			// Add another PolyLinkedList.
		PolyLinkedList operator+(LD) const;								// Add scalar.
		PolyLinkedList operator*(const PolyLinkedList&) const;			// Multiply by PolyLinkedList.
		PolyLinkedList operator*(LD) const;								// Multiply by scalar.
		PolyLinkedList operator-(const PolyLinkedList&) const;			// Subtract another PolyLinkedList.
		PolyLinkedList operator-(LD) const;								// Subtract scalar.
		PolyLinkedList operator/(const PolyLinkedList&) const;			// Divide by PolyLinkedList.
		PolyLinkedList operator/(LD) const;								// Divide by scalar.
		// Reflexive Arithmetic:
		void operator+=(const PolyLinkedList&);							// Reflexive addition.
		void operator-=(const PolyLinkedList&);							// Reflexive subtraction.
		void operator*=(const PolyLinkedList&);							// Reflexive multiplication.
		void operator/=(const PolyLinkedList&);							// Reflexive division.
		// Boolean compare:
		bool operator==(const PolyLinkedList&) const;					// Equivalence Operator. 
		bool operator!=(const PolyLinkedList&) const;					// Inequivalence Operator. 
		// Accessing via bracket operator:
		const PolyNode& operator[](ULL) const;			// Read-only access.
		PolyNode& operator[](ULL);						// Write access.
		// Global non-member friend operators:
		friend PolyLinkedList operator-(PolyLinkedList in)			// Negation operator.
		{
			if (!in.start)
			{
				return PolyLinkedList();
			}
			PolyNode *tempNode = in.start;

			while (tempNode)
			{
				tempNode->coeff *= -1;
				tempNode = tempNode->right;
			}
			return in;
		}
	};
}
#endif