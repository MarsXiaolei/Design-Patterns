#include <iostream>

using namespace std;

//ˮ����
class Fruit {
public:
	Fruit() {};
	~Fruit() {};
	virtual void getName() = 0;
};

//���󹤳���
class AbstractFactory {
public:
	AbstractFactory() {};
	~AbstractFactory() {};
	virtual Fruit* createFruit() = 0;
};

//ƻ����
class Apple :public Fruit {
public:
	Apple() {};
	~Apple() {};
	virtual void getName()
	{
		cout << "����ƻ��" << endl;
	}
};

//�㽶��
class Banana :public Fruit {
public:
	Banana() {};
	~Banana() {};
	virtual void getName()
	{
		cout << "�����㽶" << endl;
	}
};

//ƻ������
class AppleFactory :public AbstractFactory {
public:
	AppleFactory() {};
	~AppleFactory() {};
	//����ָ����Ϊ����ֵ�������������
	virtual Fruit* createFruit()
	{
		return new Apple;
	}
};

//�㽶����
class BananaFactory :public AbstractFactory {
public:
	BananaFactory() {};
	~BananaFactory() {};
	virtual Fruit* createFruit()
	{
		return new Banana;
	}
};

//��
class Pear :public Fruit {
public:
	Pear() {};
	~Pear() {};
	virtual void getName()
	{
		cout << "����Ѽ��" << endl;
	}
};

//�湤��
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