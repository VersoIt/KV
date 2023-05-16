#include <iostream>
#include "Base.h"

#define IDENTS_COUNT 4

Base::Base(Base* parent, const std::string& name) : m_parent{ parent }, m_name{ name }, m_current{ this }, m_readiness{ 1 }
{
	if (parent != nullptr)
		m_parent->AddChild(this);
}

void Base::AddChild(Base* child) 
{
	m_childs.push_back(child); 
}

std::string Base::GetName() 
{ 
	return m_name; 
}

bool Base::SetName(const std::string& name) 
{ 
	for (auto child : m_childs) 
	{ 
		if (FindChildByName(name) != nullptr)
			return false; 
	}
	
	m_name = name; 
	return true; 
}

std::vector<Base*>& Base::GetChilds() {
	return m_childs;
}

Base* Base::FindChildByName(const std::string& name) 
{ 
	for (auto element : m_childs) 
	{ 
		if (element->GetName() == name)
			return element;
	}

	for (auto element : m_childs)
	{
		Base* subElement = element->FindChildByName(name);
		if (subElement)
			return subElement;
	}

	return nullptr; 
}

void Base::Print(int ident) 
{ 
	++ident;

	for (auto child : m_childs)
	{
		std::cout << std::endl << std::string(ident * IDENTS_COUNT, ' ') << child->m_name;
		child->Print(ident);
	}
}

Base* Base::GetParent() 
{ 
	return m_parent; 
}

bool Base::OverrideParent(Base* newParent)
{
	if (m_current->m_parent == nullptr)
		return false;

	if (m_current->m_name == newParent->m_name)
		return false;

	for (auto newParentChild : newParent->m_childs)
	{
		if (newParentChild->m_name == m_current->m_name)
			return false;
	}

	Base* parentOfNewParent = newParent->m_parent;
	while (parentOfNewParent != nullptr)
	{
		if (parentOfNewParent == m_current)
			return false;

		parentOfNewParent = parentOfNewParent->m_parent;
	}

	// Удаление ссылки у старого головного объекта на текущий объект
	std::vector<Base*>* parentBranch = &m_current->m_parent->m_childs;
	for (size_t idxNum = 0; idxNum < parentBranch->size(); ++idxNum)
	{
		if ((*parentBranch)[idxNum]->GetName() == m_current->GetName())
		{
			parentBranch->erase(idxNum + parentBranch->begin());
			break;
		}
	}

	// newParent->m_parent = m_current->m_parent;
	m_current->m_parent = newParent;
	newParent->AddChild(m_current);

	return true;
}

void Base::Remove(const std::string& childName)
{
	for (size_t idxNum = 0; idxNum < m_childs.size(); ++idxNum)
	{
		if (childName == m_childs[idxNum]->m_name)
		{
			m_childs[idxNum]->m_parent = nullptr;

			delete m_childs[idxNum];
			m_childs.erase(m_childs.begin() + idxNum);

			return;
		}
	}
}

void Base::SetCurrent(Base* current)
{
	m_current = current;
}

Base* Base::GetCurrent()
{
	return m_current;
}

Base* Base::FindByCoordinate(const std::string& pattern)
{
	if (pattern == "/")
	{
		if (m_parent == nullptr)
			return this;

		Base* root = m_parent;
		while (root->m_parent != nullptr)
			root = root->m_parent;

		return root;
	}
	else if (pattern.substr(0, 2) == "//")
	{
		std::string nameToSearch = pattern.substr(2, pattern.size());

		Base* root;

		if (m_parent == nullptr)
			root = this;
		else
		{
			root = m_parent;
			while (root->m_parent != nullptr)
				root = root->m_parent;
		}

		if (root->CountOf(nameToSearch) != 1)
			return nullptr;

		if (m_name == nameToSearch)
			return this;

		return FindChildByName(nameToSearch);
	}
	else if (pattern == ".")
	{
		return m_current;
	}
	else if (pattern[0] == '.')
	{
		std::string nameToSearch = pattern.substr(1, pattern.size());
		int a = m_current->CountOf(nameToSearch);
		if (m_current->CountOf(nameToSearch) != 1)
			return nullptr;

		//if (m_name == nameToSearch)
		//	return this;

		return m_current->FindChildByName(nameToSearch);
	}
	else if (pattern.empty())
		return nullptr;
	else
	{
		std::string command = pattern;
		Base* target = nullptr;

		if (pattern[0] == '/')
		{
			command = command.substr(1, command.size());
			if (m_parent == nullptr)
				target = this;
			else
			{
				target = m_parent;
				while (target->m_parent != nullptr)
					target = target->m_parent;
			}
		}
		else
			target = m_current;

		while (command.size() != 0)
		{
			if (target == nullptr)
				return nullptr;

			int lastCommandIndex = command.find('/');
			lastCommandIndex = lastCommandIndex == -1 ? command.size() : lastCommandIndex;
			
			std::string path = command.substr(0, lastCommandIndex);
			target = target->FindChildByName(path);

			command = lastCommandIndex == command.size() ? "" : command.substr(++lastCommandIndex, command.size());
		}

		return target;
	}

	return nullptr;
}

int Base::CountOf(const std::string& name)
{
	int count = 0;
	for (auto child : m_childs)
	{
		if (child->m_name == name)
			++count;

		count += child->CountOf(name);
	}

	return count;
}

void Base::CreateConnection(TYPE_SIGNAL signal, Base* target, TYPE_HANDLER handler)
{
	Connection* connection;

	for (size_t i = 0; i < connections.size(); ++i)
	{
		if (connections[i]->m_signal == signal &&
			connections[i]->m_target == target &&
			connections[i]->m_handler == handler)
		{
			return;
		}
	}

	connection = new Connection();

	connection->m_signal = signal;
	connection->m_target = target;
	connection->m_handler = handler;

	connections.push_back(connection);
}

void Base::BreakConnection(TYPE_SIGNAL signal, Base* target, TYPE_HANDLER handler)
{
	for (size_t i = 0; i < connections.size(); ++i)
	{
		if (connections[i]->m_signal == signal)
		{
			delete connections[i];
			this->connections.erase(connections.begin() + i);
			return;
		}
	}
}

void Base::EmitSignal(TYPE_SIGNAL signal, std::string& message)
{

	if (m_readiness == 0)
		return;
	
	TYPE_SIGNAL sign;
	Base* object;

	for (size_t i = 0; i < connections.size(); ++i)
	{
		if (connections[i]->m_signal == signal)
		{
			sign = connections[i]->m_signal;
			object = connections[i]->m_target;

			if (object->m_readiness == 0)
				return;

			(object->*sign) (message);
		}
	}
}

void Base::Handle(std::string message)
{
}

std::string Base::getAbsolutePath()
{
	std::string path = "";
	Base* target = this;

	if (target->m_parent == nullptr)
		return "/";

	while (target->m_parent != nullptr) {
		path = "/" + target->GetName() + path;
		target = target->m_parent;
	}
	return path;
}

void Base::Signal(std::string& message)
{
}

void Base::SetState(int state)
{
	if (m_parent != nullptr && m_parent->m_readiness == 0)
	{
		m_readiness = 0;
		for (auto child : m_childs)
			child->SetState(0);

		return;
	}

	if (state == 0)
	{
		for (auto child : m_childs)
			child->SetState(0);
	}

	m_readiness = state;
}

int Base::GetClassNumber() 
{
	return 1;
}

Base::~Base() 
{
	for (auto element : m_childs)
		delete element; 
}

TYPE_SIGNAL Base::GetSignalPointer()
{
	return nullptr;
}

TYPE_HANDLER Base::GetHandlerPointer()
{
	return nullptr;
}