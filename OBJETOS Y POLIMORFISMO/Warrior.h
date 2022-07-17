#pragma once
#include "Character.h"
#include "Enemigo.h"
#include <iostream>
#include <ctime>

using namespace std;


class Warrior : public Character
{

public:
	Warrior();
	virtual void recibirdaño(int damagehp) override;
	virtual void atacar(Enemigo* objetivo) override;
	void ataqueespecial(Enemigo* objetivo);
	void descripcion();
	~Warrior();
};

