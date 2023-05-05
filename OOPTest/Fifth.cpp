#include "Fifth.h"

#include <iostream>

Fifth::Fifth() : Base(nullptr, "")
{
}

Fifth::Fifth(Base* parent, const std::string& name = "UNKNOWN") : Base(parent, name) {}

void Fifth::Handle(std::string message)
{
	std::cout << std::endl << "Signal to " << getAbsolutePath() << " Text: " << message;
}

void Fifth::Signal(std::string& message)
{
	std::cout << std::endl << "Signal from " << getAbsolutePath();
	message += " (class: 5)";
}

int Fifth::GetClassNumber()
{
	return 5;
}

TYPE_SIGNAL Fifth::GetSignalPointer()
{
	return SIGNAL_D(Fifth::Signal);
}

TYPE_HANDLER Fifth::GetHandlerPointer()
{
	return HANDLER_D(Fifth::Handle);
}