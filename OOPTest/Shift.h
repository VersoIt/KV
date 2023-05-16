#pragma once
#ifndef SHIFT_H
#define SHIFT_H

#include "Base.h"

class Shift : public Base
{
public:

	Shift();

	Shift(Base* parent, const std::string& name);

	void Handle(std::string message);

	void Signal(std::string& message);

	virtual int GetClassNumber() override;

	TYPE_SIGNAL GetSignalPointer() override;

	TYPE_HANDLER GetHandlerPointer() override;
};

#endif // SHIFT_H