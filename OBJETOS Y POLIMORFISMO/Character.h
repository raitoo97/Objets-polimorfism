#pragma once
#include <iostream>
using namespace std;

class Enemigo;



class Character{
protected:
	int hp = 0;
	int damage = 0;
	int oro = 0;
	string name = "";
	string clase = "";
public:
	int gethp() { return hp; }
	int getdamge() { return damage; }
	int getoro() { return oro; }
	string getname() { return name; }
	string getclase() { return clase; }
	void setclase(string claseinit) { clase = claseinit; }
	void sethp(int hpinit) { hp = hpinit; }
	void setdamge(int damageinit) { damage = damageinit; }
	void setoro(int oroinit) { oro = oroinit; }
	void setname(string nameinit) { name = nameinit;}
	virtual void recibirdaño(int damagehp) { hp -= damagehp; }
	virtual void atacar(Enemigo* objetivo) {};
};

