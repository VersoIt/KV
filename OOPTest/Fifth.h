#pragma once
#pragma once
#ifndef FIFTH_H
#define FIFTH_H

#include "Base.h"

class Fifth : public Base
{
public:

	Fifth();

	Fifth(Base* parent, const std::string& name);

	void Handle(std::string message);

	void Signal(std::string& message);

	virtual int GetClassNumber() override;

	TYPE_SIGNAL GetSignalPointer() override;

	TYPE_HANDLER GetHandlerPointer() override;
};

#endif // FIFTH_H