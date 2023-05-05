#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <vector>

#define SIGNAL_D(signal_f) (TYPE_SIGNAL) (&signal_f)
#define HANDLER_D(handler_f) (TYPE_HANDLER) (&handler_f)

class Base;

typedef void (Base ::* TYPE_SIGNAL) (std::string&);
typedef void (Base ::* TYPE_HANDLER) (std::string);

struct Connection
{
	TYPE_SIGNAL m_signal;   // ”казатель на метод сигнала
	Base* m_target;	        // ”казатель на целевой объект
	TYPE_HANDLER m_handler; // ”казатель на метод обработчика
};

class Base 
{
protected:

	Base* m_parent;
	Base* m_current;

	std::string m_name;

	std::vector<Base*> m_childs;

	std::vector<Connection*> connections;

	int m_readiness;

public:
	
	Base(Base* parent, const std::string& name = "UNKNOWN");
	
	bool SetName(const std::string& name);
	
	Base* GetParent();
	
	void Print(int ident = 0);

	std::string GetName();
	
	Base* FindChildByName(const std::string& name);

	std::vector<Base*>& GetChilds();
	
	void AddChild(Base* child);

	int CountOf(const std::string& name);

	bool OverrideParent(Base* newParent);

	void Remove(const std::string& childName);

	void SetCurrent(Base* current);

	Base* GetCurrent();

	Base* FindByCoordinate(const std::string& coordinate);

	// new methods

	void CreateConnection(TYPE_SIGNAL signal, Base* target, TYPE_HANDLER handler);

	void BreakConnection(TYPE_SIGNAL singnal, Base* target, TYPE_HANDLER handler);

	void EmitSignal(TYPE_SIGNAL signal, std::string& message);

	std::string getAbsolutePath();

	void Signal(std::string& message);

	void Handle(std::string message);

	void SetState(int state);

	virtual int GetClassNumber();

	virtual TYPE_SIGNAL GetSignalPointer();

	virtual TYPE_HANDLER GetHandlerPointer();

	~Base();

};

#endif // BASE_H