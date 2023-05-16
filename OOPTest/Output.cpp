#include "Output.h"

#include <iostream>

Output::Output() : Base(nullptr, "")
{
}

Output::Output(Base* parent, const std::string& name) : Base(parent, name) {}

void Output::Handle(std::string message)
{
	std::cout << std::endl << "Signal to " << getAbsolutePath() << " Text: " << message;
}

void Output::Signal(std::string& message)
{
	std::cout << std::endl << "Signal from " << getAbsolutePath();
	message += " (class: 6)";
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