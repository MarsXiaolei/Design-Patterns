#include <iostream>

using namespace  std;

class SubSystem1 {
public:
	SubSystem1() {}
	~SubSystem1() {}
	void Method1()
	{
		cout << "子系统方法一" << endl;
	}
};

class SubSystem2 {
public:
	SubSystem2() {}
	~SubSystem2() {}
	void Method2()
	{
		cout << "子系统方法二" << endl;
	}
};

class SubSystem3 {
public:
	SubSystem3() {}
	~SubSystem3() {}
	void Method3()
	{
		cout << "子系统方法三" << endl;
	}
};

class SubSystem4 {
public:
	SubSystem4() {}
	~SubSystem4() {}
	void Method4()
	{
		cout << "子系统方法四" << endl;
	}
};

class Facade {
public:
	Facade() 
	{
		one = new SubSystem1;
		two = new SubSystem2;
		three = new SubSystem3;
		four = new SubSystem4;
	}

	~Facade() 
	{
		delete one;
		delete two;
		delete three;
		delete four;
	}

	void MethodA()
	{
		cout << "" << endl;
		one->Method1();
		two->Method2();
	}

	void MethodB()
	{
		cout << "" << endl;
		three->Method3();
		four->Method4();
	}

private:
	SubSystem1 *one;
	SubSystem2 *two;
	SubSystem3 *three;
	SubSystem4 *four;
};

int main()
{
	Facade facade;
	facade.MethodA();
	facade.MethodB();
	cin.get();
	return 0;
}