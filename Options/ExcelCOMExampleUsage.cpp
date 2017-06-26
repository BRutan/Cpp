/* ExcelCOMExampleUsage.cpp
-Description:
	*Use MeshGenerator or EuropeanOption object to generate mesh varying all possible parameters then
	output results to Excel using ConvertMeshToExcel global function.
-Variable Catalogue:
	*EuropeanOption option: European option object to generate prices.
	*MeshGenerator meshGen: MeshGenerator object to create mesh.
***Note: COM libraries randomly throw runtime exception.
*/

#include <iostream>
#include <strstream>
#include <string>
#include <vector>
#include "Files/ConvertMeshToExcel.hpp"
#include "Files/EuropeanOption.hpp"
#include "Files/BaseExcept.hpp"
#include "Files/MeshGenerator.hpp"

int main()
{
	// Instantiate EuropeanOption (batch 4 data) and MeshGenerator objects:
	Options::EuropeanOption option(.25, 60, 65, .08, .08, .3, true);
	Options::MeshGenerator meshGen;
	// Load all parameters:
	meshGen.Load("s", 40, 70, 20);
	meshGen.Load("k", 40, 70, 20);
	meshGen.Load("t", .05, .35, 20);
	meshGen.Load("r", .05, .35, 20);
	meshGen.Load("sigma", .20, .50, 20);
	// Generate mesh using loaded parameters:
	std::vector<std::vector<double>> mesh = meshGen.GenerateN(&option, &Options::EuropeanOption::Price);
	// Output contents of mesh to Excel:
	try
	{
		Options::ConvertMeshToExcel(mesh, meshGen, "Output", "Price");
	}
	catch (Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.Message() << std::endl;
	} 
	// Test ConvertMeshToExcel() exceptions:
	meshGen.Load("s", 50, 150, 30); 
	meshGen.Load("k", 50, 150, 3); 
	meshGen.Load("t", 10, 50, 20);
	meshGen.Load("r", .02, .42, 3);
	meshGen.Load("sigma", .10, .50, 5);
	mesh = meshGen.GenerateN(&option, &Options::EuropeanOption::Price);	
	try
	{
		Options::ConvertMeshToExcel(mesh, meshGen, "Output", "Price"); // Throw exception since columns are not uniform for each row.
	}
	catch (Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.Message() << std::endl;
	}
	std::vector<std::vector<double>> meshEmpty;
	try
	{
		Options::ConvertMeshToExcel(meshEmpty, meshGen, "Output", "Price"); // Throws exception since mesh is empty.
	}
	catch (Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.Message() << std::endl;
	}
	meshGen.Clear();
	try
	{
		Options::ConvertMeshToExcel(meshEmpty, meshGen, "Output", "Price"); // Throws exception since no parameters loaded.	
	}
	catch (Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.Message() << std::endl;
	}
	meshGen.Load("t", 100, 200, 30);
	try
	{
		Options::ConvertMeshToExcel(meshEmpty, meshGen, "Output", "Price"); // Throws exception since only one parameter loaded.	
	}
	catch (Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.Message() << std::endl;
	}

	system("pause");

	return 0;
} 