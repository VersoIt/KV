#ifndef SYSTEM_H
#define SYSTEM_H
#include "Base.h"

#include "Reader.h"
#include "Arithmetic.h"
#include "Shift.h"
#include "Clear.h"
#include "Output.h"


class System : public Base
{
private:

	Reader* reader = nullptr;
	Arithmetic* arithmetic = nullptr;
	Shift* shift = nullptr;
	Clear* clear = nullptr;
	Output* output = nullptr;

public:

	System(Base* parent, const std::string& name);
	  
	void build_tree_objects();
	
	int Execute();

	void exec_app();
};

#endif // SYSTEM_H