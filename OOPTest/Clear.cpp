#include "Clear.h"

#include <iostream>

Clear::Clear() : Base(nullptr, "")
{
}

Clear::Clear(Base* parent, const std::string& name) : Base(parent, name) {}

void Clear::Handle(std::string message)
{
}

void Clear::Signal(std::string& message)
{
	message = "";
}

int Clear::GetClassNumber()
{
	return 5;
}

TYPE_SIGNAL Clear::GetSignalPointer()
{
	return SIGNAL_D(Clear::Signal);
}

TYPE_HANDLER Clear::GetHandlerPointer()
{
	return HANDLER_D(Clear::Handle);
}