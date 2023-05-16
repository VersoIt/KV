#include "Reader.h"

#define OFF "Off"
#define SHOW_TREE "SHOWTREE"

#include <sstream>
#include <iostream>

bool IsNumber(std::string str)
{
	std::istringstream is(str);
	int number;

	is >> number;
	return is.eof() && !is.fail();
}

Reader::Reader() : Base(nullptr, "")
{
}

Reader::Reader(Base* parent, const std::string& name) : Base(parent, name) {}

void Reader::Handle(std::string message)
{
	std::cout << message;
}

void Reader::Signal(std::string& message)
{

	std::string firstOperand;
	std::string command;
	std::string secondOperand;

	std::cin >> firstOperand;

	if (firstOperand == "+" || firstOperand == "-" || firstOperand == "*" || firstOperand == "/")
	{
		std::cin >> secondOperand;
		message += " " + firstOperand + " " + secondOperand;
		std::cout << message;
		return;
	}

	if (firstOperand == OFF)
	{
		message = OFF;
		return;
	}

	if (firstOperand == SHOW_TREE)
	{
		message = SHOW_TREE;
		return;
	}

	std::cin >> command;

	while (IsNumber(command))
	{
		firstOperand = command;
		std::cin >> command;
	}

	if (command == OFF)
	{
		message = OFF;
		return;
	}

	if (command == SHOW_TREE)
	{
		message = SHOW_TREE;
		return;
	}

	std::cin >> secondOperand;

	message = firstOperand + " " + command + " " + secondOperand;

	std::cout << message;
}

int Reader::GetClassNumber()
{
	return 2;
}

TYPE_SIGNAL Reader::GetSignalPointer()
{
	return SIGNAL_D(Reader::Signal);
}

TYPE_HANDLER Reader::GetHandlerPointer()
{
	return HANDLER_D(Reader::Handle);
}