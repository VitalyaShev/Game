#include "Controller.h"
#include "Model.h"
#include <iostream>
#include <fstream>
#include <conio.h>


void Gamefield::display() {
	system("cls");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << field[i][j];
		cout << endl;
	}
}


void Gamefield::gameover(Player p1, Player p2) {
    system("cls");
	if (p1.take_s())
		cout << "Win Player2";
	else
		cout << "Win Player1";
}


