/* SymLinkedList.hpp (TODO 5.12.2017: Update arithmetic operators to NOT use [] (too slow). Update to correctly handle PolyLinkedList exponents.)
Description:


*/

#ifndef SYMLINKEDLIST_HPP
#define SYMLINKEDLIST_HPP

#include"PolyLinkedList.hpp"
#include"SymNode.hpp"
#include"TypeDefs.hpp"

namespace Symboliq
{
	class SymLinkedList
	{
	private:
		////////////////////////////////
		// State Variables:
		////////////////////////////////
		SymNode *start, *end;									// First and last nodes in the list.
		ULL numSymbols;											// Number of elements in the list. 
		////////////////////////////////
		// Misc. Private Functions:
		////////////////////////////////
		void Quicksort(ULL, ULL);								// Quicksort algorithm.
	public:
		///////////////////////////////
		// Constructors/Destructor:
		///////////////////////////////
		SymLinkedList();										// Default Constructor.
		SymLinkedList(const SymLinkedList&);					// Copy Constructor.
		virtual ~SymLinkedList();								// Destructor. 
		///////////////////////////////
		// Mutators:
		///////////////////////////////
		void Clear();													// Clear all elements of list.
		void Consolidate();												// Combine like terms (ex: x^3x^2 -> x^5).
		void Convert(const std::string&, const CharVector&);			// Convert passed string into a SymLinkedList.
		void Push_Back(SymNode*);
		void Push_Back(const SymNode&);									// Append PolyNode to back of list.
		void Push_Back(const PolyLinkedList& exponent, char symbol);	// Overloaded Push_Back. 
		void Push_Front(const SymNode&);								// Append PolyNode to front of list.
		void Push_Front(const PolyLinkedList& exponent, char symbol);	// Overloaded Push_Front.
		void Swap(ULL, ULL);											// Swap symbols in the SymbolLinkedList.
		///////////////////////////////
		// Accessors:
		///////////////////////////////
		LD Degree() const;												// Return the degree of the linked list (highest exponent).
		std::string ToString() const;									// Output string description of SymLinkedList (ex: "x^3x^2").
		ULL Size() const;												// Get numSymbols in the list.
		///////////////////////////////
		// Misc. Methods:
		///////////////////////////////
		bool Find(char);										// Return true if char is in the SymLinkedList.
		///////////////////////////////
		// Overloaded Operators:
		///////////////////////////////
		SymLinkedList& operator=(const SymLinkedList&);			// Assignment Operator.
		SymLinkedList operator*(const SymLinkedList&);			// Multiply two SymLinkedLists.
		SymLinkedList operator/(const SymLinkedList&);			// Divide two SymLinkedLists.
		SymLinkedList operator+(const SymLinkedList&);			// Add two SymLinkedLists.
		bool operator==(const SymLinkedList&) const;			// Equivalence operator. 
		bool operator!=(const SymLinkedList&) const;			// Inequivalence operator.
		const SymNode& operator[](ULL) const;					// Read-only access.
		SymNode& operator[](ULL);								// Write access.
	};
}
#endif
