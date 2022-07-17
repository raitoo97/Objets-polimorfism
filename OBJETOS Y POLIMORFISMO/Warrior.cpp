#include "Warrior.h"

Warrior::Warrior()
{	hp = 150;
	damage = 10;
	oro = 100;
	name = "Warrior_prueba";
	clase = "Warrior";
}
void Warrior::recibirdaño(int damagehp)
{
	int x = damagehp / 2;
	hp -= x;
	cout << "has recibido " << x << " puntos de dano." << endl;
}
void Warrior::atacar(Enemigo* objetivo)
{

	objetivo->recibirdaño(damage);
	cout << "has infligido " << damage << " puntos de dano." << endl;
}
void Warrior::ataqueespecial(Enemigo* objetivo) {

	srand(time(NULL));
	int x = rand() % 100 + 1;
	if (x <= 50) {
		objetivo->setparalizado(true);
		cout << "El objetivo fue paralizado" << endl;
	}
	else {
		cout << "El objetivo no fue paralizado" << endl;
	}

	
}
void Warrior::descripcion()
{
	cout << "Guerrero: El guerrero lucha con una espada junto con un escudo, es un gran luchador y soporta casi cualquier tipo de golpe." << endl;
	cout << "Skills:" << endl;
	cout << "Armadura pesada: Recibe un 50% menos de dano al ser atacado." << endl;
	cout << "Ataque: Golpeas al objetivo con tu espada infligiendole 10 putos de dano." << endl;
	cout << "Habilidad: Golpea con tu escudo al objetivo y tienes un 50% de posibilidad de stunearlo." << endl;

}
Warrior::~Warrior()
{
}

