#include "Second.h"

#include <iostream>

Second::Second() : Base(nullptr, "")
{
}

Second::Second(Base* parent, const std::string& name = "UNKNOWN") : Base(parent, name) {}