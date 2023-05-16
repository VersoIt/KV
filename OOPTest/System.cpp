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

#define CLEAR "C"
#define PLUS "+"
#define MINUS "-"
#define DIVIDE "/"
#define PRODUCT "*"
#define SHIFT "%"

#define READY_STATE 1

System::System(Base* parent, const std::string& name) : Base(parent, name)
{
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

	std::string firstOperand;
	std::string lastOperand;

	std::string command;

	while (true)
	{

		EmitSignal(reader->GetSignalPointer(), command);
		if (command == "Off")
			return;

		EmitSignal(arithmetic->GetSignalPointer(), command);
	}

}

int System::Execute()
{
	return 0; 
}