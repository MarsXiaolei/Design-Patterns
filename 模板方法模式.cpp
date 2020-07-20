/*
����ο��ԣ������ǿ����ɸ㶨���ģʽ

*/
#include <iostream>

using namespace std;

class Beverage {
public:
	Beverage() {}
	~Beverage() {}

	void BoilWater()
	{
		cout << "�տ�ˮ" << endl;
	}

	virtual void Brew() = 0; //���麯����������д

	void PourInCup()
	{
		cout << "���뱭��" << endl;
	}

	virtual void AddCondiments() = 0; //���麯����������д

	virtual bool CustomWantsCondiments()
	{
		return true;
	}

	void PrepareBeverage()
	{
		BoilWater();
		Brew();
		PourInCup();

		if (CustomWantsCondiments())
		{
			AddCondiments();
		}
	}
};

class Coffee :public Beverage {
public:
	Coffee() {}
	~Coffee() {}
	virtual void Brew()
	{
		cout << "���ݿ��ȶ�" << endl;
	}

	virtual void AddCondiments()
	{
		cout << "����Ǻ�ţ��" << endl;
	}
};

class Tea :public Beverage {
public:
	Tea() {}
	~Tea() {}
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}

	virtual void AddCondiments()
	{
		cout << "�������" << endl;
	}
};

int main()
{
	Beverage *pTea = new Tea;
	pTea->PrepareBeverage();
	delete pTea;

	cout << "------------------------" << endl;

	Beverage *pCoffee = new Coffee;
	pCoffee->PrepareBeverage();
	delete pCoffee;

	cin.get();
	return 0;
}