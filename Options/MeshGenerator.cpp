/* MeshGenerator.cpp
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
	MeshGenerator::MeshGenerator(double min, double max, double step)  /* Overloaded Constructor. Set meshStep AND "Load" all elements of minMaxes to min and max for each poss parameter. */
	{
		// Handle 0s being passed as min or max:
		if (min <= 0 || max <= 0)
		{
			throw Exceptions::GeneratorExcept("MeshGenerator Constructor Error: Min and max must be > 0.");
		}
		else if (step <= 0)
		{
			throw Exceptions::GeneratorExcept("MeshGenerator Constructor Error: Step must be > 0.");
		}
		else if(min > max)	// If min > max, swap to prevent issues.
		{
			double minCopy = min;
			min = max;
			max = minCopy;
		}
		minMaxStep.emplace("t", std::make_tuple(min, max, step));
		minMaxStep.emplace("s", std::make_tuple(min, max, step));
		minMaxStep.emplace("r", std::make_tuple(min, max, step));
		minMaxStep.emplace("sigma", std::make_tuple(min, max, step));
		minMaxStep.emplace("b", std::make_tuple(min, max, step));
		minMaxStep.emplace("k", std::make_tuple(min, max, step));
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
	double MeshGenerator::Max(const std::string &key) const		/* Return loaded max of passed parameter. */
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
	double MeshGenerator::Min(const std::string &key) const		/* Return loaded min of passed parameter. */
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
	double MeshGenerator::Step(const std::string &key) const	/* Return loaded step of passed parameter. */
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
	void MeshGenerator::Load(const std::string &key, double min, double max, double step) /* Load passed parameter val OR alter passed parameter's min, max and step. */
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