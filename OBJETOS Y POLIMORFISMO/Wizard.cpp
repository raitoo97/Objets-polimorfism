#include "Wizard.h"

Wizard::Wizard()
{
	hp = 100;
	oro = 150;
	name = "Wizard_prueba";
	clase = "Wizard";

}
void Wizard::recibirdaño(int damagehp)
{
	int x = (damagehp) * 2;
	hp -= x;
	cout << "Has recibido " << x << " puntos de dano." << endl;
}
void Wizard::atacar(Enemigo* objetivo)
{
	srand(time(NULL));
	cout << "Por favor eliga un hechizo" << endl;
	cout << "1.Bolas de fuego" << endl;
	cout << "2.Latigo de Agua" << endl;
	cout << "3.Relampago" << endl;

	int Eleccion = 0;
	cin >> Eleccion;

	switch (Eleccion)
	{
	case 1:
		damage = rand() % 8 + 1;
		objetivo->recibirdaño(damage);
		cout << "has infligido " << damage << " puntos de dano con el primer ataque." << endl;
		objetivo->recibirdaño(damage);
		cout << "has infligido " << damage << " puntos de dano con el segundo ataque." << endl;
		break;
	case 2:
		damage = 15;
		objetivo->recibirdaño(damage);
		cout << "has infligido " << damage << " puntos de dano." << endl;
		break;
	case 3:
		int probabilidad = rand() % 100 + 1;
		damage = rand() % 10 + 1;
		objetivo->recibirdaño(damage);
		cout << "has infligido " << damage << " puntos de dano." << endl;
		if (probabilidad <= 50) {
			objetivo->setparalizado(true);
			cout << "El objetivo fue paralizado" << endl;
		}
		else
			cout << "EL objetivo no fue paralizado" << endl;
	}


}
void Wizard::ataqueespecial()
{
	srand(time(NULL));
	int x = rand() % 20 + 1;
	hp += x;
	cout << "Te has sanado " << x << " puntos de salud." << endl;

}
void Wizard::descripcion()
{
	cout << "Mago: El mago es una clase que se especializa en los ataques a distancias conjurando distintos hechizos." << endl;
	cout << "Ademas el mago es un excelente sanador." << endl;
	cout << "Skills:" << endl;
	cout << "Armadura liviana: recibo el doble de dano por golpe recibido." << endl;
	cout << "1.Ataques:" << endl;
	cout << "Bolas de fuego: Tira dos bolas de fuego al enemigo, cada un infligue 1d8 puntos de dano." << endl;
	cout << "Latigo de agua: Un poderoso latigo de agua que inlige 15 puntos de dano al enemigo." << endl;
	cout << "Relampago: Convocas un relampago que chocara contra el enemigo infligiendole 1d10 puntos de dano," << endl;
	cout << "Ademas tienes un 50% de probabilidad de stunear al enemigo." << endl;
	cout << "2.Habilidad:" << endl;
	cout << "curacion inferior:El mago se puede curar a si mismo 1d20 puntos de dano." << endl;
}
Wizard::~Wizard()
{
}

