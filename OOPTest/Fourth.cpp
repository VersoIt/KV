#include "Fourth.h"

#include <iostream>

Fourth::Fourth() : Base(nullptr, "")
{
}

Fourth::Fourth(Base* parent, const std::string& name = "UNKNOWN") : Base(parent, name) {}