#pragma once
#include "Enemigo.h"
#include <iostream>
#include <ctime>
#include "Character.h"
using namespace std;
class Loboblanco : public Enemigo{
protected:

	int damageB = 0;


public:
	Loboblanco();
	virtual void recibirdaño(int damagerecib) override;
	virtual void atacar(Character* objetivo) override;
	virtual void habilidadespecial();

};

