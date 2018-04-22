/* Main.cpp (exercise 2.7)
Description:
	* Solutions to problems 1-5.
*/

#include <cerrno>
#include <fstream>
#include <boost\system\error_code.hpp>
#include <string>
#include <vector>
#include "Wrappers.hpp"


int main()
{
	/* 2.7.1 */
	// c) Test ReadFile with existing file and nonexisting file:
	// File exists:
	std::cout << "Testing Boost version: " << std::endl;
	std::cout << "Opening file misc.txt: " << std::endl;
	boost::system::error_condition result1(ReadFile_boost("misc.txt"));
	std::cout << "Error message: " << result1.message() << std::endl;
	// File does not exist:
	boost::system::error_condition result2(ReadFile_boost("not_exist.txt"));
	std::cout << "Opening file not_exist.txt: " << std::endl;
	std::cout << "Error message: " << result2.message() << std::endl;

	// d) Test the C++11 version of above boost ReadFile function:
	std::cout << "Testing C++11 version: " << std::endl;
	std::cout << "Opening file misc.txt: " << std::endl;
	std::error_condition result3(ReadFile_cpp11("misc.txt"));
	std::cout << "Error message: " << result3.message() << std::endl;
	std::error_condition result4(ReadFile_cpp11("not_exist.txt"));
	std::cout << "Opening file not_exist.txt: " << std::endl;
	std::cout << "Error message: " << result4.message() << std::endl;

	/* 2.7.2 */
	// a) create instances of std::error_condition based on requirements:
	// Default constructor:
	std::error_condition err1;
	// Value and error category:
	std::error_condition err2(errno, std::generic_category());
	// Using std::errc code:
	std::error_condition err3(std::errc::file_exists);
	
	// b) Test the error_condition tuple returning function:
	std::vector<std::tuple<std::string, int, std::string>> errors;
	errors.push_back(GetCharacteristics_independent(err1));
	errors.push_back(GetCharacteristics_independent(err2));
	errors.push_back(GetCharacteristics_independent(err3));

	// Print the characteristics of each error:
	std::cout << "Output characteristics of error_conditions: "<< std::endl;
	for (auto &item : errors)
	{
		std::cout << "Message: " << std::get<0>(item) << std::endl;
		std::cout << "Error Number: " << std::get<1>(item) << std::endl;
		std::cout << "Error Category: " << std::get<2>(item) << std::endl;
	}

	/* 2.7.3 */
	// a) Create error_condition instances using POSIX error codes in scoped enumerator errc:
	std::error_condition err4(std::errc::io_error);
	std::error_condition err5(std::errc::network_unreachable);
	std::error_condition err6(std::errc::no_such_file_or_directory);
	std::error_condition err7(std::errc::not_a_socket);
	std::error_condition err8(std::errc::permission_denied);
	// b) Create error_condition using value 128 and generic error category:
	std::error_condition err9(128, std::generic_category());
	// c) Use make_error_condition with io_errc to create instance of error_condition:
	std::error_condition err10(std::make_error_condition(std::io_errc()));

	/* 2.7.4 */
	// a) Create default error code and platform dependent error code:
	std::error_code default_errc;
	std::error_code dependent_errc(0, std::generic_category());
	// b) Test error_code characteristic returning function:
	std::vector<std::tuple<std::string, int, std::string>> errors2;
	errors2.push_back(GetCharacteristics_dependent(default_errc));
	errors2.push_back(GetCharacteristics_dependent(dependent_errc));
	std::cout << "Output characteristics of error_code: " << std::endl;
	for (auto item : errors2)
	{
		std::cout << "Message: " << std::get<0>(item) << std::endl;
		std::cout << "Error Number: " << std::get<1>(item) << std::endl;
		std::cout << "Error Category: " << std::get<2>(item) << std::endl;
	}
	// c) Test equality/inequality of error_code and error_condition instances:
	std::cout << "io_error vs network_unreachable: " << (err4 == err5) << std::endl;
	std::cout << "io_eror vs no_such_file_or_directory: " << (err4 == err6) << std::endl;
	std::cout << "io_error vs not_a_Socket: " << (err4 == err7) << std::endl;
	std::cout << "io_error vs permission_denied: " << (err4 == err8) << std::endl;
	std::cout << "io_error vs generic error: " << (err4 == err9) << std::endl;
	std::cout << "io_error vs io_errc: " << (err4 == err10) << std::endl;

	/* 2.7.5 */
	// a-c) Adjust the provided code based upon specifications:
	std::ifstream file(std::string("DOESNOTEXIST.txt"));
	try 
	{ 
		// Set the exception mask of the file stream 
		// In this case 1) logical error on I/O operation or 
		// 2) read/write error on I/O operation 
		file.exceptions(file.failbit | file.badbit); 
	} 
	catch (const std::ios_base::failure& e) 
	{ 
		std::cout << "Code: " << e.code() << ", Stream: " << std::io_errc::stream << std::endl;
		if (e.code() == std::io_errc::stream)
		{
			std::error_code ec1(e.code());
			std::error_code ec2(ec1);
			std::tuple<std::string, int, std::string> result(GetCharacteristics_dependent(ec2));
			std::cout << "Value: " << std::get<1>(result) << ", Message: " << std::get<0>(result) << ", Category: " << std::get<2>(result) << std::endl;
		}
	} 
	catch (...) 
	{ 
		std::cout << "catch all\n"; 
	}

	system("pause");
	
	return 0;
}