#include <iostream>
#include <string>

using namespace std;

class Phone {
public:
	Phone() {}
	~Phone() {}
	virtual void show() = 0;
};

class iPhone :public Phone {
public:
	iPhone(string kind) 
	{
		this->kind = kind;
	}
	virtual void show()
	{
		cout << "秀出了 iPhone-" << kind << endl;
	}
	~iPhone() {}
private:
	string kind;
};

class Mi :public Phone {
public:
	Mi(string kind)
	{
		this->kind = kind;
	}
	virtual void show()
	{
		cout << "秀出了 Mi-" << kind << endl;
	}
	~Mi() {}
private:
	string kind;
};

class DecoratorPhone :public Phone {
public:
	DecoratorPhone() {}
	DecoratorPhone(Phone *phone)
	{
		this->phone = phone;
	}
	virtual void show()
	{
		this->phone->show();
	}
	~DecoratorPhone() {}
private:
	Phone *phone;
};

class DecoratorPhoneMo :public DecoratorPhone {
public:
	DecoratorPhoneMo(Phone *phone) 
	{
		this->phone = phone;
	}
	virtual void show()
	{
		this->phone->show();
		AddMo();
	}
	void AddMo()
	{
		cout << "装饰：手机贴膜" << endl;
	}
	~DecoratorPhoneMo() {}
private:
	Phone *phone;
};

class DecoratorPhoneTao :public DecoratorPhone {
public:
	DecoratorPhoneTao(Phone *phone)
	{
		this->phone = phone;
	}
	~DecoratorPhoneTao() {}
	virtual void show()
	{
		this->phone->show();
		AddTao();
	}

	void AddTao()
	{
		cout << "装饰：手机外套" << endl;
	}
private:
	Phone *phone;
};

int main()
{
	Phone *phone = NULL;
	DecoratorPhone *hasMophone = NULL;
	DecoratorPhone *hasTaophone = NULL;
	DecoratorPhone *hasMoTaophone = NULL;
	
	phone = new iPhone("");
	hasMophone = new DecoratorPhoneMo(phone);
	hasTaophone= new DecoratorPhoneTao(phone);

	hasMophone->show();
	hasTaophone->show();

	hasMoTaophone = new DecoratorPhoneMo(hasTaophone);
	hasMoTaophone->show();

	delete hasTaophone;
	delete hasMophone;
	delete hasMoTaophone;
	delete phone;

	phone = new Mi("");
	hasMophone = new DecoratorPhoneMo(phone);
	hasTaophone = new DecoratorPhoneTao(phone);
	hasMophone->show();
	hasTaophone->show();

	hasMoTaophone = new DecoratorPhoneTao(hasMophone);
	hasMoTaophone->show();

	delete hasTaophone;
	delete hasMophone;
	delete hasMoTaophone;
	delete phone;
	
	cin.get();
	return 0;
}