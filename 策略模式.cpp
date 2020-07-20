#include <iostream>

using namespace std;

class WeaponStrategy {
public:
	WeaponStrategy() {}
	~WeaponStrategy() {}
	virtual void useWeapon() = 0;
};

class AK47 :public WeaponStrategy {
public:
	AK47() {}
	~AK47() {}
	virtual void useWeapon()
	{
		cout << "使用AK47射击" << endl;
	}
};

class Knife :public WeaponStrategy {
public:
	Knife() {}
	~Knife() {}
	virtual void useWeapon()
	{
		cout << "使用匕首击杀" << endl;
	}
};

class Character {
public:
	Character() {}
	~Character() {}

	void setWeapon(WeaponStrategy *strategy)
	{
		wStrategy = strategy;
	}

	void fight()
	{
		wStrategy->useWeapon();
	}

private:
	WeaponStrategy *wStrategy;
};

class CharacterKnife {
public:
	CharacterKnife() {}
	~CharacterKnife() {}

	void fight()
	{
		knife.useWeapon();
	}

private:
	Knife knife;
};

class CharacterAK47 {
public:
	CharacterAK47() {}
	~CharacterAK47() {}

	void fight()
	{
		ak47.useWeapon();
	}

private:
	AK47 ak47;
};

int main()
{
	WeaponStrategy *strategy = NULL;
	Character *c = new Character;

	strategy = new Knife;
	c->setWeapon(strategy);
	c->fight();
	delete strategy;

	strategy = new AK47;
	c->setWeapon(strategy);
	c->fight();
	delete strategy;
	delete c;

	cin.get();
	return 0;
}