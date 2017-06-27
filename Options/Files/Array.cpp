/* Array.cpp
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

#ifndef ARRAY_CPP
#define ARRAY_CPP

#include"Array.hpp"
#include"ArrayException.hpp"
#include"OutOfBoundsException.hpp"

namespace Containers
{
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	template<typename T>
	unsigned int Array<T>::defaultSize = 10;					/* Default size of an array object. */
	template<typename T>
	Array<T>::Array() : m_size(defaultSize)						/* Default Constructor (allocates 10 T objects in m_data). */
	{
		m_data = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			// Set each element of m_data to the template type's default constructor value:
			m_data[i] = T();
		}
	}
	template<typename T>
	Array<T>::Array(unsigned int size_in) : m_size(size_in)		/* Overloaded Constructor (allocates <size_in> T objects and sets size_in). */
	{
		m_data = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			// Set each element of m_data to the template type's default constructor value:
			m_data[i] = T();
		}
	}
	template<typename T>
	Array<T>::Array(const Array<T>& array_in) : m_size(array_in.m_size)		/* Copy Constructor. */
	{
		// Copy the passed array's m_size and allocate the corresponding number of elements on the heap:
		m_data = new T[m_size];
		// Copy each of the elements in the passed array.
		for (unsigned int i = 0; i < m_size; i++)
		{
			m_data[i] = array_in.m_data[i];
		}
	}
	template<typename T>
	Array<T>::~Array()														/* Destructor. */
	{
		delete[] m_data;
	}
	/////////////////////////////
	// Accessors:
	/////////////////////////////
	template<typename T>
	T& Array<T>::GetElement(unsigned int index) const			/* Return element at passed index. */
	{
		// If passed index is out of bounds, throw OutOfBoundsException object:  
		if (index >= m_size || index < 0)
		{
			throw Containers::OutOfBoundsException(index);
		}
		else
		{
			return m_data[index];
		}
	}
	template<typename T>
	unsigned int Array<T>::DefaultSize() const				/* Return the defaultSize. */
	{
		return defaultSize;
	}
	template<typename T>
	unsigned int Array<T>::Size() const						/* Return size of array. */
	{
		return m_size;
	}
	/////////////////////////////
	// Mutators:
	/////////////////////////////
	template<typename T>
	void Array<T>::DefaultSize(unsigned int dS_in)			/* Set the defaultSize. */
	{
		defaultSize = dS_in;
	}
	template<typename T>
	void Array<T>::SetElement(unsigned int index, const T &p_in) /* Set element at passed index to passed T object. */
	{
		// If passed index is out of bounds, throw OutOfBoundsException object: 
		if (index >= m_size || index < 0)
		{
			throw Containers::OutOfBoundsException(index);
		}
		else
		{
			m_data[index] = p_in;
		}
	}
	/////////////////////////////
	// Overloaded operators:
	/////////////////////////////
	template<typename T>
	Array<T>& Array<T>::operator=(const Array<T> &array_in)					   /* Overloaded assignment operator. */
	{
		// Preclude self-assignment:
		if (this != &array_in)
		{
			// Delete old m_data array:
			delete[] m_data;
			m_size = array_in.m_size;
			// Reallocate memory on the heap for m_data:
			m_data = new T[m_size];
			// Copy T objects in array_in:
			for (unsigned int i = 0; i < m_size; i++)
			{
				m_data[i] = array_in.m_data[i];
			}
		}
		return *this;
	}
	template<typename T>
	const T& Array<T>::operator[](unsigned int index) const		/* Const bracket operator (returns T object at passed index). */
	{
		// If passed index is out of bounds, throw OutOfBoundsException object: 
		if (index >= m_size || index < 0)
		{
			throw Containers::OutOfBoundsException(index);
		}
		else
		{
			return m_data[index];
		}
	}
	template<typename T>
	T& Array<T>::operator[](unsigned int index)					/* Non-const bracket operator (returns T object at passed index and allows mutation).*/
	{
		if (index >= m_size || index < 0)
		{
			throw Containers::OutOfBoundsException(index);
		}
		else
		{
			return m_data[index];
		}
	}
}
#endif