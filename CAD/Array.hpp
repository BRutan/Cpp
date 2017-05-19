/* Array.hpp
Description:
	*Dynamic array template of objects that are allocated on the heap.
State Variables:
	*static unsigned int defaultSize: default size of Array object.
	*T *m_data: array of objects.
	*unsigned int m_size: the size of the array.
Member Functions:
	// Constructors/Destructor:
	*Array(): Default constructor. Allocates memory for <defaultSize> T objects on heap and initializes to 0 via their default constructors.
	*Array(unsigned int size): Overloaded constructor. Allocates memory for <size> T objects on heap and initializes to 0.
	*Array(const Array<T>&): Copy constructor. Copies state of passed array.
	*virtual ~Array(): Destructor. Deletes every T object in m_data and
	// Accessors:
	*T& GetElement(unsigned int) const: Get object at passed index.
	*unsigned int DefaultSize() const: Get the defaultSize of all Array objects.
	*unsigned int Size() const: Get m_size.
	// Mutators:
	*void SetElement(unsigned int, const T&): Set the object at the passed index to the passed T object.
	*void DefaultSize(unsigned int): Set the defaultSize of all Array objects.
*/

#ifndef ARRAY_HPP
#define ARRAY_HPP

namespace Containers
{
	template<typename T>
	class Array
	{
	private:
		// State Variables:
		static unsigned int defaultSize;			/* Default size of array. */
		T *m_data;									/* Dynamic array of T objects. */
		unsigned int m_size;						/* Size of m_data. */
	public:
		/////////////////////////////
		// Constructors/Destructor:
		/////////////////////////////
		Array();									/* Default Constructor (allocates 10 T objects in m_data). */
		Array(unsigned int);						/* Overloaded Constructor (set size of m_data). */
		Array(const Array<T>&);						/* Copy Constructor. */
		virtual ~Array();							/* Destructor. */
		/////////////////////////////
		// Accessors:
		/////////////////////////////
		unsigned int DefaultSize() const;			/* Return defaultSize. */
		T& GetElement(unsigned int) const;			/* Return element at passed index. */
		unsigned int Size() const;					/* Return size of array. */
		/////////////////////////////
		// Mutators:
		/////////////////////////////
		void DefaultSize(unsigned int);							/* Set the defaultSize. */
		void SetElement(unsigned int, const T&);	/* Set element at passed index to passed T object. */
		/////////////////////////////
		// Overloaded operators:
		/////////////////////////////
		Array<T>& operator=(const Array<T>&);		/* Assignment operator. */
		const T& operator[](unsigned int) const;	/* Return element at passed index (const version). */
		T& operator[](unsigned int);				/* Return element at passed index (non-const version).*/
	};
}

#ifndef ARRAY_CPP
#include"Array.cpp"
#endif				

#endif
