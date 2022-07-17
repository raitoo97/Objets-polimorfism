#pragma once
#include <iostream>
using namespace std;

class Character;

class Enemigo {
protected:
	int hp = 0;
	int damage = 0;
	int oro = 0;
	string name = "";
	bool paralizado = false;
	string clase = "";
public:
	//Getters
	int gethp() { return hp; }
	int getdamage() { return damage; }
	int getoro() { return oro; }
	string getname() { return name; }
	bool getparalizado() { return paralizado; }
	string getclase() { return clase; }
	//setters
	void setclase(string claseinit) { clase = claseinit; }
	void sethp(int hpinit) { hp = hpinit; }
	void setdamage(int damageinit) { damage = damageinit; }
	void setoro(int oroinit) { oro = oroinit; }
	void setname(string nameinit) { name = nameinit; }
	void setparalizado(bool paralizadoinit) { paralizado = paralizadoinit; }
	//Metodo de ataque
	virtual void recibirdaño(int damagerecib) { hp -= damagerecib; }
	virtual void atacar(Character* objetivo) {};
};

