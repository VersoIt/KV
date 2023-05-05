#include "Third.h"

#include <iostream>

Third::Third() : Base(nullptr, "")
{
}

Third::Third(Base* parent, const std::string& name = "UNKNOWN") : Base(parent, name) {}

void Third::Handle(std::string message)
{
	std::cout << std::endl << "Signal to " << getAbsolutePath() << " Text: " << message;
}

void Third::Signal(std::string& message)
{
	std::cout << std::endl << "Signal from " << getAbsolutePath();
	message += " (class: 3)";
}

int Third::GetClassNumber()
{
	return 3;
}

TYPE_SIGNAL Third::GetSignalPointer()
{
	return SIGNAL_D(Third::Signal);
}

TYPE_HANDLER Third::GetHandlerPointer()
{
	return HANDLER_D(Third::Handle);
}