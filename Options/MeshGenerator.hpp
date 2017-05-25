/* MeshGenerator.hpp 
-Description:
	*Generates large number of iterates over range of values given by user via Load(string, double, double). For every parameter the user loads, the
	Generate (for one parameter only) or the GenerateN() (for > 1 parameter) functions will output a mesh of 
-Variable/Object Catalogue:
	*MinMaxMap minMaxes: maps string parameter key to the min (first) or the max (second).
-Member Functions:
	// Constructors/Destructor:
	*MeshGenerator(double): Overloaded Constructor. Set meshStep only.
	*MeshGenerator(double, double, double): Overloaded Constructor. Set meshStep AND "load" all parameters to passed mins and maxes.
	*MeshGenerator(const MeshGenerator&): Copy constructor.
	*~MeshGenerator(): Destructor.
	// Accessors:
	*double MeshStep() const: Return meshStep.
	// Mutators:
	*void Clear(): "Unload" all parameters from minMaxes.
	*void Load(const string&, double, double): "Load" passed parameter, set its min and max.
	*void MeshStep(double): Alter the meshStep.
	*void Unload(const string&): Eliminate passed parameter key from minMaxes.
	// Misc. Methods:
	*vector<double> Generate(OptionType *option_in, double (OptionType::*Func)() const): Return vector of changes in *Func given changes in SINGLE loaded parameter over its respective
	min and max (in minMaxes) for passed option. (i.e. can pass EuropeanOption::Delta to see changes in Delta given changes in 1 parameter).
	*vector<vector<double>> GenerateN(OptionType *option_in, double (OptionType::*Func)() const): Return vector of changes in *Func given changes > 1 loaded parameters over their respective
	mins and maxes (in minMaxes) for passed option. (i.e. can pass EuropeanOption::Delta to see changes in Delta given changes in s, t, k, etc).
*/

#ifndef MESHGENERATOR_HPP
#define MESHGENERATOR_HPP

#include<numeric>
#include<vector>
#include"GeneratorExcept.hpp"
#include"Option.hpp"

typedef std::map<std::string, std::tuple<double,double,double>> Map;

namespace Options
{
	class MeshGenerator 
	{
	private:
		Map minMaxStep;														   /* Contains Min/Max for t, k, s, r, b, sigma (in order). */
	public:
		/////////////////////////////
		// Constructors/Destructor:
		/////////////////////////////
		MeshGenerator();													   /* Default Constructor. Calls default constructor for minMaxStep*/
		MeshGenerator(double min, double max, double step);   /* Overloaded Constructor. "Load" all elements of minMaxStep with passed min, max and step. */
		MeshGenerator(const MeshGenerator &meshGen_in);						   /* Copy Constructor. */
		virtual ~MeshGenerator();											   /* Destructor. */
		/////////////////////////////
		// Accessors:
		/////////////////////////////
		double Max(const std::string &key) const;							   /* Return loaded Min of passed parameter. */
		double Min(const std::string &key) const;							   /* Return loaded Max of passed parameter. */
		double Step(const std::string &key) const;							   /* Return loaded Step of passed parameter. */
		/////////////////////////////
		// Mutators:
		/////////////////////////////
		void Clear();														   /* Erase all elements of minMaxStep. */
		void Load(const std::string &key, double min, double max, double step);/* Load passed parameter val OR alter passed parameter's min, max and step. */
		void Unload(const std::string &key);								   /* Eliminate passed parameter from minMaxStep (will not be used in Generate/GenerateN). */
		/////////////////////////////
		// Misc. Methods:
		/////////////////////////////
		std::string Description() const;									   /* Return loaded parameters with their mins, maxes and steps. */
		template<typename OptionType>
		std::vector<double> Generate(OptionType *option_in, double (OptionType::*Func)() const) 	   /* Generate mesh using only 1 variable and function pointer belonging to derived Option class. */
		{
			if (minMaxStep.size() < 1)
			{
				throw Exceptions::GeneratorExcept("MeshGenerator::Generate() Error: Not enough loaded parameters for generator.\n");
			}
			else if (minMaxStep.size() > 1)
			{
				throw Exceptions::GeneratorExcept("MeshGenerator::Generate() Error: Too many loaded parameters for generator.\n");
			}
			std::string key = minMaxStep.begin()->first;
			double origVal = option_in->Param(key), currVal;
			std::vector<double> container_out;
			option_in->Param(key, std::get<0>(minMaxStep.at(key))); // Set parameter's value in option to the min.
			while (option_in->Param(key) <= std::get<1>(minMaxStep.at(key)))
			{
				container_out.push_back((option_in->*Func)()); // Run passed member function. 
				currVal = option_in->Param(key);	
				option_in->Param(key, currVal + std::get<2>(minMaxStep.at(key))); // Step parameter's value by step (third parameter in tuple) and continue. 
			}
			option_in->Param(key, origVal); // Reset parameter's value.
			return container_out;
		}
		template<typename OptionType>
		std::vector<std::vector<double>> GenerateN(OptionType *option_in, double (OptionType::*Func)() const)	/* Generate mesh using more than 1 variable and function pointer belonging to derived Option class. */
		{
			if (minMaxStep.size() <= 1)
			{
				throw Exceptions::GeneratorExcept("MeshGenerator::GenerateN() Error: Not enough loaded parameters for generator.\n");
			}
			std::vector<std::vector<double>> containerMain;
			std::vector<double> containerSub;
			std::string key;
			double origVal, currVal;
			Map::const_iterator iter = minMaxStep.begin();
			while (iter != minMaxStep.end())
			{
				key = iter->first;
				containerSub.clear();
				origVal = option_in->Param(key);					  // Get original value of option parameter.
				option_in->Param(key, std::get<0>(minMaxStep.at(key))); // Set current parameter's value in option to the min.
				while (option_in->Param(key) <= std::get<1>(minMaxStep.at(key)))
				{
					containerSub.push_back((option_in->*Func)());
					currVal = option_in->Param(key);
					option_in->Param(key, currVal + std::get<2>(minMaxStep.at(key))); // Increment parameter vlaue by meshStep.
				}
				containerMain.push_back(containerSub);
				option_in->Param(key, origVal);				   // Reset parameter's value. 
				iter++;
			}
			return containerMain;
		}
		/////////////////////////////
		// Overloaded Operators:
		/////////////////////////////
		MeshGenerator& operator=(const MeshGenerator &in);				/* Assignment Operator. */
	};
}

#endif