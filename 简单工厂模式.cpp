#include <iostream>

using namespace std;

class Fruit
{
public:
	Fruit() {};
	~Fruit() {};
	Fruit(string name) 
	{
		this->name = name;
		/*if (name=="apple")
		{
		}
		else if (name=="banana")
		{
		}
		else if (name=="pear")
		{
		}*/
	}
	void getName()
	{
		if (name == "apple")
		{
			cout << "我是苹果" << endl;
		}
		else if (name == "banana")
		{
			cout << "我是香蕉" << endl;
		}
		else if (name == "pear")
		{
			cout << "我是鸭梨" << endl;
		}
	}
private:
	int kind;
	string name;
};

int main()
{
	Fruit apple = Fruit("apple");
	Fruit banana = Fruit("banana");
	Fruit pear = Fruit("pear");

	apple.getName();
	banana.getName();
	pear.getName();

	cin.get();

	return 0;
}