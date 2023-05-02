#ifndef APPNODE_H
#define APPNODE_H
#include "Base.h"

class AppNode : public Base
{
private:

	bool m_isApplied;

public:


	AppNode(Base* parent, const std::string& name = "UNKNOWN");
	  
	void Build();
	
	int Execute();
};

#endif