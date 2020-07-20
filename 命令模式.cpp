/*
����ο��ԣ������ǿ����ɸ㶨���ģʽ
*/
#include <iostream>

using namespace std;

class Doctor {
public:
	Doctor() {}
	~Doctor() {}
	void treat_eye()
	{
		cout << "ҽ�� ���� �ۿƲ�" << endl;
	}

	void treat_nose()
	{
		cout << "ҽ�� ���� �ǿƲ�" << endl;
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