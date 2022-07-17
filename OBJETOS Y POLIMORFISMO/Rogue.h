#pragma once
#include "Character.h"
#include "Enemigo.h"
#include <ctime>
#include <iostream>
using namespace std;

class Rogue : public Character
{

public:
    Rogue();
    virtual void recibirdaño(int damagehp) override;
    virtual void atacar(Enemigo* objetivo) override;
    void ataqueespecial(Enemigo* objetivo);
    void descripcion();
    ~Rogue();


};

