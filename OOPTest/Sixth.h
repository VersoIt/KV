#pragma once
#ifndef SIXTH_H
#define SIXTH_H

#include "Base.h"

class Sixth : public Base
{
public:
	Sixth();

	Sixth(Base* parent, const std::string& name);

	void Handle(std::string message);

	void Signal(std::string& message);

	virtual int GetClassNumber() override;

	TYPE_SIGNAL GetSignalPointer() override;

	TYPE_HANDLER GetHandlerPointer() override;
};

#endif // SIXTH_H