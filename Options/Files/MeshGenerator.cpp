/* MeshGenerator.cpp
-Description:
	*Generates large number of iterates over range of values given by user via Load(string, double, double). For every parameter the user loads, the
	Generate (for one parameter only) or the GenerateN() (for > 1 parameter) methods will output a mesh of result of passed function given
	changes in parameter over associated min and max using provided step.
-Variable/Object Catalogue:
	*map<string, tuple<double,double,double>> minMaxStep: maps string parameter key to the min (first), max (second) or step (third).
-Member Functions:
	// Constructors/Destructor:
	*MeshGenerator(): Default Constructor. Create empty minMaxStep.
	*MeshGenerator(double, double, unsigned): Overloaded Constructor. "Load" all parameters simultaneously with passed min, max and steps.
	*MeshGenerator(const MeshGenerator&): Copy constructor.
	*~MeshGenerator(): Destructor.
	// Accessors:
	*double Min(const string &key) const: Return min of parameter associated with passed key. Throws exception if key not loaded.
	*double Max(const string &key) const: Return max of parameter associated with passed key. Throws exception if key not loaded.
	*unsigned Step(const string &key) const: Return steps of parameter associated with passed key. Throws exception if key not loaded.
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

#include <strstream>
#include"MeshGenerator.hpp"

namespace Options
{
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	MeshGenerator::MeshGenerator() : minMaxStep()						/* Default Constructor. */
	{
		
	}
	MeshGenerator::MeshGenerator(double min, double max, unsigned steps)  /* Overloaded Constructor. Set meshStep AND "Load" all elements of minMaxes to min and max for each poss parameter. */
	{
		// Handle 0s being passed as min or max:
		if (min <= 0 || max <= 0)
		{
			throw Exceptions::GeneratorExcept("MeshGenerator Constructor Error: Min and max must be > 0.");
		}
		else if (steps <= 0)
		{
			throw Exceptions::GeneratorExcept("MeshGenerator Constructor Error: Steps must be > 0.");
		}
		else if(min > max)	// If min > max, swap to prevent issues.
		{
			double minCopy = min;
			min = max;
			max = minCopy;
		}
		minMaxStep.emplace("t", std::make_tuple(min, max, steps));
		minMaxStep.emplace("s", std::make_tuple(min, max, steps));
		minMaxStep.emplace("r", std::make_tuple(min, max, steps));
		minMaxStep.emplace("sigma", std::make_tuple(min, max, steps));
		minMaxStep.emplace("b", std::make_tuple(min, max, steps));
		minMaxStep.emplace("k", std::make_tuple(min, max, steps));
	}
	MeshGenerator::MeshGenerator(const MeshGenerator &meshGen_in) : minMaxStep(meshGen_in.minMaxStep)			/* Copy Constructor. */
		
	{

	}
	MeshGenerator::~MeshGenerator()								/* Destructor. */
	{

	}
	/////////////////////////////
	// Accessors:
	/////////////////////////////
	Map MeshGenerator::MinMaxStep() const																	  /* Return copy of minMaxStep object. */
	{
		return minMaxStep;
	}
	double MeshGenerator::Max(const std::string &key) const													  /* Return loaded max of passed parameter. */
	{
		try
		{
			return std::get<1>(minMaxStep.at(key));
		}
		catch (...)
		{
			throw Exceptions::GeneratorExcept("MeshGenerator::Max() Error: key \"" + key + "\" is invalid/not loaded.");
		}
	}
	double MeshGenerator::Min(const std::string &key) const													/* Return loaded min of passed parameter. */
	{
		try
		{
			return std::get<0>(minMaxStep.at(key));
		}
		catch (...)
		{
			throw Exceptions::GeneratorExcept("MeshGenerator::Min() Error: key \"" + key + "\" is invalid/not loaded.");
		}
	}
	unsigned MeshGenerator::Step(const std::string &key) const	/* Return loaded step of passed parameter. */
	{
		try
		{
			return std::get<2>(minMaxStep.at(key));
		}
		catch (...)
		{
			throw Exceptions::GeneratorExcept("MeshGenerator::Step() Error: key \"" + key + "\" is invalid/not loaded.");
		}
	}
	/////////////////////////////
	// Mutators:
	/////////////////////////////
	void MeshGenerator::Clear()									/* Erase all elements of minMaxStep. */
	{
		minMaxStep.clear();
	}
	void MeshGenerator::Load(const std::string &key, double min, double max, unsigned step) /* Load passed parameter val OR alter passed parameter's min, max and step. */
	{
		if (min > max) // If min is greater than max, swap to prevent issues.
		{
			double minCopy = min;
			min = max;
			max = minCopy;
		}
		if (!(key == "s" || key == "t" || key == "s" || key == "sigma" || key == "b" || key == "k" || key == "r"))
		{
			throw Exceptions::GeneratorExcept("MeshGenerator::Load() Error: Parameter \"" + key + "\" is invalid.");
		}
		else if (min <= 0 || max <= 0) // If min or max are equal or less than 0, throw exception to prevent generator issues.
		{
			throw Exceptions::GeneratorExcept("MeshGenerator::Load() Error: Min and Max must be > 0.");
		}
		else if (minMaxStep.find(key) == minMaxStep.end()) // If key is not in map, emplace with min and max.
		{
			minMaxStep.emplace(key, std::make_tuple(min, max, step));
		}
		else // Replace parameters' min and max if already in minMaxes.
		{
			minMaxStep.at(key) = std::make_tuple(min, max, step);
		}
	}
	void MeshGenerator::Unload(const std::string &key)				/* Eliminate passed parameter from minMaxStep (will not be used in Generate/GenerateN). */
	{
		if (!(key == "s" || key == "t" || key == "s" || key == "sigma" || key == "b" || key == "k"))
		{
			throw Exceptions::GeneratorExcept("MeshGenerator::Unload() Error: Parameter \"" + key + "\" is invalid.");
		}
		else if (minMaxStep.find(key) != minMaxStep.end()) // If key is in map, eliminate element.
		{
			minMaxStep.erase(key);
		}
	}
	/////////////////////////////
	// Misc. Methods:
	/////////////////////////////
	std::string MeshGenerator::Description() const					/* Return description of loaded parameters with their mins, maxes and steps. */
	{
		std::strstream ss;
		if (minMaxStep.size() == 0)
		{
			ss << "No parameters loaded.";
			ss << '\0';
		}
		else
		{
			Map::const_iterator iter;
			for (iter = minMaxStep.begin(); iter != minMaxStep.end(); iter++)
			{
				ss << iter->first << ": (" << std::get<0>(iter->second) << ", " << std::get<1>(iter->second) << ", " << std::get<2>(iter->second) << ")";
				if (iter != --minMaxStep.end())
				{
					ss << ", ";
				}
			}
			ss << '\0';
		}
		return ss.str();
	}
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	MeshGenerator& MeshGenerator::operator=(const MeshGenerator &in)				/* Assignment Operator. */
	{
		if (this != &in)
		{
			minMaxStep = in.minMaxStep;
		}
		return *this;
	}
}