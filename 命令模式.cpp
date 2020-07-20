/*
代码参考自：传播智客轻松搞定设计模式
*/
#include <iostream>

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

class CommandTreatEye {
public:
	CommandTreatEye(Doctor *doctor) 
	{
		m_doctor = doctor;
	}
	~CommandTreatEye() {}
	void treat()
	{
		m_doctor->treat_eye();
	}
private:
	Doctor *m_doctor;
};

class CommandTreatNose {
public:
	CommandTreatNose(Doctor *doctor) 
	{
		m_doctor = doctor;
	}
	~CommandTreatNose() {}
	void treat()
	{
		m_doctor->treat_nose();
	}
private:
	Doctor *m_doctor;
};

int main()
{
	Doctor *doctor = new Doctor;
	doctor->treat_eye();
	doctor->treat_nose();
	delete doctor;

	cout << "--------------------" << endl;

	Doctor *doctor_1 = new Doctor;
	CommandTreatEye *cmdTreatEye = new CommandTreatEye(doctor_1);
	cmdTreatEye->treat();
	delete cmdTreatEye;

	CommandTreatNose *cmdTreatNose = new CommandTreatNose(doctor_1);
	cmdTreatNose->treat();
	delete cmdTreatNose;
	delete doctor_1;
	
	cin.get();
	return 0;
}