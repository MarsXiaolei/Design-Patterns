/*
代码参考自：传播智客轻松搞定设计模式

*/
#include <iostream>

using namespace std;

class Beverage {
public:
	Beverage() {}
	~Beverage() {}

	void BoilWater()
	{
		cout << "烧开水" << endl;
	}

	virtual void Brew() = 0; //纯虚函数，子类重写

	void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}

	virtual void AddCondiments() = 0; //纯虚函数，子类重写

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
		cout << "冲泡咖啡豆" << endl;
	}

	virtual void AddCondiments()
	{
		cout << "添加糖和牛奶" << endl;
	}
};

class Tea :public Beverage {
public:
	Tea() {}
	~Tea() {}
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}

	virtual void AddCondiments()
	{
		cout << "添加柠檬" << endl;
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