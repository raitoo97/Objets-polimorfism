#pragma once
#include <iostream>
#include <ctime>
#include "Character.h"
#include "Enemigo.h"
#include "Warrior.h"
#include "Zombie.h"
#include "Wizard.h"
#include "Rogue.h"
#include "Loboblanco.h"


using namespace std;
void mostrarmenu() {
	cout << "1.Atacar" << endl;
	cout << "2.Habilidad" << endl;
}
void controles() {
	system("pause");
	system("Cls");
}
void combate(Character* personaje, Enemigo* enemigo);
int main()
{
	//Presentacion de clases;
	Character* wizard = new Wizard();
	Character* rogue = new Rogue();
	Character* warrior = new Warrior();
	Enemigo* zombie = new Zombie();

	cout << "Bienvenido al juego en primer lugar tendras que elegir entre tres personajes cada uno con sus respectivas hablidades" << endl;
	cout << "Lee con antencion cada uno antes de pasar de pagina" << endl;
	controles();
	dynamic_cast<Wizard*>(wizard)->descripcion();
	controles();
	dynamic_cast<Rogue*>(rogue)->descripcion();
	controles();
	dynamic_cast<Warrior*>(warrior)->descripcion();

	delete wizard;
	wizard = nullptr;
	delete warrior;
	warrior = nullptr;
	delete rogue;
	rogue = nullptr;
	controles();
	//Eleccion de clase;

	Character* personaje = nullptr;

	cout << "Presiona el numero del personaje que quieras" << endl;
	cout << "1.Mago" << endl;
	cout << "2.Guerrero" << endl;
	cout << "3.Picaro" << endl;

	int seleccion = 0;
	cin >> seleccion;
	bool eleccion = false;
	while (!eleccion) {
		if (seleccion == 1) {
			personaje = new Wizard();
			eleccion = true;
			break;
		}
		else if (seleccion == 2) {
			personaje = new Warrior();
			eleccion = true;
			break;
		}
		else if (seleccion == 3) {
			personaje = new Rogue();
			eleccion = true;
			break;
		}
		else {
			cout << "Por favor escriba una opcion valida" << endl;
			cin >> seleccion;
			controles();

		}
	}

		cout << "Estas seguro que deseas seleccionar(escriba si o no): " << personaje->getclase() << endl;
		string confirmar = "";
		cin >> confirmar;
		bool clasedefinida = false;
		controles();
		while (!clasedefinida) {
			if (confirmar == "si" || confirmar == "Si" || confirmar == "SI") {
				cout << "felicidades has escogido " << personaje->getclase() << endl;
				clasedefinida = true;
				controles();
			}
			else {
				cout << "Por favor vuelve a seleccionar una clase." << endl;
				cout << "1.Mago" << endl;
				cout << "2.Guerrero" << endl;
				cout << "3.Picaro" << endl;

				cin >> seleccion;

				if (seleccion == 1) {
					personaje = new Wizard();
				}
				else if (seleccion == 2) {
					personaje = new Warrior();
				}
				else if (seleccion == 3) {
					personaje = new Rogue();
				}
				cout << "Estas seguro que deseas seleccionar(escriba si o no): " << personaje->getclase() << endl;
				cin >> confirmar;
				controles();
				if (confirmar == "si" || confirmar == "Si" || confirmar == "SI") {
					cout << "felicidades has escogido " << personaje->getclase() << endl;
					clasedefinida = true;
					controles();

				}
			}
		}

		//Primer combate;
		cout << "Prerate para el primer combate" << endl;
		cout << "Te enfrentaras a un zombie" << endl;
		cout << "Stats del zombie:" << endl;
		cout << "Vida del zombie: " << zombie->gethp() << endl;
		cout << "Dano del zombie: " << zombie->getdamage() << endl;
		controles();
		cout << "Stats del PJ:" << endl;
		cout << "Vida del PJ: " << personaje->gethp() << endl;
		if (personaje->getclase() == "Warrior") {
			cout << "Dano del PJ: " << personaje->getdamge() << endl;
		}
		controles();

		while (personaje->gethp() > 0 && zombie->gethp() > 0) {
			combate(personaje, zombie);
		}
		if (personaje->gethp() <= 0) {
			cout << "El personaje ha muerto" << endl;
			delete personaje;
			personaje = nullptr;
		}
		else if (zombie->gethp() <= 0) {
			cout << "El zombie ha muerto" << endl;
			delete zombie;
			zombie = nullptr;
		}
		controles();
		//Segundo combate;
		Enemigo* lobo = new Loboblanco();
		cout << "Te adentras en el bosque y te encontras con un lobo." << endl;
		controles();
		cout << "Sin motivo alguno tu personaje se cura toda la vida y aumenta mas tu salud" << endl;
		controles();
		if (personaje->getclase() == "Wizard") {
			personaje->sethp(150);
		}
		else if (personaje->getclase() == "Rogue") {
			personaje->sethp(170);
		}
		else if (personaje->getclase() == "Warrior") {
			personaje->sethp(200);
		}
		cout <<"Vida actual del personaje: "<< personaje->gethp() << endl;
		controles();
		while (personaje->gethp() > 0 && lobo->gethp() > 0) {
			if (personaje->gethp() <= 0) 
			{
				delete personaje;
				personaje = nullptr;
				break;
				
			}
			else if (lobo->gethp() <= 0) {

			}
			combate(personaje,lobo);
		}
		controles();
		if (personaje->gethp() <= 0) {
			delete personaje;
			personaje = nullptr;
			cout << "Tu personaje murio reinicia el juego." << endl;
		}
		else if (lobo->gethp() <= 0) {
			delete lobo;
			lobo = nullptr;
			cout << "El lobo murio." << endl;
			cout << "Gracias por jugar" << endl;
		}
		
		return 0;
}

	void combate(Character* personaje, Enemigo* enemigo) {
		mostrarmenu();
		int seleccion = 0;
		cin >> seleccion;
		if (seleccion == 1) {
			personaje->atacar(enemigo);
		}
		else if (seleccion == 2) {
			if (personaje->getclase() == "Warrior") {
				dynamic_cast<Warrior*>(personaje)->ataqueespecial(enemigo);
			}
			else if (personaje->getclase() == "Wizard") {
				dynamic_cast<Wizard*>(personaje)->ataqueespecial();
			}
			else if (personaje->getclase() == "Rogue") {
				dynamic_cast<Rogue*>(personaje)->ataqueespecial(enemigo);
			}
		}
		cout << "El enemigo tiene: " << enemigo->gethp() << " Puntos de vida" << endl;
		controles();

		if (!enemigo->getparalizado()) {
			srand(time(NULL));
			int turno = rand() % 1;
			switch (turno) {
			case 0:
				enemigo->atacar(personaje);
				cout << "El Personaje tiene: " << personaje->gethp() << " Puntos de vida" << endl;
				break;
			case 1:
				if (enemigo->getclase() == "Lobo de Hielo") {
					dynamic_cast<Loboblanco*>(enemigo)->habilidadespecial();
				}
				else {
					enemigo->atacar(personaje);
					cout << "El Personaje tiene: " << personaje->gethp() << " Puntos de vida" << endl;
				}
				break;
				
			}
			
		} else if (enemigo->getparalizado()) {
			srand(time(NULL));
			int x = rand() % 100 + 1;
			if (x >= 50) {
				enemigo->setparalizado(false);
				cout << "El enemigo no esta paralizado" << endl;
			}
			else
				cout << "El enemigo continua paralizado" << endl;
			controles();

		}
	

}
