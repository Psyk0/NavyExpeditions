#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Configuration.h" 
#include "Jogador.h"
#include "Celula.h"
#include "Pirata.h"

using namespace std;

class Game{
public:
	Game(Configuration config);

	void displayMenuTwo();
	void resolveCommand(string comando);
	void getFileCommands(string fich);
	void run();
	void displayMap();
	void displayShips();
	void displayShipsP();
	void displayLista();
	void displayInfoShips();
	void setGrelha();
	void setPortos();
	void save(string nome);
	void load(string nome);
	void del(string nome);
	void eventPhase();
	void autoPhase();
	void combatPhase();
	bool confirmaComando(string comando);
	~Game();
	
private:
	Configuration config;
	Jogador jog;
	Pirata pir;
	vector <vector <Celula>> grelha;
};