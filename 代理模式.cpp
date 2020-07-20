/*
����ο��ԣ������ǿ����ɸ㶨���ģʽ
����ģʽ������ָ����Ϊ���������������������������Ϊʵ�δ���
*/
#include <iostream>
#include <string>

using namespace std;

class Item {
public:
	Item(string kind,bool fact)
	{
		this->kind = kind;
		this->fact = fact;
	}
	~Item() {};
	string kind;
	bool fact;
};

//�������
class Shopping {
public:
	Shopping() {}
	~Shopping() {}
	virtual void buy(Item &item) = 0;
};

//��������
class KoreaShopping :public Shopping {
public:
	KoreaShopping() {}
	~KoreaShopping() {}
	virtual void buy(Item &item)
	{
		cout << "ȥ���������˹������" << item.kind << endl;
	}
};

//��������
class USAShopping :public Shopping {
public:
	USAShopping() {}
	~USAShopping() {}
	virtual void buy(Item &item)
	{
		cout << "ȥ���������˹������" << item.kind << endl;
	}
};

//���޹���
class AfrikaShopping :public Shopping {
public:
	AfrikaShopping() {}
	~AfrikaShopping() {}
	virtual void buy(Item &item)
	{
		cout << "ȥ���޽����˹������" << item.kind << endl;
	}
};

//�������
class OverseasProxy :public Shopping {
public:
	OverseasProxy(Shopping *shopping) 
	{
		this->shopMode = shopping;
	}
	~OverseasProxy() 
	{
		delete this->shopMode;
	}

	virtual void buy(Item &item)
	{
		if (distinguish(item)==true)
		{
			this->shopMode->buy(item);
			check(item);
		}
		else
		{
			cout << "����α��["<<item.kind<<"].���ܹ���" << endl;
		}
	}

	bool distinguish(Item &item)
	{
		cout << "����Ʒ[" << item.kind << "]�����α." << endl;
		return item.fact;
	}

	void check(Item &item)
	{
		cout << "ͨ�����ذ��죬���ع���" << endl;
	}
private:
	Shopping *shopMode;
};

int main()
{
	Item t1("��ױƷ",true);
	Item t2("CET4֤��", false);
	Item t3("adidas", true);

	Shopping *shopping = NULL;
	OverseasProxy *proxy = NULL;

	//1��ȥ������ױƷ
	proxy = new OverseasProxy(new KoreaShopping);
	proxy->buy(t1);
	delete proxy;

	//2��ȥ������CET4֤��
	proxy = new OverseasProxy(new USAShopping);
	proxy->buy(t2);
	delete proxy;

	//3��ȥ����adidas
	proxy = new OverseasProxy(new AfrikaShopping);
	proxy->buy(t3);
	delete proxy;

	cin.get();
	return 0;
}