#include "Arithmetic.h"

#include <sstream>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <algorithm>

#define PLUS "+"
#define MINUS "-"
#define DIVIDE "/"
#define PRODUCT "*"

#define DIVISION_STAT "%"

Arithmetic::Arithmetic() : Base(nullptr, "")
{
}

Arithmetic::Arithmetic(Base* parent, const std::string& name) : Base(parent, name) {}

void Arithmetic::Handle(std::string message)
{
}

void Arithmetic::Signal(std::string& message)
{
	int firstOperand;
	std::string command;
	int secondOperand;

	std::stringstream ss(message);
	ss >> firstOperand;
	ss >> command >> secondOperand;

	if (command == PLUS)
	{
		firstOperand += secondOperand;
	}
	else if (command == DIVIDE)
	{
		if (secondOperand == 0)
		{
			std::cout << "     " << DIVISION_BY_ZERO;
			message = DIVISION_BY_ZERO;
			return;
		}
		firstOperand /= secondOperand;
	}
	else if (command == PRODUCT)
	{
		firstOperand *= secondOperand;
	}
	else if (command == MINUS)
	{
		firstOperand -= secondOperand;
	}
	else if (command == DIVISION_STAT)
	{
		firstOperand %= secondOperand;
	}

	if (firstOperand != static_cast<short>(firstOperand))
	{
		std::cout << "     " << ARITHMETIC_OVERFLOW;
		message = ARITHMETIC_OVERFLOW;
	}
	else
		message = std::to_string(firstOperand);
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