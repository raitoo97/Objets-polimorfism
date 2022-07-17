#include "Loboblanco.h"

Loboblanco::Loboblanco()
{
	srand(time(NULL));
	hp = 80;
	damage = 0;
	damageB = 0;
	clase = "Lobo de Hielo";
	name = "Lobo Alfa";
}
void Loboblanco::recibirdaño(int damagerecib)
{
	hp -= damagerecib;
}
void Loboblanco::atacar(Character* objetivo)
{
	srand(time(NULL));
	damage = rand() % 8 + 1;
	damageB = rand() % 8 + 1;
	objetivo->recibirdaño(damage);
	cout << "El PJ ah sufrido " << damage << " puntos de dano a causa de una mordida" << endl;
	objetivo->recibirdaño(damageB);
	cout << "El PJ ah sufrido " << damageB << " puntos de dano a causa de las garras " << endl;
}
void Loboblanco::habilidadespecial()
{
	srand(time(NULL));
	int x = rand() % 10 + 1;
	cout << "El lobo ha aullado a la luna y se ha curado " << x << " puntos de salud.";

}



