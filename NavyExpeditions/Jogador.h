#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Navio.h"
#include "Veleiro.h"
#include "Escuna.h"
#include "Fragata.h"
#include "Galeao.h"
#include "Iate.h"
#include "Porto.h"

using namespace std;

class Jogador {
public:
	
	Jogador();
	
	void setVeleiro(Veleiro v);
	void setEscuna(Escuna e);
	void setFragata(Fragata f);
	void setGaleao(Galeao g);
	void setIate(Iate i);
	void setPorto(Porto p);
	void setMoney(int m);
	int getMoney();
	void moveNavios();
	void compraNav(string tipo);
	vector<Navio> getVectorNavios();
	vector<Porto> getVectorPortos();
	void verifcaEscuna();
	void compraMercadorias(int id, int quantidade);
	void vendeMercadorias(int id);
	
	~Jogador();

private:

	int money;
	vector<Navio> navios;
	vector<Porto> portos;
};