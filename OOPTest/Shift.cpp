#include "Shift.h"

#include <iostream>

Shift::Shift() : Base(nullptr, "")
{
}

Shift::Shift(Base* parent, const std::string& name) : Base(parent, name) {}

void Shift::Handle(std::string message)
{
	std::cout << std::endl << "Signal to " << getAbsolutePath() << " Text: " << message;
}

void Shift::Signal(std::string& message)
{
	std::cout << std::endl << "Signal from " << getAbsolutePath();
	message += " (class: 4)";
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