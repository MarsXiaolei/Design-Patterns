#include <iostream>

using namespace std;

class AbstractApple {
public:
	AbstractApple() {};
	~AbstractApple() {};
	virtual void getName() = 0;
};

class AbstractBanana {
public:
	AbstractBanana() {};
	~AbstractBanana() {};
	virtual void getName() = 0;
};

class ChinaApple :public AbstractApple {
public:
	ChinaApple() {};
	~ChinaApple() {};
	virtual void getName() 
	{
		cout << "中国苹果" << endl;
	}
};

class USAApple :public AbstractApple {
public:
	USAApple() {};
	~USAApple() {};
	virtual void getName()
	{
		cout << "美国苹果" << endl;
	}
};

class ChinaBanana :public AbstractBanana {
public:
	ChinaBanana() {};
	~ChinaBanana() {};
	virtual void getName()
	{
		cout << "中国香蕉" << endl;
	}
};

class USABanana :public AbstractBanana {
public:
	USABanana() {};
	~USABanana() {};
	virtual void getName()
	{
		cout << "美国香蕉" << endl;
	}
};

class AbstractFactory {
public:
	AbstractFactory() {};
	~AbstractFactory() {};
	virtual AbstractApple* createApple() = 0;
	virtual AbstractBanana* createBanana() = 0;
};

class ChinaFactory :public AbstractFactory {
public:
	ChinaFactory() {};
	~ChinaFactory() {};
	virtual AbstractApple* createApple()
	{
		return new ChinaApple;
	}

	virtual AbstractBanana* createBanana()
	{
		return new ChinaBanana;
	}
};

class USAFactory :public AbstractFactory {
public:
	USAFactory() {};
	~USAFactory() {};
	virtual AbstractApple* createApple()
	{
		return new USAApple;
	}

	virtual AbstractBanana* createBanana()
	{
		return new USABanana;
	}
};

int main()
{
	AbstractApple *apple = NULL;
	AbstractBanana *banana = NULL;
	AbstractFactory *factory = NULL;

	factory = new ChinaFactory;
	apple = factory->createApple();
	banana = factory->createBanana();
	apple->getName();
	banana->getName();

	delete apple;
	delete banana;
	delete factory;

	cin.get();
	return 0;
}