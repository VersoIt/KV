#pragma once
#ifndef SECOND_H
#define SECOND_H

#include "Base.h"

class Second : public Base
{

public:

	Second();

	Second(Base* parent, const std::string& name);

	void Handle(std::string message);

	void Signal(std::string& message);

	virtual int GetClassNumber() override;

	TYPE_SIGNAL GetSignalPointer() override;

	TYPE_HANDLER GetHandlerPointer() override;
};

#endif // SECOND_H