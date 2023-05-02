#include "AppNode.h"

int main()
{
	AppNode appNode(nullptr);
	appNode.Build();
	int code = appNode.Execute();
	return code;
}