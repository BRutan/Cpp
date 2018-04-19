/*



*/

#include <fstream>
#include <boost\system\error_code.hpp>


int main()
{
	/* 2.7.1 */
	std::ifstream fileOut("..\misc.txt", std::ifstream::in);
	if (fileOut.is_open())
	{
		char a = 4;
	}
	system("pause");
	return 0;
}