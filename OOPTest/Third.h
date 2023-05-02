#pragma once
#ifndef THIRD_H
#define THIRD_H

#include "Base.h"

class Third : public Base
{
public:
	Third();

	Third(Base* parent, const std::string& name);
};

#endif // THIRD_H