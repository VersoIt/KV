#pragma once
#ifndef OUTPUT_H
#define OUTPUT_H

#include "Base.h"

class Output : public Base
{
public:
	Output();

	Output(Base* parent, const std::string& name);

	void Handle(std::string message);

	void Signal(std::string& message);

	virtual int GetClassNumber() override;

	TYPE_SIGNAL GetSignalPointer() override;

	TYPE_HANDLER GetHandlerPointer() override;

	bool IsNumber(std::string str);
};

#endif // OUTPUT_H