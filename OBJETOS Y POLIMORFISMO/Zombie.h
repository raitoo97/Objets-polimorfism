#pragma once
#include <iostream>
#include "Enemigo.h"
#include "Character.h"
#include <ctime>
using namespace std;

class Zombie : public Enemigo
{

public:
	Zombie();
	virtual void recibirdaño(int damagerecib) override;
	virtual void atacar(Character* objetivo) override;
	~Zombie();
};

