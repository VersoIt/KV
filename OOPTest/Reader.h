#pragma once
#ifndef READER_H
#define READER_H

#include "Base.h"

class Reader : public Base
{

public:

	Reader();

	Reader(Base* parent, const std::string& name);

	void Handle(std::string message);

	void Signal(std::string& message);

	virtual int GetClassNumber() override;

	TYPE_SIGNAL GetSignalPointer() override;

	TYPE_HANDLER GetHandlerPointer() override;
};

#endif // READER_H