#include "Arithmetic.h"

#include <sstream>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <algorithm>

Arithmetic::Arithmetic() : Base(nullptr, "")
{
}

Arithmetic::Arithmetic(Base* parent, const std::string& name) : Base(parent, name) {}

std::string ToHex(int number)
{
	std::stringstream ss;
	ss << std::setfill('0') << std::setw(4) << std::hex << number;

	std::string result = ss.str();
	std::for_each(result.begin(), result.end(), [](char& e) {
		e = std::toupper(e);
	});

	return result;
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

void Arithmetic::Handle(std::string message)
{
	std::cout << std::endl << "Signal to " << getAbsolutePath() << " Text: " << message;
}

void Arithmetic::Signal(std::string& message)
{
	int firstOperand;
	std::string command;
	int secondOperand;

	std::stringstream ss(message);
	ss >> firstOperand;
	while (ss >> command >> secondOperand)
	{
		if (command == "+")
		{
			firstOperand += secondOperand;
		}
		else if (command == "/")
		{
			firstOperand /= secondOperand;
		}
		else if (command == "*")
		{
			firstOperand *= secondOperand;
		}
		else if (command == "-")
		{
			firstOperand -= secondOperand;
		}
	}

	std::cout << "     " << "HEX" << " " << ToHex(firstOperand) << "  " << "DEC " << firstOperand << "  " << "BIN" << " " << ToBin(firstOperand);
}

int Arithmetic::GetClassNumber()
{
	return 3;
}

TYPE_SIGNAL Arithmetic::GetSignalPointer()
{
	return SIGNAL_D(Arithmetic::Signal);
}

TYPE_HANDLER Arithmetic::GetHandlerPointer()
{
	return HANDLER_D(Arithmetic::Handle);
}