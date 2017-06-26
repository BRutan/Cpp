/* MeshGenerator.hpp 
-Description:
	*Generates large number of iterates over range of values given by user via Load(string, double, double). For every parameter the user loads, the
	Generate (for one parameter only) or the GenerateN() (for > 1 parameter) methods will output a mesh of result of passed function given
	changes in parameter over associated min and max using provided step.
-Variable/Object Catalogue:
	*map<string, tuple<double,double,double>> minMaxStep: maps string parameter key to the min (first), max (second) or step (third).
-Member Functions:
	// Constructors/Destructor:
	*MeshGenerator(): Default Constructor. Create empty minMaxStep.
	*MeshGenerator(double, double, unsigned): Overloaded Constructor. "Load" all parameters simultaneously with passed min, max and step.
	*MeshGenerator(const MeshGenerator&): Copy constructor.
	*~MeshGenerator(): Destructor.
	// Accessors:
	*double Min(const string &key) const: Return min of parameter associated with passed key. Throws exception if key not loaded.
	*double Max(const string &key) const: Return max of parameter associated with passed key. Throws exception if key not loaded.
	*unsigned Step(const string &key) const: Return step f parameter associated with  passed key. Throws exception if key not loaded.
	// Mutators:
	*void Clear(): "Unload" all parameters from minMaxStep.
	*void Load(const string &key, double min, double max, unsigned step): "Load" passed parameter, set its min, max and step.
	*void Unload(const string &key): Eliminate passed parameter key from minMaxStep.
	// Misc. Methods:
	*string Description() const: Return string describing loaded parameters and their mins, maxes and steps.
	*vector<double> Generate(OptionType *option_in, double (OptionType::*Func)() const): Return vector of changes in *Func given changes in SINGLE loaded parameter over its respective
	min and max (in minMaxStep) for passed option. (i.e. can pass EuropeanOption::Delta to see changes in Delta given changes in 1 parameter).
	*vector<vector<double>> GenerateN(OptionType *option_in, double (OptionType::*Func)() const): Return vector of changes in *Func given changes > 1 loaded parameters over their respective
	mins and maxes (in minMaxStep) for passed option. (i.e. can pass EuropeanOption::Delta to see changes in Delta given changes in s, t, k, etc).
*/

#ifndef MESHGENERATOR_HPP
#define MESHGENERATOR_HPP

#include<numeric>
#include<vector>
#include"GeneratorExcept.hpp"
#include"Option.hpp"

typedef std::map<std::string, std::tuple<double,double,unsigned>> Map;

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
		MeshGenerator(double min, double max, unsigned step);   /* Overloaded Constructor. "Load" all elements of minMaxStep with passed min, max and step. */
		MeshGenerator(const MeshGenerator &meshGen_in);						   /* Copy Constructor. */
		virtual ~MeshGenerator();											   /* Destructor. */
		/////////////////////////////
		// Accessors:
		/////////////////////////////
		Map MinMaxStep() const;												   /* Return copy of minMaxStep object. */
		double Max(const std::string &key) const;							   /* Return loaded Min of passed parameter. */
		double Min(const std::string &key) const;							   /* Return loaded Max of passed parameter. */
		unsigned Step(const std::string &key) const;						   /* Return loaded Step of passed parameter. */
		/////////////////////////////
		// Mutators:
		/////////////////////////////
		void Clear();														   /* Erase all elements of minMaxStep. */
		void Load(const std::string &key, double min, double max, unsigned step);/* Load passed parameter val OR alter passed parameter's min, max and step. */
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
				throw Exceptions::GeneratorExcept("MeshGenerator::Generate() Error: Not enough loaded parameters for generator.");
			}
			else if (minMaxStep.size() > 1)
			{
				throw Exceptions::GeneratorExcept("MeshGenerator::Generate() Error: Too many loaded parameters for generator.");
			}
			unsigned numSteps = 0;
			std::string key = minMaxStep.begin()->first;
			double stepSize = (std::get<1>(minMaxStep.at(key)) - std::get<0>(minMaxStep.at(key))) / (double) std::get<2>(minMaxStep.at(key));
			double origVal = option_in->Param(key), currVal;
			std::vector<double> container_out;
			option_in->Param(key, std::get<0>(minMaxStep.at(key))); // Set parameter's value in option to the min.
			while (numSteps <= std::get<2>(minMaxStep.at(key)))
			{
				container_out.push_back((option_in->*Func)()); // Run passed member function. 
				currVal = option_in->Param(key);	
				option_in->Param(key, currVal + stepSize); // Step parameter's value by step (third parameter in tuple) and continue. 
				numSteps++;
			}
			option_in->Param(key, origVal); // Reset parameter's value.
			return container_out;
		}
		template<typename OptionType>
		std::vector<std::vector<double>> GenerateN(OptionType *option_in, double (OptionType::*Func)() const)	/* Generate mesh using more than 1 variable and function pointer belonging to derived Option class. */
		{
			if (minMaxStep.size() <= 1)
			{
				throw Exceptions::GeneratorExcept("MeshGenerator::GenerateN() Error: Not enough loaded parameters for generator.");
			}
			unsigned numSteps;
			std::vector<std::vector<double>> containerMain;
			std::vector<double> containerSub;
			std::string key;
			double origVal, currVal, stepSize;
			Map::const_iterator iter = minMaxStep.begin();
			while (iter != minMaxStep.end())
			{
				numSteps = 0;
				key = iter->first;
				containerSub.clear();
				origVal = option_in->Param(key);					  // Get original value of option parameter.
				option_in->Param(key, std::get<0>(minMaxStep.at(key))); // Set current parameter's value in option to the min.
				stepSize = (std::get<1>(minMaxStep.at(key)) - std::get<0>(minMaxStep.at(key))) / (double)std::get<2>(minMaxStep.at(key));
				while (numSteps <= std::get<2>(minMaxStep.at(key)))
				{
					containerSub.push_back((option_in->*Func)());
					currVal = option_in->Param(key);
					option_in->Param(key, currVal + stepSize); // Increment parameter vlaue by step.
					numSteps++;
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