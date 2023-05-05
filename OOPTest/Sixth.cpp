#include "Sixth.h"

#include <iostream>

Sixth::Sixth() : Base(nullptr, "")
{
}

Sixth::Sixth(Base* parent, const std::string& name = "UNKNOWN") : Base(parent, name) {}

void Sixth::Handle(std::string message)
{
	std::cout << std::endl << "Signal to " << getAbsolutePath() << " Text: " << message;
}

void Sixth::Signal(std::string& message)
{
	std::cout << std::endl << "Signal from " << getAbsolutePath();
	message += " (class: 6)";
}

int Sixth::GetClassNumber()
{
	return 6;
}

TYPE_SIGNAL Sixth::GetSignalPointer()
{
	return SIGNAL_D(Sixth::Signal);
}

TYPE_HANDLER Sixth::GetHandlerPointer()
{
	return HANDLER_D(Sixth::Handle);
}