#pragma once
#pragma once
#ifndef CLEAR_H
#define CLEAR_H

#include "Base.h"

class Clear : public Base
{
public:

	Clear();

	Clear(Base* parent, const std::string& name);

	void Handle(std::string message);

	void Signal(std::string& message);

	virtual int GetClassNumber() override;

	TYPE_SIGNAL GetSignalPointer() override;

	TYPE_HANDLER GetHandlerPointer() override;
};

#endif // FIFTH_H