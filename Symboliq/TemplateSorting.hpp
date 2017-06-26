/*




*/

#ifndef TEMPLATESORTING_HPP
#define TEMPLATESORTING_HPP

#include"PolyLinkedList.hpp"
#include"SymLinkedList.hpp"

namespace Symboliq
{
	namespace HelperFuncs
	{
		template<typename T>
		void QuickSort(T Array, unsigned long long low, unsigned long long high)
		{
			unsigned long long int mid = low / 2 + high / 2;
		}
		template<>
		void QuickSort<Symboliq::PolyLinkedList>(Symboliq::PolyLinkedList List, unsigned long long low, unsigned long long high)
		{
			unsigned long long int mid = low / 2 + high / 2;
			if (low < high)
			{

				QuickSort(List, low, mid);
				QuickSort(List, mid + 1, high);
			}
		}
	}
}

#endif
