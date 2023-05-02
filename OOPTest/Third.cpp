#include "Third.h"

#include <iostream>

Third::Third() : Base(nullptr, "")
{
}

Third::Third(Base* parent, const std::string& name = "UNKNOWN") : Base(parent, name) {}