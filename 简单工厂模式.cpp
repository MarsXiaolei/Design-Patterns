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
			cout << "����ƻ��" << endl;
		}
		else if (name == "banana")
		{
			cout << "�����㽶" << endl;
		}
		else if (name == "pear")
		{
			cout << "����Ѽ��" << endl;
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