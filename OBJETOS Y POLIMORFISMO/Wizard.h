#pragma once
#include "Character.h"
#include "Enemigo.h"
#include <iostream>
#include <ctime>
using namespace std;
class Wizard : public Character
{

public:
	Wizard();
	virtual void recibirdaño(int damagehp) override;
	virtual void atacar(Enemigo* objetivo) override;
	void ataqueespecial();
	void descripcion();
	~Wizard();
};

