#pragma once
#ifndef SECOND_H
#define SECOND_H

#include "Base.h"

class Second : public Base
{

public:
	Second();

	Second(Base* parent, const std::string& name);
};

#endif // SECOND_H