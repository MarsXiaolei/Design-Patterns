#include <iostream>

using namespace std;

class Singelton {
public:
	static Singelton* getInstance()
	{
		if (instance==NULL)
		{
			instance = new Singelton;
		}
		m_count++;
		return instance;
	}

	int getCount()
	{
		return m_count;
	}
private:
	Singelton()
	{
		instance = NULL;
		m_count = 0;
		cout << "构造函数 singelton() 执行" << endl;
	}
	~Singelton() {};
	static Singelton *instance;
	static int m_count;
};

Singelton* Singelton::instance = NULL;
int Singelton::m_count = 0;

class Singelton2 {
public:
	static Singelton2* getInstance()
	{
		m_count++;
		return instance;
	}
	int getCount()
	{
		return m_count;
	}

private:
	Singelton2()
	{
		instance = NULL;
		m_count = 0;
	}
	~Singelton2() {};
	static Singelton2* instance;
	static int m_count;
};

Singelton2* Singelton2::instance = NULL;
int Singelton2::m_count = 0;

int main()
{
	Singelton *singer = Singelton::getInstance();
	cout << singer->getCount() << endl;
	Singelton *singer2 = Singelton::getInstance();
	cout << singer2->getCount() << endl;
	if (singer==singer2)
	{
		cout << "二者是同一个实例" << endl;
	}
	else
	{
		cout << "二者不是同一个实例" << endl;
	}

	cout << "--------------以下是饿汉式---------------" << endl;

	Singelton2 *singer3 = Singelton2::getInstance();
	cout << singer3->getCount() << endl;
	Singelton2 *singer4 = Singelton2::getInstance();
	cout << singer4->getCount() << endl;

	if (singer3==singer4)
	{
		cout << "二者是同一个实例" << endl;
	}
	else
	{
		cout << "二者不是同一个实例" << endl;
	}
	cin.get();
	return 0;
}