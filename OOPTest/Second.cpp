#include "Second.h"

#include <iostream>

Second::Second() : Base(nullptr, "")
{
}

Second::Second(Base* parent, const std::string& name = "UNKNOWN") : Base(parent, name) {}

void Second::Handle(std::string message)
{
	std::cout << std::endl << "Signal to " << getAbsolutePath() << " Text: " << message;
}

void Second::Signal(std::string& message)
{
	std::cout << std::endl << "Signal from " << getAbsolutePath();
	message += " (class: 2)";
}

int Second::GetClassNumber()
{
	return 2;
}

TYPE_SIGNAL Second::GetSignalPointer()
{
	return SIGNAL_D(Second::Signal);
}

TYPE_HANDLER Second::GetHandlerPointer()
{
	return HANDLER_D(Second::Handle);
}