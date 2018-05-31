/* Main.cpp (exercise 3.5.7)
Description:
	* Solutions to problems a-b in exercise 3.5.7.
*/

#include <iostream>
#include <ratio>

int main()
{
	// a) Create number of instances of std::ratio and print them:
	typedef std::ratio<1, 3> oneThird;
	typedef std::ratio<30, 4> thirtyFourths;
	typedef std::ratio<100, 500> oneHundredFiveHundredths;

	std::cout << "One Third: " << oneThird::num << "/" << oneThird::den << std::endl;
	std::cout << "Thirty Fourths: " << thirtyFourths::num << "/" << thirtyFourths::den << std::endl;
	std::cout << "One Hundred Five Hundredths: " << oneHundredFiveHundredths::num << "/" << oneHundredFiveHundredths::den << std::endl;

	// b) Add, subtract, multiply and divide two instances:
	typedef std::ratio_add<oneThird, thirtyFourths> sum;
	typedef std::ratio_subtract<oneThird, thirtyFourths> subtr;
	typedef std::ratio_multiply<oneThird, thirtyFourths> mult;
	typedef std::ratio_divide<oneThird, thirtyFourths> div;

	std::cout << "One Third + Thirty Fourths: " << sum::num << "/" << sum::den << std::endl;
	std::cout << "One Third - Thirty Fourths: " << subtr::num << "/" << subtr::den << std::endl;
	std::cout << "One Third * Thirty Fourths: " << mult::num << "/" << mult::den << std::endl;
	std::cout << "One Third / Thirty Fourths: " << div::num << "/" << div::den << std::endl;

	system("pause");

	return 0;
}