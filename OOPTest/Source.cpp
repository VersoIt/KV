#include "System.h"

int main()
{
	System system(nullptr, "");
	system.build_tree_objects();
	system.exec_app();
	int code = system.Execute();
	return code;
}