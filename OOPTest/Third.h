#pragma once
#ifndef THIRD_H
#define THIRD_H

#include "Base.h"

class Third : public Base
{
public:

	Third();

	Third(Base* parent, const std::string& name);

	void Handle(std::string message);

	void Signal(std::string& message);

	virtual int GetClassNumber() override;

	TYPE_SIGNAL GetSignalPointer() override;

	TYPE_HANDLER GetHandlerPointer() override;
};

#endif // THIRD_H