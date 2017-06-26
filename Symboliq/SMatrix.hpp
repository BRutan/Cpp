/* SMatrix.hpp
-Description:
	*
-Member Variable Catalogue:
	
-Method Catalogue:

*/

#ifndef SMATRIX_H
#define SMATRIX_H
#include "TypeDefs.hpp"

namespace Symboliq
{
	class SMatrix
	{
	private:
		ULL numRows, numCols;

		SMatrix *eigenValDecomp();
		void GJElimination();
		void getDimensions();
		void getEigenValues();
		//void scanner(const string&);
	public:
		SMatrix(ULL, ULL);
		SMatrix(SMatrix&);
		~SMatrix();
		void ReDim(ULL, ULL);
		//SMatrix operator'(void);
	};

};

#endif