#include "Fifth.h"

#include <iostream>

Fifth::Fifth() : Base(nullptr, "")
{
}

Fifth::Fifth(Base* parent, const std::string& name = "UNKNOWN") : Base(parent, name) {}