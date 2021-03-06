#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Configuration{
public:
	Configuration();
	~Configuration();

	void run();
	void resolveCommands(bool *val, string comando);
	void displayMenuOne(string *comando);
	void getFileConfig(bool *val, string fich);

	int getLinhas();
	int getColunas();
	int getMoedas();
	float getProbPirata();
	int getPrecoNavio();
	int getPrecoSoldado();
	int getPrecoVendPeixe();
	int getPrecoCompMercad();
	int getPrecoVendMercad();
	int getSoldadosPorto();
	int getProbEvento();
	int getProbTempestade();
	int getProbSereias();
	int getProbCalmaria();
	int getProbMotim();

	void setLinhas(int l);
	void setColunas(int c);
	void setMoedas(int m);
	void setProbPirata(float p);
	void setPrecoNavio(int p);
	void setPrecoSoldado(int p);
	void setPrecoVendPeixe(int p);
	void setPrecoCompMercad(int p);
	void setPrecoVendMercad(int p);
	void setSoldadosPorto(int p);
	void setProbEvento(int p);
	void setProbTempestade(int p);
	void setProbSereias(int p);
	void setProbCalmaria(int p);
	void setProbMotim(int p);

	vector<string> getMapa();
	vector<string> map;
private:
	int linhas;
	int colunas;
	int moedas;
	float probpirata;
	int preconavio;
	int precosoldado;
	int precovendpeixe;
	int precocompmercad;
	int precovendmercad;
	int soldadosporto;
	int probevento;
	int probtempestade;
	int probsereias;
	int probcalmaria;
	int probmotim;

	//vector<string> map;
};