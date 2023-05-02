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
};

#endif // FOURTH_H