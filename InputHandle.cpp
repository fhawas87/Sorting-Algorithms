#include <iostream>
#include <vector>
#include <cstdint>
#include <sstream>

const auto StringToNumber(const std::string& TempStringInput) {

	int32_t IntInput;

	for (const char &Char : TempStringInput) {

		IntInput *= 10;
		IntInput += (Char - '0');
	}

	return IntInput;
}

void GetInputNumbersAsString(std::vector<int32_t> &InputNumbers) {

	std::string StringInput;
	std::string TempStringInput;

	std::cout << "Enter space seperated numbers : ";
	std::getline(std::cin, StringInput);

	std::stringstream StringStream(StringInput);

	while (StringStream >> TempStringInput) {

		InputNumbers.emplace_back(StringToNumber(TempStringInput));

	}
}