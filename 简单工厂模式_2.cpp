#include <iostream>

using namespace std;

class Fruit {
public:
	Fruit() {};
	~Fruit() {};
	virtual void getName() = 0;
};

class Apple :public Fruit {
public:
	Apple() {};
	~Apple() {};
	virtual void getName()
	{
		cout << "我是苹果" << endl;
	}
};

class Banana :public Fruit {
public:
	Banana() {};
	~Banana() {};
	virtual void getName()
	{
		cout << "我是香蕉" << endl;
	}
};

class Pear:public Fruit {
public:
	Pear() {};
	~Pear() {};
	virtual void getName()
	{
		cout << "我是鸭梨" << endl;
	}
};

//利用了多态特性，父类指针指向子类对象
class Factory {
public:
	Factory() {};
	~Factory() {};
	Fruit* createFruit(string name)
	{
		if (name == "apple")
		{
			return new Apple;
		}
		else if (name == "banana")
		{
			return new Banana;
		}
		else if (name == "pear")
		{
			return new Pear;
		}
	}
};

int main()
{
	Factory* factory = new Factory;
	Fruit* fruit = NULL;
	fruit = factory->createFruit("apple");
	fruit->getName();
	delete fruit;
	fruit = NULL;

	fruit = factory->createFruit("banana");
	fruit->getName();
	delete fruit;
	fruit = NULL;

	fruit = factory->createFruit("pear");
	fruit->getName();
	delete fruit;
	fruit = NULL;

	cin.get();
	return 0;
}