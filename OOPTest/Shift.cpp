#include "Shift.h"

#include "Arithmetic.h"

#include <iostream>
#include <sstream>

Shift::Shift() : Base(nullptr, "")
{
}

Shift::Shift(Base* parent, const std::string& name) : Base(parent, name) {}

void Shift::Handle(std::string message)
{
}

void Shift::Signal(std::string& message)
{
	std::stringstream ss(message);
	int firstOperand;
	std::string command;
	int lastOperand;

	ss >> firstOperand >> command >> lastOperand;
	if (command == SHIFT_LEFT)
		firstOperand <<= lastOperand;
	else if (command == SHIFT_RIGHT)
		firstOperand >>= lastOperand;

	if (firstOperand != static_cast<short>(firstOperand))
	{
		std::cout << "     " << ARITHMETIC_OVERFLOW;
		message = ARITHMETIC_OVERFLOW;
	}
	else
		message = std::to_string(firstOperand);
}

int Shift::GetClassNumber()
{
	return 4;
}

TYPE_SIGNAL Shift::GetSignalPointer()
{
	return SIGNAL_D(Shift::Signal);
}

TYPE_HANDLER Shift::GetHandlerPointer()
{
	return HANDLER_D(Shift::Handle);
}