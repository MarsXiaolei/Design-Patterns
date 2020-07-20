#include <iostream>

using namespace std;

//水果类
class Fruit {
public:
	Fruit() {};
	~Fruit() {};
	virtual void getName() = 0;
};

//抽象工厂类
class AbstractFactory {
public:
	AbstractFactory() {};
	~AbstractFactory() {};
	virtual Fruit* createFruit() = 0;
};

//苹果类
class Apple :public Fruit {
public:
	Apple() {};
	~Apple() {};
	virtual void getName()
	{
		cout << "我是苹果" << endl;
	}
};

//香蕉类
class Banana :public Fruit {
public:
	Banana() {};
	~Banana() {};
	virtual void getName()
	{
		cout << "我是香蕉" << endl;
	}
};

//苹果工厂
class AppleFactory :public AbstractFactory {
public:
	AppleFactory() {};
	~AppleFactory() {};
	//父类指针作为返回值，返回子类对象
	virtual Fruit* createFruit()
	{
		return new Apple;
	}
};

//香蕉工厂
class BananaFactory :public AbstractFactory {
public:
	BananaFactory() {};
	~BananaFactory() {};
	virtual Fruit* createFruit()
	{
		return new Banana;
	}
};

//梨
class Pear :public Fruit {
public:
	Pear() {};
	~Pear() {};
	virtual void getName()
	{
		cout << "我是鸭梨" << endl;
	}
};

//梨工厂
class PearFactory:public AbstractFactory {
public:
	PearFactory() {};
	~PearFactory() {};
	virtual Fruit* createFruit()
	{
		return new Pear;
	}
};

int main()
{
	AbstractFactory* abFactory = NULL;
	Fruit* fruit = NULL;

	abFactory = new AppleFactory;
	fruit = abFactory->createFruit();
	fruit->getName();
	delete abFactory;
	delete fruit;

	abFactory = new BananaFactory;
	fruit = abFactory->createFruit();
	fruit->getName();
	delete abFactory;
	delete fruit;

	abFactory = new PearFactory;
	fruit = abFactory->createFruit();
	fruit->getName();
	delete abFactory;
	delete fruit;

	cin.get();
	return 0;
}