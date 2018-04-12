/* Main.cpp (exercise 1.6 problems 1-4)
Description:
	* Answer provided questions for section 1.6.
*/

#include <memory>
#include <vector>
#include "ExplicitConstructors.hpp"
#include "Client.hpp"
#include "Sealed.hpp"
#include "TMPClass.hpp"

// Define input function used with TMPClass, multiplies each element by 5: 
double five()
{
	return 5;
}
// Define output function used with TMPClass, displays to stdout:
void output(std::vector<double> data_in)
{
	std::size_t count = 0;
	std::size_t size = data_in.size();
	std::cout << "{ ";
	for (auto &elem : data_in)
	{
		count++;
		(count != size) ? std::cout << elem << ", " : std::cout << elem << " } " << std::endl;
	}
}

int main()
{
	/* 1.6.1 */
	// b) Instantiate Base, Derived and Derived2 objects in additional stack instance to observe constructor and destructor at runtime:
	{
		std::unique_ptr<Base> base(new Base());
		std::unique_ptr<Base> derived(new Derived());
		std::unique_ptr<Base> derived2(new Derived2());
		// Execute each member function of relevant classes:
		base.get()->draw();
		base.get()->print();
		derived.get()->draw();
		derived.get()->print();
		derived2.get()->draw();
		derived2.get()->print();
	}

	/* 1.6.2 */
	// b) Test the TMPClass with the five() and output() functions:
	TMPClass test(10, 4.0, five, output);
	test.Execute();

	/* 1.6.3 */
	// Test the below lines without modifying struct B in ExplicitConstructors.hpp to see which compile and which do not:
	B b1 = 1;	  // a: Will not compile since no assignment operator exists by default to convert from int to B. 
				  // Removing the 'explicit' keyword with the B(int) constructor will allow this line to compile, since the RHS int will be implicitly converted to B, allowing the compiler generated copy assignment operator to be invoked.
	B b2(3);	  // b: Compiles since constructor with int as parameter exists.
	B b3{ 7,3 };  // c: Compiles since constructor with two ints as parameters exists, which apparently is all that is required to allow initializer lists to be used.
	B b4 = (B)42; // d: Compiles since explicit copy constructor with single int as parameter exists. 
	
	/* 1.6.4 */
	// Test the Client class that uses alias templates instead of deprecated typedef. Note that behavior is identical:
	Client_Alias<int> testClient(10, 20);
	testClient.print();

	system("pause");

	return 0;
}