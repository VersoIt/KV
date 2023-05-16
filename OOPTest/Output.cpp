#include "Output.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <algorithm>

Output::Output() : Base(nullptr, "")
{
}

Output::Output(Base* parent, const std::string& name) : Base(parent, name) {}

void Output::Handle(std::string message)
{
}

std::string ToHex(int number)
{
	std::stringstream ss;
	ss << std::setfill('0') << std::setw(4) << std::hex << number;

	std::string result = ss.str();
	std::for_each(result.begin(), result.end(), [](char& e) {
		e = std::toupper(e);
		});

	return result.substr(result.size() - 4, result.size());
}

std::string ToBin(int number)
{
	std::bitset<16> binary(number);
	std::string binaryStr = "";

	for (int i = 0; i < binary.size(); ++i)
	{
		binaryStr += std::to_string(binary[i]);
		if ((i + 1) % 4 == 0 && i != binary.size() - 1)
		{
			binaryStr += " ";
		}
	}

	std::reverse(binaryStr.begin(), binaryStr.end());
	return binaryStr;
}

void Output::Signal(std::string& message)
{
	if (IsNumber(message))
	{
		int number = std::stoi(message);
		std::cout << "     " << "HEX" << " " << ToHex(number) << "  " << "DEC " << number << "  " << "BIN" << " " << ToBin(number);
		return;
	}

	std::cout << "     " << message;
}

int Output::GetClassNumber()
{
	return 6;
}

TYPE_SIGNAL Output::GetSignalPointer()
{
	return SIGNAL_D(Output::Signal);
}

TYPE_HANDLER Output::GetHandlerPointer()
{
	return HANDLER_D(Output::Handle);
}

bool Output::IsNumber(std::string str)
{
	std::istringstream is(str);
	int number;

	is >> number;
	return is.eof() && !is.fail();
}