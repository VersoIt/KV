#pragma once
#ifndef SIXTH_H
#define SIXTH_H

#include "Base.h"

class Sixth : public Base
{
public:
	Sixth();

	Sixth(Base* parent, const std::string& name);
};

#endif // SIXTH_H