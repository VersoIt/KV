#pragma once
#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#define DIVISION_BY_ZERO "Division by zero"
#define ARITHMETIC_OVERFLOW "Overflow"

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