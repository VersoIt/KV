#include "AppNode.h"
#include <iostream>

#include "Second.h"
#include "Third.h"
#include "Fourth.h"
#include "Fifth.h"
#include "Sixth.h"

#define EMIT "EMIT"
#define SET_CONNECT "SET_CONNECT"
#define DELETE_CONNECT "DELETE_CONNECT"
#define SET_CONDITION "SET_CONDITION"
#define END "END"

AppNode::AppNode(Base* parent, const std::string& name) : Base(parent, name), m_isApplied{ true }
{
}

void AppNode::Build() {

	std::cin >> m_name;

	std::string path;
	std::string elementToCreateName;

	int classCode;

	while(true)
	{
		std::cin >> path;

		if (path == "endtree")
			break;

		std::cin >> elementToCreateName;
		std::cin >> classCode;

		Base* parent = FindByCoordinate(path);
		Base* elementToCreate = nullptr;

		if (parent == nullptr)
		{
			m_isApplied = false;
			break;
		}
		else
			m_isApplied = true;


		bool isUnique = true;
		for (auto child : parent->GetChilds())
		{
			if (child->GetName() == elementToCreateName)
				isUnique = false;
		}

		if (!isUnique)
			continue;

		switch (classCode)
		{
		case 2:
			elementToCreate = new Second(parent, elementToCreateName);
			break;
		case 3:
			elementToCreate = new Third(parent, elementToCreateName);
			break;
			case 4:
			elementToCreate = new Fourth(parent, elementToCreateName);
			break;
		case 5:
			elementToCreate = new Fifth(parent, elementToCreateName);
			break;
		case 6:
			elementToCreate = new Sixth(parent, elementToCreateName);
			break;
		}

	}

	std::cout << "Object tree" << std::endl;
	std::cout << m_name;

	Print();

	std::cout << std::endl;

	if (!m_isApplied)
	{
		std::cout << "The head object " << path << " is not found" << std::endl;
	}
	else
	{
		while (true)
		{
			std::string command;

			std::cin >> command;

			if (command == END)
				break;

			if (command == EMIT)
			{
				std::string objectCoordinate;
				std::string message;

				std::cin >> objectCoordinate;
				std::cin >> message;

				Base* object = FindByCoordinate(objectCoordinate);

			}
		}
	}
}

int AppNode::Execute() 
{
	if (m_isApplied)
	{

	}

	return 0; 
}