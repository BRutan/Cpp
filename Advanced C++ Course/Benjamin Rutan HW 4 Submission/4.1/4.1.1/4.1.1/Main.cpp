/* Main.cpp (exercise 4.1.1) TODO fix next_permutation, not giving full permutation lists.



*/

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Proposition.hpp"

int main()
{
	/* 4.1.1 */
	Proposition A(true), B(true), C(false);

	// c) Check that code satisfies De Morgan's laws:
	std::cout << "A: " << A << ", B: " << B << ", C: " << C << std::endl;
	std::cout << "NOT(A OR B): " << !(A | B) << std::endl;
	std::cout << "NOT(A) AND NOT(B): " << (!A & !B) << std::endl;
	std::cout << "NOT(A AND B): " << !(A & B) << std::endl;
	std::cout << "NOT(A) OR NOT(B): " << (!(A) | !B) << std::endl;
	// d) Check that code satisfies the Distributive Laws:
	std::cout << "A AND(B OR C): " << (A & (B | C)) << std::endl;
	std::cout << "(A AND B) OR (A AND C): " << ((A & B) | (A & C)) << std::endl;
	std::cout << "A OR (B AND C): " << (A | (B & C)) << std::endl;
	std::cout << "(A OR B) AND (A OR C): " << ((A | B) & (A | C)) << std::endl;
	// e) Check tautologies (four scenarios: 0 true, 1 true, 2 trues, 3 trues):
	// Scenario 1: 0 true
	std::vector<Proposition> outputs;
	std::vector<std::string> tautStrings;
	std::stringstream currStream;
	std::size_t permutCount = 0;
	Proposition vals[3] = { 0, 0, 0 };
	outputs.push_back((vals[0] % (vals[1] % vals[2])) %= ((vals[0] & vals[1]) % vals[2]));
	currStream.str(std::string());
	currStream << "[" << vals[0] << "->(" << vals[1] << "->" << vals[2] << ")]<->[(" << vals[0] << "&" << vals[1] << ")->" << vals[2] << "]";
	tautStrings.push_back(currStream.str());
	
	// Scenario 2: 1 true
	vals[0] = 0; vals[1] = 0; vals[2] = 1;
	// std::sort(vals, vals + 2);
	while (std::next_permutation(vals, vals + 2))
	{
		outputs.push_back((vals[0] % (vals[1] % vals[2])) %= ((vals[0] & vals[1]) % vals[2]));
		currStream.str(std::string());
		currStream << "[" << vals[0] << "->(" << vals[1] << "->" << vals[2] << ")]<->[(" << vals[0] << "&" << vals[1] << ")->" << vals[2] << "]";
		tautStrings.push_back(currStream.str());
	}
	
	// Scenario 3: 2 true
	vals[0] = 0; vals[1] = 1; vals[2] = 1;
	//std::sort(vals, vals + 2);
	while (std::next_permutation(vals, vals + 2))
	{
		outputs.push_back((vals[0] % (vals[1] % vals[2])) %= ((vals[0] & vals[1]) % vals[2]));
		currStream.str(std::string());
		currStream << "[" << vals[0] << "->(" << vals[1] << "->" << vals[2] << ")]<->[(" << vals[0] << "&" << vals[1] << ")->" << vals[2] << "]";
		tautStrings.push_back(currStream.str());
	}

	// Scenario 4: 3 true
	vals[0] = 1; vals[1] = 1; vals[2] = 1;
	outputs.push_back((vals[0] % (vals[1] % vals[2])) %= ((vals[0] & vals[1]) % vals[2]));
	currStream.str(std::string());
	currStream << "[" << vals[0] << "->(" << vals[1] << "->" << vals[2] << ")]<->[(" << vals[0] << "&" << vals[1] << ")->" << vals[2] << "]";
	tautStrings.push_back(currStream.str());

	// Print the results of all 8 possible tautologies, should all be true:
	for (std::size_t i = 0; i < outputs.size(); i++)
	{
		std::cout << tautStrings[i] << ": " << outputs[i] << std::endl;
	}
	
	system("pause");

	return 0;
}