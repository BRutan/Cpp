/* Wrappers.hpp (exercise 2.7.1, 2.7.2, 2.7.4)
Description:
	* Solutions to exercise 2.7.1, 2.7.2, 2.7.4.
Functions:
	* ReadFile_boost(const string &filePath) noexcept: Open file at filepath, return boost error if could not be opened.
	* ReadFile_cpp11(const string &filePath) noexcept: Open file at filepath, return c++11 error_condition if could not be opened.
	* GetCharacteristics_independent(const error_condition &err) noexcept: Return tuple containing message, error number and category for passed error_condition.
	* GetCharacteristics_dependent(const error_code &err) noexcept: Return tuple containing message, error number and category for passed error_code.
*/

#ifndef WRAPPERS_HPP
#define WRAPPERS_HPP

#include <cerrno>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <boost/system/error_code.hpp>

/* 2.7.1 */
// a) Create function to read file, return boost error condition if file could not be opened:
boost::system::error_condition ReadFile_boost(const std::string &filePath) noexcept
{
	std::ifstream file_in(filePath.c_str(), std::ifstream::in);
	if (!file_in.is_open())
	{
		return boost::system::errc::make_error_condition(boost::system::errc::no_such_file_or_directory);
	}
	// If file was successfully opened then print all contents:
	std::cout << file_in.rdbuf() << std::endl;
	// Close file:
	file_in.close();
	// Return success:
	return boost::system::errc::make_error_condition(boost::system::errc::success);
}

// d) Create C++11 version of above function:
std::error_condition ReadFile_cpp11(const std::string &filePath) noexcept
{
	std::ifstream file_in(filePath.c_str(), std::ifstream::in);
	if (!file_in.is_open())
	{
		return std::error_condition(errno, std::iostream_category());
	}
	// If file was successfully opened then print all contents:
	std::cout << file_in.rdbuf() << std::endl;
	// Close file:
	file_in.close();
	// Return success, i.e. no error code:
	return std::error_condition();
}

/* 2.7.2 */ 
// d) Create function to return characteristics of passed error_condition: 
std::tuple<std::string, int, std::string> GetCharacteristics_independent(const std::error_condition &err_in) noexcept
{
	std::string message(err_in.message());
	std::string category(err_in.category().name());
	int value(err_in.value());
	std::tuple<std::string, int, std::string> output(std::move(message), std::move(value), std::move(category));
	return output;
}

/* 2.7.4 */
// b) Create function to return characteristics of error_code:
std::tuple<std::string, int, std::string> GetCharacteristics_dependent(const std::error_code &err_in) noexcept
{
	std::string message(err_in.message());
	std::string category(err_in.category().name());
	int value(err_in.value());
	std::tuple<std::string, int, std::string> output(std::move(message), std::move(value), std::move(category));
	return output;
}


#endif 

