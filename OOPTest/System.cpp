#include "System.h"
#include <iostream>
#include <string>
#include <sstream>

#include "Reader.h"
#include "Arithmetic.h"
#include "Shift.h"
#include "Clear.h"
#include "Output.h"

#define READER_NAME "read_object"
#define ARITHMETIC_NAME "arithmetic_opearion"
#define SHIFT_NAME "shift_operation"
#define CLEAR_NAME "clear_operation"
#define OUTPUT_NAME "output_object"
#define SYSTEM_NAME "system_object"

#define SHIFT "%"

#define READY_STATE 1

System::System(Base* parent, const std::string& name) : Base(parent, name)
{
}

void GetLastCommandAndOperator(std::string str, std::string& command, std::string& lastOperand)
{
	std::stringstream ss(str);

	std::vector<std::string> words;
	std::string temp;
	while (ss >> temp)
		words.push_back(temp);

	command = words[words.size() - 2];
	lastOperand = words[words.size() - 1];
}

void SplitAllCommand(std::string command, std::string& lastCommand, std::string& lastOperand, int& firstOperand)
{
	std::stringstream ss(command);

	std::vector<std::string> words;
	std::string temp;
	while (ss >> temp)
		words.push_back(temp);

	lastOperand = words[words.size() - 1];
	lastCommand = words[words.size() - 2];
	firstOperand = std::stoi(words[words.size() - 3]);
}

void System::build_tree_objects()
{
	SetName(SYSTEM_NAME);
	reader = new Reader(this, READER_NAME);
	arithmetic = new Arithmetic(this, ARITHMETIC_NAME);
	shift = new Shift(this, SHIFT_NAME);
	clear = new Clear(this, CLEAR_NAME);
	output = new Output(this, OUTPUT_NAME);

	CreateConnection(reader->GetSignalPointer(), reader, reader->GetHandlerPointer());
	CreateConnection(arithmetic->GetSignalPointer(), arithmetic, arithmetic->GetHandlerPointer());
	CreateConnection(shift->GetSignalPointer(), shift, shift->GetHandlerPointer());
	CreateConnection(clear->GetSignalPointer(), clear, clear->GetHandlerPointer());
	CreateConnection(output->GetSignalPointer(), output, output->GetHandlerPointer());
}

void System::exec_app()
{
	for (int idxNum = 0; idxNum < GetChilds().size(); ++idxNum)
		GetChilds()[idxNum]->SetState(READY_STATE);

	std::string command; // 100 + 23 - 1 + 1 + 3
	int lastResult = 0;

	// Проверка на то вводит ли пользователь первое число
	bool isFirst = true;
	while (true)
	{

		EmitSignal(reader->GetSignalPointer(), command);

		if (command == "Off")
			return;

		if (command == "C")
		{
			isFirst = true;
			EmitSignal(clear->GetSignalPointer(), command);
			lastResult = 0;
			continue;
		}

		std::string lastOperand;
		std::string lastCommand;
		// Если предыдущий результат не равен 0, то достаем только последний операнд и знак операции
		if (lastResult != 0 || !isFirst)
		{
			GetLastCommandAndOperator(command, lastCommand, lastOperand);
		}
		else
		{
			// Разделяем комманду на удобные структуры
			SplitAllCommand(command, lastCommand, lastOperand, lastResult);
		}

		std::string commandToSend = std::to_string(lastResult) + " " + lastCommand + " " + lastOperand;
		if (lastCommand == SHIFT_LEFT || lastCommand == SHIFT_RIGHT)
		{
			isFirst = false;
			EmitSignal(shift->GetSignalPointer(), commandToSend);

			if (commandToSend == ARITHMETIC_OVERFLOW)
			{
				isFirst = true;
				EmitSignal(clear->GetSignalPointer(), command);
				lastResult = 0;
			}
			else
			{
				EmitSignal(output->GetSignalPointer(), commandToSend);
				lastResult = std::stoi(commandToSend);
			}
		}
		else
		{
			EmitSignal(arithmetic->GetSignalPointer(), commandToSend);

			if (commandToSend == DIVISION_BY_ZERO || commandToSend == ARITHMETIC_OVERFLOW)
			{
				isFirst = true;
				EmitSignal(clear->GetSignalPointer(), command);
				lastResult = 0;
			}
			else
			{
				isFirst = false;
				lastResult = std::stoi(commandToSend);
				EmitSignal(output->GetSignalPointer(), commandToSend);
			}
		}
	}

}

int System::Execute()
{
	return 0; 
}