// NavyExpeditions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Configuration.h"
#include "Game.h"
#include "Consola.h"

using namespace std;

int main(){
	Consola::setTextColor(Consola::BRANCO);
	Consola::setTextSize(18, 18);
	Consola::setScreenSize(50, 50);
	Consola::setBackgroundColor(Consola::PRETO);

	Configuration config;
	config.run();
	Game game(config);
	game.run();

    return 0;
}

