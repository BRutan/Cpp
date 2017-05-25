/* Main.cpp
-Description:
	*Test functionality of EuropeanOption, AmericanPerpetualOption & MeshGenerator classes.
	***Note: Requires Boost library.
*/
#define BOOST_EXCEPTION_DISABLE 
#include<iostream>
#include<iomanip>
#include"AmericanPerpetualOption.hpp"
#include"EuropeanOption.hpp"
#include"MeshGenerator.hpp"
#include"OptionExcept.hpp"

int main()
{
////////////////////////////////////////////////
/* A. */
////////////////////////////////////////////////
	/* a.1): */
	// Create European Options based upon values in Batches in HW file:
	Options::EuropeanOption batch1(.25, 60, 65, .08, .08, .3, true);
	Options::EuropeanOption batch2(1, 100, 100, 0, 0, .2, true);
	Options::EuropeanOption batch3(1, 5, 10, .12, .12, .5, true);
	Options::EuropeanOption batch4(30, 100, 100, .08, .08, .3, true);
	// Print values of each option using member Price() function and Put-Call Parity:
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "A. European Options: " << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Calculate batches 1-4' prices using EuropeanOption::Price(): " << std::endl;
	std::cout << "Batch1 Prices: C: " << batch1.Price(); batch1.TypeToggle();
	std::cout << ", P: " << batch1.Price() << " (Correct : 2.13337, 5.84628)" << std::endl; batch1.TypeToggle();
	std::cout << "Batch2 Prices: C: " << batch2.Price(); batch2.TypeToggle();
	std::cout << ", P: " << batch2.AltPrice() << " (Correct : 7.96557, 7.96557)" << std::endl; batch2.TypeToggle();
	std::cout << "Batch3 Prices: C: " << batch3.Price(); batch3.TypeToggle();
	std::cout << ", P: " << batch3.AltPrice() << " (Correct : .204058, 4.07326)" << std::endl; batch3.TypeToggle();
	std::cout << "Batch4 Prices: C: " << batch4.Price(); batch4.TypeToggle();
	std::cout << ", P: " << batch4.AltPrice() << " (Correct : 92.17570, 1.24750)" << std::endl; batch4.TypeToggle();
	/* b.1) */
	// Use Put-Call Parity (EuropeanOption::AltPrice()) to calculate prices:
	batch2.TypeToggle(); 
	batch4.TypeToggle();
	std::cout << "Calculate batch prices using Put-Call Parity (EuropeanOption::AltPrice()): " << std::endl;
	std::cout << "Batch1 Prices: C: " << batch1.Price() << ", P: " << batch1.AltPrice() << " (Correct : 2.13337, 5.84628)" << std::endl;
	std::cout << "Batch2 Prices: C: " << batch2.Price() << ", P: " << batch2.AltPrice() << " (Correct : 7.96557, 7.96557)" << std::endl; 
	std::cout << "Batch3 Prices: C: " << batch3.Price() << ", P: " << batch3.AltPrice() << " (Correct : .204058, 4.07326)" << std::endl; 
	std::cout << "Batch4 Prices: C: " << batch4.Price() << ", P: " << batch4.AltPrice() << " (Correct : 92.17570, 1.24750)" << std::endl; 
	/* c.1): */
	// Create vector to hold large number of iterates generated using GenerateMesh() and MeshFunctor object:
	std::cout << "Using MeshGenerator class to generate meshes varying one or more parameters: " << std::endl;
	Options::MeshGenerator meshGen;
	meshGen.Load("s", 100, 110, 1); // Load "s" so only stock price is varied.
	batch4.TypeToggle(); // Set batch4 to Call option.
	std::vector<double> varyOne = meshGen.Generate<Options::EuropeanOption>(&batch4, &Options::EuropeanOption::Price); // Pass Price() function to determine change in s given change in price.
	std::cout << "Price given range of parameter 's' (100, 110): "<< std::endl;
	for (unsigned i = 0; i < 4; i++)
	{
		std::cout << std::setprecision(5) << varyOne[i] << ", " << varyOne[i + 3] << ", " << varyOne[i + 6] << std::endl;
	}
	/* d.1): */
	// "Load" all parameters and store impacts to Price() in vector of vectors:
	meshGen.Load("t", 30, 40, 1);
	std::vector<std::vector<double>> varyN = meshGen.GenerateN(&batch4, &Options::EuropeanOption::Price);
	std::cout << "Price given range of parameters 's' (100 to 110) and 't' (30 to 40): " << std::endl;
	std::cout << std::fixed;
	for (unsigned i = 0; i < varyN.size(); i++)
	{
		for (unsigned j = 0; j < varyN[i].size(); j++)
		{
			std::cout << std::setprecision(2) << varyN[i][j];
			(j != varyN[i].size() / 2 - 1) ? std::cout << ", " : std::cout << " ";
		}
		std::cout << std::endl;
	}
/* A Part II: */
	/* a) */
	// Compute Delta for each option type:
	Options::EuropeanOption batch5(.5, 105, 100, 0, .1, .36, true);
	std::cout << "Working with Option 'Greeks': " << std::endl;
	std::cout << std::setprecision(4) << "Batch5 Call Delta: " << batch5.Delta() << ", Gamma: " << batch5.Gamma() << std::endl;
	batch5.TypeToggle();
	std::cout << "Batch5 Put Delta: " << batch5.Delta() << " (Correct: .5946, -.3566) " << std::endl;
	std::cout << "Given parameters: " << batch5.Description() << std::endl;
	/* b) */
	// Compute batch5 Deltas over large range of iterates using MeshGenerator object:
	batch5.TypeToggle();
	meshGen.Clear();
	meshGen.Load("s", 100, 120, 1);
	varyOne = meshGen.Generate<Options::EuropeanOption>(&batch5, &Options::EuropeanOption::Delta);
	std::cout << "Delta given range in parameter 's' (100 to 110): " << std::endl;
	for (unsigned i = 0; i < 3; i++)
	{
		std::cout << std::setprecision(5) << varyOne[i] << ", " << varyOne[i + 3] << ", " << varyOne[i + 6] << ", " << varyOne[i + 9] << std::endl;
	}	
	/* c) */
	meshGen.Load("t", .5, 20, .25);
	varyN = meshGen.GenerateN<Options::EuropeanOption>(&batch5, &Options::EuropeanOption::Delta);
	std::cout << "Delta given range in parameters 's' (100 to 110) and 't' (.1, 1): " << std::endl;
	for (unsigned i = 0; i < varyN.size(); i++)
	{
		for (unsigned j = 0; j < varyN[i].size(); j++)
		{
			std::cout << std::setprecision(2) << varyN[i][j];
			(j != varyN[i].size() - 1) ? std::cout << ", " : std::cout << " ";
		}
		std::cout << std::endl;
	}
	/* d) */
	std::cout << "Greeks using Finite Difference approximation (Option::FiniteDiff): " << std::endl;
	std::cout << "Batch5 Call Delta: " << std::setprecision(5) << batch5.FiniteDiff("s", batch5.Param("s"), 1, .05);
	batch5.TypeToggle();
	std::cout << ", Put Delta: " << batch5.FiniteDiff("s", batch5.Param("s"), 1, .05) << " (Correct: .5946, -.3566) " << std::endl;
	std::cout << "Given parameters: " << batch5.Description() << std::endl;
////////////////////////////////////////////////
/* B. */
////////////////////////////////////////////////
	/* b) */
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "B. American Perpetual Options" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	Options::AmericanPerpetualOption batch6(110, 100, .02, .1, .1, true);
	std::cout << "Batch 6 Call Price: " << batch6.Price() << ", Put Price: "; batch6.TypeToggle();
	std::cout << batch6.Price() << " (Correct : 18.5035, 3.03106)" << std::endl; batch6.TypeToggle();
	std::cout << "Given parameters: " << batch6.Description() << std::endl;
	/* c) */
	meshGen.Clear();
	meshGen.Load("s", 70, 120, 5);
	varyOne = meshGen.Generate<Options::AmericanPerpetualOption>(&batch6, &Options::AmericanPerpetualOption::Price);
	std::cout << "Batch6 Call Price given range of parameter 's' (70 to 120): " << std::endl;
	std::cout << std::setprecision(5) << std::fixed;
	for (unsigned i = 0; i < 3; i++)
	{
		std::cout << varyOne[i] << ", " << varyOne[i + 3] << ", " << varyOne[i + 6] << std::endl;
	}
	/* d) */
	meshGen.Load("k", 70, 120, 10);
	std::cout << "Batch6 Call Price given range of parameter 's' (70 to 120) and 'k' (80 to 120): " << std::endl;
	for (unsigned i = 0; i < varyN.size(); i++)
	{
		for (unsigned j = 0; j < varyN[i].size(); j++)
		{
			std::cout << std::setprecision(2) << varyN[i][j];
			(j != varyN[i].size() - 1) ? std::cout << ", " : std::cout << " ";
		}
		std::cout << std::endl;
	}

////////////////////////////////////////////////
/* Misc. Testing of Remaining Functionality: */
////////////////////////////////////////////////
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << " Testing remaining functionality:		   " << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	// Test EuropeanOption:
	std::cout << "---- EuropeanOption class: ----" << std::endl;
	Options::EuropeanOption Euro1(30, 100, 100, .08, .08, .3, true);
	Options::EuropeanOption Euro2(Euro1);
	Options::EuropeanOption Euro3(.02, .02, .02, .02, .02, .02, false);
	Euro3 = Euro2;
	std::cout << "Euro1 Description (Constructed): " << Euro1.Description() << std::endl;
	std::cout << "Euro2 Description (Euro1 Copy): " << Euro2.Description() << std::endl;
	std::cout << "Euro3 Description (Euro2 Assign): " << Euro3.Description() << std::endl;
	std::cout << "Euro1 D1: " << Euro1.D1() << ", D2: " << Euro1.D2() << std::endl;
	std::cout << "Euro1 Theta: " << Euro1.Theta() << " (Approx " << Euro1.FiniteDiff("t", Euro1.Param("t"), 1, .05) << ") " << std::endl;
	std::cout << "Euro1 Vega: " << Euro1.Vega() << " (Approx " << Euro1.FiniteDiff("sigma", Euro1.Param("sigma"), 1, .05) << ") " << std::endl;
	try
	{
		Options::EuropeanOption testOption3(.5, .5, .5, -1, .3, .4, true); // Throws OptionExcept.
	}
	catch(Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.GetMessage() << std::endl;
	}
	try
	{
		Euro1.Param("s", -1); // Throws OptionExcept.
	}
	catch (Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.GetMessage() << std::endl;
	}
	try
	{
		Euro1.Param("q"); // Throws OptionExcept.
	}
	catch (Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.GetMessage() << std::endl;
	}
	// Test AmericanPerpetualOption:
	std::cout << "---- AmericanPerpetualOption class: ----" << std::endl;
	Options::AmericanPerpetualOption APO1(.1, .1, .1, .1, .3, true);
	Options::AmericanPerpetualOption APO2(APO1);
	Options::AmericanPerpetualOption APO3(.2, .2, .2, .2, .2, false);
	APO3 = APO2;
	std::cout << "APO1 Description (Constructed): " << APO1.Description() << std::endl;
	std::cout << "APO2 Description (APO1 Copy): " << APO2.Description() << std::endl;
	std::cout << "APO3 Description (APO3 Assign): " << APO3.Description() << std::endl;
	std::cout << "APO1 Y1: " << APO1.Y1() << ", Y2: " << APO1.Y2() << std::endl;
	// Test MeshGenerator:
	std::cout << "---- MeshGenerator class: ----" << std::endl;
	Options::MeshGenerator MeshGen1(.2, .5, .3);
	Options::MeshGenerator MeshGen2(MeshGen1);
	Options::MeshGenerator MeshGen3;
	MeshGen3 = MeshGen2;
	std::cout << "MeshGen1 Description (Constructed): " << MeshGen1.Description() << std::endl;
	std::cout << "MeshGen2 Description (MeshGen1 Copy): " << MeshGen2.Description() << std::endl;
	std::cout << "MeshGen3 Description (MeshGen2 Assign): " << MeshGen3.Description() << std::endl;
	MeshGen1.Load("s", .4, .5, .1);
	std::cout << "MeshGen1 \"s\" Min: " << MeshGen1.Min("s") << ", Max: " << MeshGen1.Max("s") << ", " << MeshGen1.Step("s") << std::endl;
	MeshGen1.Unload("s");
	try
	{
		MeshGen1.Max("s"); // Throws GeneratorExcept since key is not loaded.
	}
	catch (Options::Exceptions::GeneratorExcept &except)
	{
		std::cout << except.GetMessage() << std::endl;
	}
	try
	{
		MeshGen1.Load("x", .4, .4, .4); // Throws GeneratorExcept due to invalid key.
	}
	catch (Options::Exceptions::GeneratorExcept &except)
	{
		std::cout << except.GetMessage() << std::endl;
	}
	MeshGen1.Clear();
	std::cout << "MeshGen1 Description (Cleared): " << MeshGen1.Description() << std::endl;



	system("pause");

	return 0;
}