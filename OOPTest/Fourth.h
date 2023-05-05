#pragma once
#pragma once
#ifndef FOURTH_H
#define FOURTH_H

#include "Base.h"

class Fourth : public Base
{
public:

	Fourth();

	Fourth(Base* parent, const std::string& name);

	void Handle(std::string message);

	void Signal(std::string& message);

	virtual int GetClassNumber() override;

	TYPE_SIGNAL GetSignalPointer() override;

	TYPE_HANDLER GetHandlerPointer() override;
};

#endif // FOURTH_H