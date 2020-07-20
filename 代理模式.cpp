/*
代码参考自：传播智客轻松搞定设计模式
代理模式：父类指针作为函数参数，将创建的子类对象作为实参传递
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

//购物基类
class Shopping {
public:
	Shopping() {}
	~Shopping() {}
	virtual void buy(Item &item) = 0;
};

//韩国购物
class KoreaShopping :public Shopping {
public:
	KoreaShopping() {}
	~KoreaShopping() {}
	virtual void buy(Item &item)
	{
		cout << "去韩国进行了购物，买了" << item.kind << endl;
	}
};

//美国购物
class USAShopping :public Shopping {
public:
	USAShopping() {}
	~USAShopping() {}
	virtual void buy(Item &item)
	{
		cout << "去美国进行了购物，买了" << item.kind << endl;
	}
};

//非洲购物
class AfrikaShopping :public Shopping {
public:
	AfrikaShopping() {}
	~AfrikaShopping() {}
	virtual void buy(Item &item)
	{
		cout << "去非洲进行了购物，买了" << item.kind << endl;
	}
};

//海外代理
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
			cout << "发现伪货["<<item.kind<<"].不能购买" << endl;
		}
	}

	bool distinguish(Item &item)
	{
		cout << "对物品[" << item.kind << "]辨别真伪." << endl;
		return item.fact;
	}

	void check(Item &item)
	{
		cout << "通过海关安检，带回国内" << endl;
	}
private:
	Shopping *shopMode;
};

int main()
{
	Item t1("化妆品",true);
	Item t2("CET4证书", false);
	Item t3("adidas", true);

	Shopping *shopping = NULL;
	OverseasProxy *proxy = NULL;

	//1、去韩国买化妆品
	proxy = new OverseasProxy(new KoreaShopping);
	proxy->buy(t1);
	delete proxy;

	//2、去美国买CET4证书
	proxy = new OverseasProxy(new USAShopping);
	proxy->buy(t2);
	delete proxy;

	//3、去非洲adidas
	proxy = new OverseasProxy(new AfrikaShopping);
	proxy->buy(t3);
	delete proxy;

	cin.get();
	return 0;
}