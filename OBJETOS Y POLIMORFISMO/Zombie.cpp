#include "Zombie.h"

Zombie::Zombie()
{
	hp = 50;
	damage = 10;
	oro = 3;
	name = "Zombie";
	paralizado = false;
}
void Zombie::recibirda�o(int damagerecib)
{
	hp -= damagerecib;
}
void Zombie::atacar(Character* objetivo)
{

	objetivo->recibirda�o(damage);
	cout << "El zombie ha hecho: " << damage << " Puntos de dano" << endl;

}
Zombie::~Zombie()
{
}
