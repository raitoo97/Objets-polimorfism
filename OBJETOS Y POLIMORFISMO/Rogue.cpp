#include "Rogue.h"

Rogue::Rogue()
{
	hp = 120;
	oro = 200;
	damage = 0;
	name = "Rogue_prueba";
	clase = "Rogue";
}
void Rogue::recibirdaño(int damagehp)
{
	int x = (damagehp) * 1.5;
	hp -= x;
	cout << "Has recibido " << x << " puntos de dano." << endl;
}
void Rogue::atacar(Enemigo* objetivo)
{
	int x = rand() % 25 + 1;
	objetivo->recibirdaño(x);
	cout << "has infligido " << x << " puntos de dano normales" << endl;
}
void Rogue::ataqueespecial(Enemigo* objetivo)
{
	srand(time(NULL));
	int y = rand() % 22 + 1;
	int xy = rand() % 11 + 1;
	int xyz = rand() % 5 + 1;

	objetivo->recibirdaño(y);
	cout << "has realizado " << y << " puntos de dano." << endl;
	if (y >= 11){
		objetivo->recibirdaño(xy);
		cout << "combo realizado, has infligido " << xy << " putos de dano adicional." << endl;
		if (xy >= 5){
			objetivo->recibirdaño(xyz);
			cout << "combo realizado, has infligido " << xyz << " putos de dano adicional." << endl;
		}
	}

}
void Rogue::descripcion()
{
	cout << "Picaro:Un feroz asesino con ataque letales hacia sus oponentes." << endl;
	cout << "Skills:" << endl;
	cout << "Armadura semipesada: recibe un 50% mas de dano por golpe recibido" << endl;
	cout << "1.Ataque: " << endl;
	cout << "inflige 1d25 puntos de dano al enemigo." << endl;
	cout << "2.Habilidad: " << endl;
	cout << "infligue 1d22 putnso de dano," << endl;
	cout << "si has infligado 11 o mas punto de ataque vuelve a atacar con 1d11" << endl;
	cout << "si has infligado 5 o mas punto de ataque vuelve a atacar con 1d5" << endl;
}
Rogue::~Rogue()
{
}
