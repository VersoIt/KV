#include "Fourth.h"

#include <iostream>

Fourth::Fourth() : Base(nullptr, "")
{
}

Fourth::Fourth(Base* parent, const std::string& name = "UNKNOWN") : Base(parent, name) {}

void Fourth::Handle(std::string message)
{
	std::cout << std::endl << "Signal to " << getAbsolutePath() << " Text: " << message;
}

void Fourth::Signal(std::string& message)
{
	std::cout << std::endl << "Signal from " << getAbsolutePath();
	message += " (class: 4)";
}

int Fourth::GetClassNumber()
{
	return 4;
}

TYPE_SIGNAL Fourth::GetSignalPointer()
{
	return SIGNAL_D(Fourth::Signal);
}

TYPE_HANDLER Fourth::GetHandlerPointer()
{
	return HANDLER_D(Fourth::Handle);
}