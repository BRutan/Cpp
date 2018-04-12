/* Main.cpp (exercise 1.5 problems 1-5)
Description:
	*Solutions to problems 1-5.
*/

#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS

#include <boost\assign.hpp>
#include <boost\date_time.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "Builder.hpp"
#include "Calculator.hpp"
#include "Circle.hpp"
#include "CircleMonitorBuilder.hpp"
#include "CircleTVBuilder.hpp"
#include "Exception.hpp"
#include "Functions-1.hpp"
#include "Functions-3.hpp"
#include "Functions-4.hpp"
#include "LineMonitorBuilder.hpp"
#include "LineTVBuilder.hpp"
#include "Monitor.hpp"
#include "SizeExcept.hpp"
#include "TV.hpp"

int main()
{
	/* 1.5.1 */
	// a) Use std:tuple<> to emulate a Person class (std::tuple<Name, Address, DateOfBirth>)
	Person personA, personB, personC;
	// Set the name of each person:
	std::get<0>(personA) = "A";
	std::get<0>(personB) = "B";
	std::get<0>(personC) = "C";
	// Set the address of each person:
	std::get<1>(personA) = "123 Main St";
	std::get<1>(personB) = "124 Main St";
	std::get<1>(personC) = "125 Main St";
	// Set the date of birth for each person:
	std::get<2>(personA) = std::move(boost::gregorian::from_string("2016-3-14"));
	std::get<2>(personB) = std::move(boost::gregorian::from_string("2017-3-14"));
	std::get<2>(personC) = std::move(boost::gregorian::from_string("2018-3-14"));
	// c) Create a list/vector of Persons and add instances:
	std::vector<Person> persons = { personA, personB, personC };
	// d) Test the sorting function:
	// Display unsorted persons vector:
	std::cout << "Unsorted persons vector: " << std::endl;
	std::for_each(persons.begin(), persons.end(), printPerson);
	// Sort and display sorted persons vector (by Name ascending):
	SortPersons<0>(persons, false);
	std::cout << "Sorted persons vector (by Name ascending): " << std::endl;
	std::for_each(persons.begin(), persons.end(), printPerson);
	// Sort and display sorted persons vector (by Name descending):
	SortPersons<0>(persons, true);
	std::cout << "Sorted persons vector (by Name descending): " << std::endl;
	std::for_each(persons.begin(), persons.end(), printPerson);
	// Sort and display sorted persons vector (by Date ascending):
	SortPersons<2>(persons, false);
	std::cout << "Sorted persons vector (by Date ascending): " << std::endl;
	std::for_each(persons.begin(), persons.end(), printPerson);
	// Sort and display sorted persons vector (by Date descending):
	SortPersons<2>(persons, true);
	std::cout << "Sorted persons vector (by Date descending): " << std::endl;
	std::for_each(persons.begin(), persons.end(), printPerson);

	/* 1.5.2 */
	// b) Test Calculator struct's static functions on tuples of varying sizes:
	std::tuple<double, double> pair = std::make_tuple<double, double>(1.0, 2.0);
	std::tuple<double, double, double> triplet = std::make_tuple<double, double, double>(1.0, 2.0, 3.0);
	std::tuple<double, double, double, double> quadruplet = std::make_tuple<double, double, double, double>(1.0, 2.0, 3.0, 4.0);
	std::cout << "Pair { 1.0, 2.0 }" << std::endl;
	std::cout << "Max: " << Calculator<double, std::tuple<double, double>, 2>::maximum(pair) << std::endl;
	std::cout << "Sum: " << Calculator<double, std::tuple<double, double>, 2>::sum(pair) << std::endl;
	std::cout << "Avg: " << Calculator<double, std::tuple<double, double>, 2>::average(pair) << std::endl;
	std::cout << "Triplet { 1.0, 2.0, 3.0 }" << std::endl;
	std::cout << "Max: " << Calculator<double, std::tuple<double, double, double>, 3>::maximum(triplet) << std::endl;
	std::cout << "Sum: " << Calculator<double, std::tuple<double, double, double>, 3>::sum(triplet) << std::endl;
	std::cout << "Avg: " << Calculator<double, std::tuple<double, double, double>, 3>::average(triplet) << std::endl;
	std::cout << "Quadruplet { 1.0, 2.0, 3.0, 4.0 }" << std::endl;
	std::cout << "Max: " << Calculator<double, std::tuple<double, double, double, double>, 4>::maximum(quadruplet) << std::endl;
	std::cout << "Sum: " << Calculator<double, std::tuple<double, double, double, double>, 4>::sum(quadruplet) << std::endl;
	std::cout << "Avg: " << Calculator<double, std::tuple<double, double, double, double>, 4>::average(quadruplet) << std::endl;
	// c) Test sum and average functions with tuple of std::complex<int> type:
	std::tuple<std::complex<int>, std::complex<int>> complexPair = std::make_tuple<std::complex<int>, std::complex<int>>(std::complex<int>(4, 3), std::complex<int>(5, 6));
	std::cout << "Complex Tuple {(4,3), (5,6)}: " << std::endl;
	std::cout << "Sum: " << Calculator<std::complex<int>, std::tuple<std::complex<int>, std::complex<int>>, 2>::sum(complexPair) << std::endl;
	std::cout << "Avg: " << Calculator<std::complex<int>, std::tuple<std::complex<int>, std::complex<int>>, 2>::average(complexPair) << std::endl;
	
	/* 1.5.3: */
	// b) Test the function implemented in a):
	std::vector<double> geyserDataVector{ 78,74,68,76,80,84,50, 93,55,76,58,74,75 };
	double mean, meanDev, range, stdDev, var;
	boost::numeric::ublas::vector<double, std::vector<double>> geyserData(geyserDataVector);
	std::tuple<double, double, double, double, double> statProperties = GetStatisticalProperties(geyserData);
	std::tie(mean, std::ignore, std::ignore, std::ignore, std::ignore) = statProperties;
	std::tie(std::ignore, meanDev, std::ignore, std::ignore, std::ignore) = statProperties;
	std::tie(std::ignore, std::ignore, range, std::ignore, std::ignore) = statProperties;
	std::tie(std::ignore, std::ignore, std::ignore, var, std::ignore) = statProperties;
	std::tie(std::ignore, std::ignore, std::ignore, std::ignore, stdDev) = statProperties;
	std::cout << "Geyser data { 78,74,68,76,80,84,50,93,55,76,58,74,75 } statistical properties: " << std::endl;
	std::cout << "Mean :" << mean << ", Mean Deviation: " << meanDev << std::endl;
	std::cout << "Range:" << range << ", Standard Deviation: " << stdDev << ", Variance: " << var << std::endl;
	// c) Sort the vector, then get the median and mode of the dataset:
	std::sort(geyserData.begin(), geyserData.end());
	double med = median<boost::numeric::ublas::vector, double>(geyserData);
	double mod = mode<boost::numeric::ublas::vector, double>(geyserData);
	std::cout << "Median: " << med << ", Mode: " << mod << std::endl;
	/* 1.5.4 */
	//// TODO: ensure relative error and abs error are correct.
	// a) Test the findIndex() procedure that returns index where v[i] <= x < v[i + 1] for given vector v and passed value x:
	std::vector<double> temp1 { 1, 2, 2, 3 };
	std::vector<double> temp2 { 1, 1, 1, 3 };
	std::vector<double> temp3 { 1, 1, 1, 1 };
	std::size_t index1 = findIndex<std::vector, double>(temp1, 2);
	std::size_t index2 = findIndex<std::vector, double>(temp2, 2);
	std::size_t index3 = findIndex<std::vector, double>(temp3, 2);
	std::cout << "For v_1 = {1, 2, 2, 3}, index i where v[i] <= 2 < v[i + 1]: " << index1 << std::endl;
	std::cout << "For v_2 = {1, 1, 1, 3}, index i where v[i] <= 2 < v[i + 1]: " << index2 << std::endl;
	std::cout << "For v_3 = {1, 1, 1, 1}, index i where v[i] <= 2 < v[i + 1]: " << index3 <<" (i.e. not found)" << std::endl;
	// b) Test the maximum error finding adapter for above vectors:
	std::pair<double, std::size_t> mRelError = maxError<std::vector, double>(temp1, temp2, std::make_pair<std::size_t, std::size_t>(0, 3), true);
	std::cout << "For v_1 and v_2: " << std::endl;
	std::cout << "Maximum relative error: " << std::get<0>(mRelError) << " at index " << std::get<1>(mRelError) << std::endl;
	std::pair<double, std::size_t> mAbsError = maxError<std::vector, double>(temp1, temp2, std::make_pair<std::size_t, std::size_t>(0, 3), false);
	std::cout << "Maximum absolute error: " << std::get<0>(mAbsError) << " at index " << std::get<1>(mAbsError) << std::endl;
	
	/* 1.5.5 */
	// a) Instantiate circle and line objects and display using input-output devices:
	Circle circ(1.0, 2.0);
	Line lin(Point(1.0, 2.0), Point(2.0, 3.0));
	TV tv_io;
	Monitor mon;
	tv_io << circ;
	mon << circ;
	tv_io << lin;
	mon << lin;
	// b) Configure shapes for input-output devices with builder objects:
	CircleMonitorBuilder cm;
	CircleTVBuilder cTV;
	LineMonitorBuilder lm;
	LineTVBuilder lTV;
	std::cout << "Builder generated combinations of Circle/Line objects with Monitor/TV objects:" << std::endl;
	std::tuple<ShapePointer, IODevicePointer> output = cm.getProduct();
	output = cTV.getProduct();
	std::get<0>(output)->display(*std::get<1>(output));
	output = lm.getProduct();
	std::get<0>(output)->display(*std::get<1>(output));
	output = lTV.getProduct();
	std::get<0>(output)->display(*std::get<1>(output));

	system("pause");

	return 0;
}