/* OptionAndGeneratorExampleUsage.cpp
-Description:
	*Test the EuropeanOption, AmericanPerpetualOption and MeshGenerator classes.
	***Note: Requires Boost library (version used: 1.64.0).
*/

#include<iostream>
#include<iomanip>
#include"Files/AmericanPerpetualOption.hpp"
#include"Files/EuropeanOption.hpp"
#include"Files/MeshGenerator.hpp"
#include"Files/OptionExcept.hpp"

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
	std::cout << "Batch1 Prices: C: " << batch1.Price(); batch1.TypeToggle(); std::cout << ", P: " << batch1.Price() << " (Correct : 2.13337, 5.84628)" << std::endl; batch1.TypeToggle();
	std::cout << "Batch2 Prices: C: " << batch2.Price(); batch2.TypeToggle(); std::cout << ", P: " << batch2.Price() << " (Correct : 7.96557, 7.96557)" << std::endl; batch2.TypeToggle();
	std::cout << "Batch3 Prices: C: " << batch3.Price(); batch3.TypeToggle(); std::cout << ", P: " << batch3.Price() << " (Correct : .204058, 4.07326)" << std::endl; batch3.TypeToggle();
	std::cout << "Batch4 Prices: C: " << batch4.Price(); batch4.TypeToggle(); std::cout << ", P: " << batch4.Price() << " (Correct : 92.17570, 1.24750)" << std::endl; batch4.TypeToggle();
	/* b.1) */
	// Use Put-Call Parity (EuropeanOption::AltPrice()) to calculate prices:
	std::cout << "Calculate batch prices using Put-Call Parity (EuropeanOption::AltPrice()): " << std::endl;
	std::cout << "Batch1 Prices: C: " << batch1.Price() << ", P: " << batch1.AltPrice() << " (Correct : 2.13337, 5.84628)" << std::endl;
	std::cout << "Batch2 Prices: C: " << batch2.Price() << ", P: " << batch2.AltPrice() << " (Correct : 7.96557, 7.96557)" << std::endl; 
	std::cout << "Batch3 Prices: C: " << batch3.Price() << ", P: " << batch3.AltPrice() << " (Correct : .204058, 4.07326)" << std::endl; 
	std::cout << "Batch4 Prices: C: " << batch4.Price() << ", P: " << batch4.AltPrice() << " (Correct : 92.17570, 1.24750)" << std::endl; 
	/* c.1): */
	// Create vector to hold large number of iterates generated using MeshGenerator object and Generate()/GenerateN() methods:
	std::cout << "Using MeshGenerator class to generate meshes varying one or more parameters: " << std::endl;
	Options::MeshGenerator meshGen;
	meshGen.Load("s", 100, 110, 10); // Load "s" so only stock price is varied.
	batch4.TypeToggle(); // Set batch4 to Call option.
	std::vector<double> varyOne = meshGen.Generate<Options::EuropeanOption>(&batch4, &Options::EuropeanOption::Price); // Pass Price() function to determine change in price given change in s.
	std::cout << "Price given range of parameter 's' (100, 110): "<< std::endl;
	std::vector<double>::const_iterator iter = varyOne.begin();
	for (; iter != varyOne.end(); iter++)
	{
		std::cout << std::setprecision(3) << *iter;
		if (iter + 1 != varyOne.end())
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
	/* d.1): */
	// "Load" "t" and store impacts to Price() in vector of vectors:
	meshGen.Load("t", 30, 40, 10);
	std::vector<std::vector<double>> varyN = meshGen.GenerateN(&batch4, &Options::EuropeanOption::Price);
	std::vector<std::vector<double>>::const_iterator nIter;
	std::cout << "Price given range of parameters 's' (100 to 110) and 't' (30 to 40): " << std::endl;
	std::cout << std::fixed;
	for (nIter = varyN.begin(); nIter != varyN.end(); nIter++)
	{
		for (iter = nIter->begin(); iter != nIter->end(); iter++)
		{
			std::cout << std::setprecision(2) << *iter;
			if (iter + 1 != nIter->end())
			{
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
/* A Part II: */
	/* a) */
	// Compute Delta for each option type:
	Options::EuropeanOption batch5Call(.5, 105, 100, 0, .1, .36, true);
	Options::EuropeanOption batch5Put(.5, 105, 100, 0, .1, .36, false);
	std::cout << "Working with Option 'Greeks': " << std::endl;
	std::cout << std::setprecision(4) << "Batch5 Delta: C: " << batch5Call.Delta() << ", P: " << batch5Put.Delta() << " (Correct: .5946, -.3566) " << std::endl;
	std::cout << "Batch5 Gamma: C: " << batch5Call.Gamma() << ", P: " << batch5Put.Gamma() << std::endl;
	/* b) */
	// Compute batch5 Deltas over large range of iterates using MeshGenerator object:
	meshGen.Clear();
	meshGen.Load("s", 100, 120, 10);
	varyOne = meshGen.Generate<Options::EuropeanOption>(&batch5Call, &Options::EuropeanOption::Delta);
	std::cout << "Delta given range in parameter 's' (100 to 110): " << std::endl;
	for (iter = varyOne.begin(); iter != varyOne.end(); iter++)
	{
		std::cout << std::setprecision(3) << *iter;
		if (iter + 1 != varyOne.end())
		{
			std::cout << ", ";
		}
	}	
	/* c) */
	meshGen.Load("t", .5, 20, 10);
	varyN = meshGen.GenerateN<Options::EuropeanOption>(&batch5Call, &Options::EuropeanOption::Delta);
	std::cout << "Delta given range in parameters 's' (100 to 110) and 't' (.1, 1): " << std::endl;
	for (nIter = varyN.begin(); nIter != varyN.end(); nIter++)
	{
		for (iter = nIter->begin(); iter != nIter->end(); iter++)
		{
			std::cout << std::setprecision(2) << *iter;
			if (iter + 1 != nIter->end())
			{
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
	/* d) */
	std::cout << "Greeks using Finite Difference approximation (Option::FiniteDiff): " << std::endl;
	std::cout << "Batch5 Call Delta: " << std::setprecision(5) << batch5Call.FiniteDiff("s", batch5Call.Param("s"), 1, .05);
	std::cout << ", Put Delta: " << batch5Put.FiniteDiff("s", batch5Put.Param("s"), 1, .05) << " (Correct: .5946, -.3566) " << std::endl;
	std::cout << "Given parameters: " << batch5Put.Description() << std::endl;
////////////////////////////////////////////////
/* B. */
////////////////////////////////////////////////
	/* b) */
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "B. American Perpetual Options"			 << std::endl;
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
	for (iter = varyOne.begin(); iter != varyOne.end(); iter++)
	{
		std::cout << std::setprecision(3) << *iter;
		if (iter + 1 != varyOne.end())
		{
			std::cout << ", ";
		}
	}
	/* d) */
	meshGen.Load("k", 70, 120, 10);
	std::cout << "Batch6 Call Price given range of parameter 's' (70 to 120) and 'k' (80 to 120): " << std::endl;
	varyN = meshGen.GenerateN(&batch6, &Options::AmericanPerpetualOption::Price);
	for (nIter = varyN.begin(); nIter != varyN.end(); nIter++)
	{
		for (iter = nIter->begin(); iter != nIter->end(); iter++)
		{
			std::cout << std::setprecision(2) << *iter;
			if (iter + 1 != nIter->end())
			{
				std::cout << ", ";
			}
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
	std::cout << "Euro1 Price: " << Euro1.Price() << std::endl;
	std::cout << "Euro1 D1: " << Euro1.D1() << ", D2: " << Euro1.D2() << std::endl;
	try
	{
		Options::EuropeanOption testOption3(.5, .5, .5, -1, .3, .4, true); // Throws OptionExcept since all parameters must be > 0.
	}
	catch(Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.Message() << std::endl;
	}
	try
	{
		Euro1.Param("s", -1); // Throws OptionExcept since all parameters must be > 0.
	}
	catch (Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.Message() << std::endl;
	}
	try
	{
		Euro1.Param("q"); // Throws OptionExcept since no parameter named "q".
	}
	catch (Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.Message() << std::endl;
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
	Options::MeshGenerator MeshGen1(.2, .5, 5);
	Options::MeshGenerator MeshGen2(MeshGen1);
	Options::MeshGenerator MeshGen3;
	MeshGen3 = MeshGen2;
	std::cout << "MeshGen1 Description (Constructed): " << MeshGen1.Description() << std::endl;
	std::cout << "MeshGen2 Description (MeshGen1 Copy): " << MeshGen2.Description() << std::endl;
	std::cout << "MeshGen3 Description (MeshGen2 Assign): " << MeshGen3.Description() << std::endl;
	MeshGen1.Load("s", .4, .5, 5);
	std::cout << "MeshGen1 \"s\" Min: " << MeshGen1.Min("s") << ", Max: " << MeshGen1.Max("s") << ", " << MeshGen1.Step("s") << std::endl;
	MeshGen1.Unload("s");
	try
	{
		MeshGen1.Max("s"); // Throws GeneratorExcept since key is not loaded.
	}
	catch (Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.Message() << std::endl;
	}
	try
	{
		MeshGen1.Load("x", .4, .4, 5); // Throws GeneratorExcept due to invalid key.
	}
	catch (Options::Exceptions::BaseExcept &except)
	{
		std::cout << except.Message() << std::endl;
	}
	MeshGen1.Clear();
	std::cout << "MeshGen1 Description (Cleared): " << MeshGen1.Description() << std::endl;

	system("pause");

	return 0;
}