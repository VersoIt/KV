#pragma once
#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "Base.h"

class Arithmetic : public Base
{
public:

	Arithmetic();

	Arithmetic(Base* parent, const std::string& name);

	void Handle(std::string message);

	void Signal(std::string& message);

	virtual int GetClassNumber() override;

	TYPE_SIGNAL GetSignalPointer() override;

	TYPE_HANDLER GetHandlerPointer() override;
};

#endif // ARITHMETIC_H