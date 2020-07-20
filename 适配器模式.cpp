#include <iostream>

using namespace std;

class V5 {
public:
	V5() {}
	~V5() {}
	virtual void useV5() = 0;
};

class V220 {
public:
	V220() {}
	~V220() {}
	virtual void useV220()
	{
		cout << "��220V��ѹ���г��" << endl;
	}
};

//�����
class ChargerAdapter :public V5 {
public:
	ChargerAdapter() {}
	~ChargerAdapter() {}
	virtual void useV5()
	{
		cout << "" << endl;
		m_p220.useV220();
	}
private:
	V220 m_p220;
};

class Phone {
public:
	Phone() 
	{
		v5Adapter = new ChargerAdapter;
	}
	~Phone() 
	{
		if (v5Adapter!=NULL)
		{
			delete v5Adapter;
		}
	}

	void charge()
	{
		cout << "�ֻ����г��" << endl;
		v5Adapter->useV5();
	}
private:
	V5 *v5Adapter;
};

int  main()
{
	Phone iphone;
	iphone.charge();
	cin.get();
	return 0;
}