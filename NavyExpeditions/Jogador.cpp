#include "stdafx.h"
#include "Jogador.h"
#include "Veleiro.h"
#include "Escuna.h"
#include "Fragata.h"
#include "Galeao.h"
#include "Game.h"
#include <ctime>

Jogador::Jogador() {}

void Jogador::setVeleiro(Veleiro v) {
	navios.push_back(v);
}
void Jogador::setEscuna(Escuna e) {
	navios.push_back(e);
}
void Jogador::setFragata(Fragata f) {
	navios.push_back(f);
}
void Jogador::setGaleao(Galeao g) {
	navios.push_back(g);
}
void Jogador::setIate(Iate i) {
	navios.push_back(i);
}
void Jogador::setMoney(int m) {
	this->money = this->money + m;
}

int Jogador::getMoney() {
	return this->money;
}
vector<Navio> Jogador::getVectorNavios() {
	return navios;
}
void Jogador::setPorto(Porto p) {
	portos.push_back(p);
}
vector<Navio> Jogador::getVectorNaviosDeriva() {
	return naviosDeriva;
}
vector<Porto> Jogador::getVectorPortos() {
	return portos;
}
void Jogador::moveNavios(int n, string x, vector <vector <Celula>>& grelha) {
	//converter a string x para UPPER CASE
	x[0] = toupper(x[0]);
	x[1] = toupper(x[1]);

	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getId() == n) {
			int xx = navios[i].getX();
			int yy = navios[i].getY();

			if (x == "D") {
				if (yy + 1 <= grelha[0].size() - 1) {
					if (grelha[xx][yy + 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else
						navios[i].setY(navios[i].getY() + 1);
				}
				else {
					if (grelha[xx][0].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setY(0);
					}
				}
			}
			else if (x == "E"){
				if (yy - 1 >= 0) {
					if (grelha[xx][yy - 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else
						navios[i].setY(navios[i].getY() - 1);
				}
				else {
					if (grelha[xx][grelha[0].size() - 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setY(grelha[0].size() - 1);
					}
				}
			}
			else if (x == "C"){
				if (xx - 1 >= 0) {
					if (grelha[xx - 1][yy].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else
						navios[i].setX(navios[i].getX() - 1);
				}
				else {
					if (grelha[grelha.size() - 1][yy].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(grelha.size() - 1);
					}
				}

			}
			else if (x == "B") {
				if (xx + 1 <= grelha.size() - 1) {
					if (grelha[xx + 1][yy].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else
						navios[i].setX(navios[i].getX() + 1);
				}
				else {
					if (grelha[0][yy].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(0);
					}
				}
			}
			else if (x == "CE") {
				if (xx - 1 >= 0 && yy - 1 >= 0) {
					if (grelha[xx - 1][yy - 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(navios[i].getX() - 1);
						navios[i].setY(navios[i].getY() - 1);
					}
				}
				else if (xx - 1 < 0 && yy - 1 >= 0) {
					if (grelha[grelha.size() - 1][yy - 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(grelha.size() - 1);
						navios[i].setY(navios[i].getY() - 1);
					}
				}
				else if (xx - 1 >= 0 && yy - 1 < 0) {
					if (grelha[xx - 1][grelha[0].size() - 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(navios[i].getX() - 1);
						navios[i].setY(grelha[0].size() - 1);
					}
				}
				else if (xx - 1 < 0 && yy - 1 < 0) {
					if (grelha[grelha.size() - 1][grelha[0].size() - 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(grelha.size() - 1);
						navios[i].setY(grelha[0].size() - 1);
					}
				}
			}
			else if (x == "CD") {
				if (xx - 1 >= 0 && yy + 1 <= grelha[0].size() - 1) {
					if (grelha[xx - 1][yy + 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(navios[i].getX() - 1);
						navios[i].setY(navios[i].getY() + 1);
					}
				}
				else if (xx - 1 < 0 && yy + 1 <= grelha[0].size() - 1) {
					if (grelha[grelha.size() - 1][yy + 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(grelha.size() - 1);
						navios[i].setY(navios[i].getY() + 1);
					}
				}
				else if (xx - 1 >= 0 && yy + 1 > grelha[0].size() - 1) {
					if (grelha[xx - 1][0].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(navios[i].getX() + 1);
						navios[i].setY(0);
					}
				}
				else if (xx - 1 < 0 && yy + 1 > grelha[0].size() - 1) {
					if (grelha[grelha.size() - 1][0].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(grelha.size() - 1);
						navios[i].setY(0);
					}
				}
			}
			else if (x == "BE") {
				if (xx + 1 <= grelha.size() - 1 && yy - 1 >= 0) {
					if (grelha[xx + 1][yy - 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(navios[i].getX() + 1);
						navios[i].setY(navios[i].getY() - 1);
					}
				}
				else if (xx + 1 > grelha.size() - 1 && yy - 1 >= 0) {
					if (grelha[0][yy - 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(0);
						navios[i].setY(navios[i].getY() - 1);
					}
				}
				else if (xx + 1 <= grelha.size() - 1 && yy - 1 < 0) {
					if (grelha[xx + 1][grelha[0].size() - 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(navios[i].getX() + 1);
						navios[i].setY(grelha[0].size() - 1);
					}
				}
				else if (xx + 1 > grelha.size() - 1 && yy - 1 < 0) {
					if (grelha[0][grelha[0].size() - 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(0);
						navios[i].setY(grelha[0].size() - 1);
					}
				}
			}
			else if (x == "BD") {
				if (xx + 1 <= grelha.size() - 1 && yy + 1 <= grelha[0].size()) {
					if (grelha[xx + 1][yy + 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(navios[i].getX() + 1);
						navios[i].setY(navios[i].getY() + 1);
					}
				}
				else if (xx + 1 > grelha.size() - 1 && yy + 1 <= grelha[0].size()) {
					if (grelha[0][yy + 1].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(0);
						navios[i].setY(navios[i].getY() + 1);
					}
				}
				else if (xx + 1 <= grelha.size() - 1 && yy + 1 > grelha[0].size()) {
					if (grelha[xx + 1][0].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(navios[i].getX() + 1);
						navios[i].setY(0);
					}
				}
				else if (xx + 1 > grelha.size() - 1 && yy + 1 > grelha[0].size()) {
					if (grelha[0][0].getImg() == '+') {
						cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
						break;
					}
					else {
						navios[i].setX(0);
						navios[i].setY(0);
					}
				}
			}
			else
				cout << "Comando movimento incorreto!" << endl;
		}
	}
}

void Jogador::compraNav(string tipo, int preco) {
	if (getMoney() - preco >= 0) {
		if (tipo == "v") {
			Veleiro v;
			v.setX(portos[0].getX()); //criar navio no porto principal
			v.setY(portos[0].getY()); //ir buscar o primeiro porto do vetor de portos, ou seja o principal
			setVeleiro(v);
			setMoney(-preco);
			cout << "Comprou um navio do tipo Veleiro" << endl;
		}
		else if (tipo == "e") {
			Escuna e;
			e.setX(portos[0].getX());
			e.setY(portos[0].getY());
			setEscuna(e);
			setMoney(-preco);
			cout << "Comprou um navio do tipo Escuna" << endl;
		}
		else if (tipo == "g") {
			Galeao g;
			g.setX(portos[0].getX());
			g.setY(portos[0].getY());
			setGaleao(g);
			setMoney(-preco);
			cout << "Comprou um navio do tipo Galeao" << endl;
		}
		else if (tipo == "f") {
			Fragata f;
			f.setX(portos[0].getX());
			f.setY(portos[0].getY());
			setFragata(f);
			setMoney(-preco);
			cout << "Comprou um navio do tipo Fragata" << endl;
		}
		else if (tipo == "i") {
			Iate i;
			i.setX(portos[0].getX());
			i.setY(portos[0].getY());
			setIate(i);
			setMoney(-preco);
			cout << "Comprou um navio do tipo Iate" << endl;
		}
		else {
			cout << "Tipo de navio inexistente!" << endl;
			return;
		}
	}
	else {
		cout << "Nao tem dinheiro suficiente" << endl;
	}
}

bool Jogador::segueNavio(Navio n1, Navio n2) {
	if ((n1.getX() == n2.getX() - 2 && n1.getY() == n2.getY() - 2)) {
		n1.setX(n1.getX() - 2);
		n1.setY(n1.getY() - 2);
		return true;
	}
	else if ((n1.getX() == n2.getX() - 2 && n1.getY() == n2.getY() - 1)) {
		n1.setX(n1.getX() - 2);
		n1.setY(n1.getY() - 1);
		return true;
	}
	else if ((n1.getX() == n2.getX() - 2 && n1.getY() == n2.getY() - 0)) {
		n1.setX(n1.getX() - 2);
		n1.setY(n1.getY() - 0);
		return true;
	}
	else if ((n1.getX() == n2.getX() - 2 && n1.getY() == n2.getY() + 1)) {
		n1.setX(n1.getX() - 2);
		n1.setY(n1.getY() + 1);
		return true;
	}
	else if ((n1.getX() == n2.getX() - 2 && n1.getY() == n2.getY() + 2)) {
		n1.setX(n1.getX() - 2);
		n1.setY(n1.getY() + 2);
		return true;
	}
	else if ((n1.getX() == n2.getX() + 2 && n1.getY() == n2.getY() - 2)) {
		n1.setX(n1.getX() + 2);
		n1.setY(n1.getY() - 2);
		return true;
	}
	else if ((n1.getX() == n2.getX() + 2 && n1.getY() == n2.getY() - 1)) {
		n1.setX(n1.getX() + 2);
		n1.setY(n1.getY() - 1);
		return true;
	}
	else if ((n1.getX() == n2.getX() + 2 && n1.getY() == n2.getY() - 0)) {
		n1.setX(n1.getX() + 2);
		n1.setY(n1.getY() - 0);
		return true;
	}
	else if ((n1.getX() == n2.getX() + 2 && n1.getY() == n2.getY() + 1)) {
		n1.setX(n1.getX() + 2);
		n1.setY(n1.getY() + 1);
		return true;
	}
	else if ((n1.getX() == n2.getX() + 2 && n1.getY() == n2.getY() + 2)) {
		n1.setX(n1.getX() + 2);
		n1.setY(n1.getY() + 2);
	}
	else if ((n1.getX() == n2.getX() - 1 && n1.getY() == n2.getY() - 2)) {
		n1.setX(n1.getX() - 1);
		n1.setY(n1.getY() - 2);
		return true;
	}
	else if ((n1.getX() == n2.getX() - 0 && n1.getY() == n2.getY() - 2)) {
		n1.setX(n1.getX() - 0);
		n1.setY(n1.getY() - 2);
		return true;
	}
	else if ((n1.getX() == n2.getX() + 1 && n1.getY() == n2.getY() - 2)) {
		n1.setX(n1.getX() + 1);
		n1.setY(n1.getY() - 2);
		return true;
	}
	else if ((n1.getX() == n2.getX() - 1 && n1.getY() == n2.getY() + 2)) {
		n1.setX(n1.getX() - 1);
		n1.setY(n1.getY() + 2);
		return true;
	}
	else if ((n1.getX() == n2.getX() - 0 && n1.getY() == n2.getY() + 2)) {
		n1.setX(n1.getX() - 0);
		n1.setY(n1.getY() + 2);
		return true;
	}
	else if ((n1.getX() == n2.getX() + 1 && n1.getY() == n2.getY() + 2)) {
		n1.setX(n1.getX() + 1);
		n1.setY(n1.getY() + 2);
		return true;
	}
	return false;
}

void Jogador::moverFragataAut(vector<Navio> naviosPiratas) {
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getIcon() == 'f') {
			for (unsigned int j = 0; j < naviosPiratas.size(); j++) {
				if ((navios[i].getX() == naviosPiratas[j].getX() - 1 && (navios[i].getY() == naviosPiratas[j].getY() - 1 || navios[i].getY() == naviosPiratas[j].getY() || navios[i].getY() == naviosPiratas[j].getY() + 1))
					|| (navios[i].getX() == naviosPiratas[j].getX() && (navios[i].getY() == navios[j].getY() - 1 || navios[i].getY() == naviosPiratas[j].getY() || navios[i].getY() == naviosPiratas[j].getY() + 1))
					|| (navios[i].getX() == naviosPiratas[j].getX() + 1) && ((navios[i].getY() == naviosPiratas[j].getY() - 1 || navios[i].getY() == naviosPiratas[j].getY() || navios[i].getY() == naviosPiratas[j].getY() + 1))) {
					//combate
				}
				else if (navios[i].getAut() == true) {
					if (segueNavio(navios[i], naviosPiratas[j]))
						return;
					else {
						for (unsigned int k = 0; k < navios.size(); k++) {
							if (navios[k].getIcon() == 'e' || navios[k].getIcon() == 'g') {
								if (segueNavio(navios[i], navios[k]))
									return;
						}
					}
				}
				}
			}
		}
	}
}

void Jogador::verifcaEscuna() {
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getIcon() == 'v' || navios[i].getIcon() == 'g' || navios[i].getIcon() == 'i') {
			for (unsigned int j = 0; j < navios.size(); j++) {
				if (navios[i].getIcon() == 'v') {
					if ((navios[i].getX() == navios[j].getX() - 1 && (navios[i].getY() == navios[j].getY() - 1 || navios[i].getY() == navios[j].getY() || navios[i].getY() == navios[j].getY() + 1))
						|| (navios[i].getX() == navios[j].getX() && (navios[i].getY() == navios[j].getY() - 1 || navios[i].getY() == navios[j].getY() || navios[i].getY() == navios[j].getY() + 1))
						|| (navios[i].getX() == navios[j].getX() + 1) && ((navios[i].getY() == navios[j].getY() - 1 || navios[i].getY() == navios[j].getY() || navios[i].getY() == navios[j].getY() + 1))) {
						if (navios[i].getIcon() == 'v') {
							if (40 - navios[i].getMercadoria() > navios[j].getMercadoria()) {
								navios[i].setMercadorias(navios[j].getMercadoria());
								navios[j].setMercadorias(-navios[j].getMercadoria());
							}
							else {
								navios[j].setMercadorias(-(40 - navios[i].getMercadoria()));
								navios[i].setMercadorias(40 - navios[i].getMercadoria());
							}
						}
						else if (navios[i].getIcon() == 'g') {
							if (70 - navios[i].getMercadoria() > navios[j].getMercadoria()) {
								navios[i].setMercadorias(navios[j].getMercadoria());
								navios[j].setMercadorias(-navios[j].getMercadoria());
							}
							else {
								navios[j].setMercadorias(-(70 - navios[i].getMercadoria()));
								navios[i].setMercadorias(70 - navios[i].getMercadoria());
							}
						}
						else if (navios[i].getIcon() == 'i') {
							if (100 - navios[i].getMercadoria() > navios[j].getMercadoria()) {
								navios[i].setMercadorias(navios[j].getMercadoria());
								navios[j].setMercadorias(-navios[j].getMercadoria());
							}
							else {
								navios[j].setMercadorias(-(100 - navios[i].getMercadoria()));
								navios[i].setMercadorias(100 - navios[i].getMercadoria());
							}
						}
					}

					if (navios[i].getAut() == true) {
						if (navios[i].getIcon() == 'v') {
							segueNavio(navios[i], navios[j]);
						}
					}
				}
			}
		}
	}
}
void Jogador::autoEscuna(vector <vector <Celula>>& grelha) {
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getIcon() == 'e') {
			if (grelha[navios[i].getX()][navios[i].getY()].getImg() == '.') {
				if (grelha[navios[i].getX()][navios[i].getY()].getT()->ret() == true) {
					navios[i].setPeixe(+1);
					grelha[navios[i].getX()][navios[i].getY()].getT()->change(false);
				}
				else {
					grelha[navios[i].getX()][navios[i].getY()].getT()->produzir();
				}
			}
		}
	}
}
void Jogador::compraMercadorias(int id, int quantidade, int preco) {
	
	bool done = false;
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getId() == id) {
			for (unsigned int j = 0; j < portos.size(); j++) {
				if (navios[i].getX() == portos[j].getX() && navios[i].getY() == portos[j].getY()) {
					if (getMoney() - (quantidade * preco) >= 0) {
						if (navios[i].setMercadorias(quantidade)) {
							setMoney(-(quantidade * preco));
						}
					}
					else {
						cout << "Nao tem dinheiro suficiente" << endl;
					}
					this->navios[i].setAgua(1000);
					done = true;
				}
			}
			if (!done) {
				cout << "O navio escolhido nao esta num porto" << endl;
			}
		}
	}
}

void Jogador::vendeMercadorias(int id, int precoM, int precoP) {
	bool done = false;
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getId() == id) {
			for (unsigned int j = 0; j < portos.size(); j++) {
				if (navios[i].getX() == portos[j].getX() && navios[i].getY() == portos[j].getY()) {
					setMoney(navios[i].getMercadoria() * precoM);
					setMoney(navios[i].getPeixe() * precoP);
					navios[i].setMercadorias(-navios[i].getMercadoria());
					navios[i].setPeixe(-navios[i].getPeixe());
					this->navios[i].setAgua(1000);
					done = true;
				}
			}
			if (!done) {
				cout << "O navio escolhido nao esta num porto" << endl;
			}
		}
	}
}

void Jogador::vendeNavio(string tipo, int precoM, int precoP, int precoN) {
	bool done = false;
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getIcon() == tipo[0]) {
			for (unsigned int j = 0; j < portos.size(); j++) {
				if (navios[i].getX() == portos[j].getX() && navios[i].getY() == portos[j].getY()) {
					setMoney(navios[i].getMercadoria() * precoM);
					setMoney(navios[i].getPeixe() * precoP);
					setMoney(precoN);
					navios.erase(navios.begin() + i);
					cout << money << endl;
					done = true;
				}
			}
			if (!done) {
				cout << "O navio escolhido nao esta num porto" << endl;
			}
		}
	}
}

void Jogador::compraSoldados(int id, int quantidade, int preco) {
	bool done = false;
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getId() == id) {
			for (unsigned int j = 0; j < portos.size(); j++) {
				if (navios[i].getX() == portos[j].getX() && navios[i].getY() == portos[j].getY()) {
					if (navios[i].setSoldados(quantidade)) {
						setMoney(-(quantidade * preco));
					}
					this->navios[i].setAgua(1000);
					done = true;
				}
			}
			if (!done) {
				cout << "O navio escolhido nao esta num porto" << endl;
			}
		}
	}
}

void Jogador::ativarMovimentoAuto(int id) {
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getId() == id) {
			navios[i].setAut(true);
		}
	}
}

void Jogador::movimentoStop(int id) {
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getId() == id) {
			navios[i].setAut(false);
		}
	}
}

void Jogador::combateNavios(vector<Navio> naviosPiratas) {
	for (unsigned int i = 0; i < navios.size(); i++) {
		for (unsigned int j = 0; i < naviosPiratas.size(); j++) {
			if ((navios[i].getX() == naviosPiratas[j].getX() - 1 && (navios[i].getY() == naviosPiratas[j].getY() - 1 || navios[i].getY() == naviosPiratas[j].getY() || navios[i].getY() == naviosPiratas[j].getY() + 1))
				|| (navios[i].getX() == naviosPiratas[j].getX() && (navios[i].getY() == navios[j].getY() - 1 || navios[i].getY() == naviosPiratas[j].getY() || navios[i].getY() == naviosPiratas[j].getY() + 1))
				|| (navios[i].getX() == naviosPiratas[j].getX() + 1) && ((navios[i].getY() == naviosPiratas[j].getY() - 1 || navios[i].getY() == naviosPiratas[j].getY() || navios[i].getY() == naviosPiratas[j].getY() + 1))) {
				srand(time(NULL));
				int n1 = rand() % navios[i].getSoldados() + 1;
				srand(time(NULL));
				int n2 = rand() % naviosPiratas[j].getSoldados() + 1;
				if (n1 > n2) {
					cout << "Barco do jogador venceu o combate" << endl;
					naviosPiratas[j].setSoldados(-((navios[i].getSoldados() * 0.2) * 2));
					navios[i].setSoldados(-(navios[i].getSoldados() * 0.2));
					if (naviosPiratas[j].getSoldados() < 1) {
						navios[i].setMercadorias(naviosPiratas[j].getMercadoria() / 2);
						navios[i].setAgua(naviosPiratas[j].getAgua());
						naviosPiratas.erase(naviosPiratas.begin() + j);
					}
				}
				else if (n2 > n1) {
					cout << "Barco pirata venceu o combate" << endl;
					navios[i].setSoldados(-((naviosPiratas[j].getSoldados() * 0.2) * 2));
					naviosPiratas[j].setSoldados(-(naviosPiratas[j].getSoldados() * 0.2));
					if (navios[i].getSoldados() < 1) {
						naviosPiratas[j].setMercadorias(navios[i].getMercadoria() / 2);
						navios.erase(navios.begin() + i);
					}
				}
			}
		}
	}
}

void Jogador::consomeAgua() {
	for (unsigned int i = 0; i < navios.size(); i++) {
		navios[i].setAgua(-1);
	}
}

Jogador::~Jogador(){}
