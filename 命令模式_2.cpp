/*
代码参考自：传播智客轻松搞定设计模式
*/
#include <iostream>
#include <list>

using namespace std;

class Doctor {
public:
	Doctor() {}
	~Doctor() {}
	void treat_eye()
	{
		cout << "医生 治疗 眼科病" << endl;
	}
	void treat_nose()
	{
		cout << "医生 治疗 鼻科病" << endl;
	}
};

class Command {
public:
	Command(Doctor *doctor) 
	{
		this->doctor = doctor;
	}
	~Command() {}
	virtual void treat() = 0;
protected:
	Doctor *doctor;
};

class CommandTreatEye :public Command {
public:
	CommandTreatEye(Doctor *doctor):Command(doctor) {}
	~CommandTreatEye() {}
	virtual void treat()
	{
		doctor->treat_eye();
	}
};

class CommandTreatNose :public Command {
public:
	CommandTreatNose(Doctor *doctor):Command(doctor) {}
	~CommandTreatNose() {}
	virtual void treat()
	{
		doctor->treat_nose();
	}
};

class Nurse {
public:
	Nurse(Command *command) 
	{
		this->command = command;
	}
	~Nurse() {}

	void Notyfy()
	{
		command->treat();
	}
private:
	Command *command;
};

class AdvNurse {
public:
	AdvNurse() 
	{
		cmd_list.clear();
	}
	~AdvNurse() {}

	void setCommand(Command *cmd)
	{
		cmd_list.push_back(cmd);
	}

	void Notyfy()
	{
		for (list<Command*>::iterator it = cmd_list.begin(); it != cmd_list.end();it++)
		{
			(*it)->treat();
		}
	}

private:
	list<Command*> cmd_list;
};

int main()
{
	Doctor *doctor = new Doctor;
	Command *command_1 = new CommandTreatEye(doctor);
	Command *command_2 = new CommandTreatNose(doctor);
	AdvNurse *advNurse = new AdvNurse;

	advNurse->setCommand(command_1);
	advNurse->setCommand(command_2);
	advNurse->Notyfy();
	delete advNurse;

	delete command_1;
	delete command_2;
	delete doctor;

	cin.get();
	return 0;
}