#include "Sixth.h"

#include <iostream>

Sixth::Sixth() : Base(nullptr, "")
{
}

Sixth::Sixth(Base* parent, const std::string& name = "UNKNOWN") : Base(parent, name) {}