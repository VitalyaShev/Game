#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Controller.h"

class Player;

using namespace std;
class Gamefield
{
public:
	char** field;
	int N, M;
	Gamefield();
	int update(Player&, Gamefield g);
	void display();
	void gameover(Player p1, Player p2);
};
