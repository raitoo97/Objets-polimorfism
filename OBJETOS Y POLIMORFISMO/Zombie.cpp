#include "Zombie.h"

Zombie::Zombie()
{
	hp = 50;
	damage = 10;
	oro = 3;
	name = "Zombie";
	paralizado = false;
}
void Zombie::recibirdaño(int damagerecib)
{
	hp -= damagerecib;
}
void Zombie::atacar(Character* objetivo)
{

	objetivo->recibirdaño(damage);
	cout << "El zombie ha hecho: " << damage << " Puntos de dano" << endl;

}
Zombie::~Zombie()
{
}
