#pragma once
#include <iostream>
#include <string>
#include <map>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <random>

using namespace std;

class Gamefield;

class Player {
private:
	int num;
	int mod;
	char dir;
	string k;
	char w;
	int s = 0;
	int stack = 0;
public:
	pair <int, int> post;
	Player(int a, int b, string key, char l);
	pair <int, int> stept(Gamefield g);
	void get_num(int a);
	void get_mod(int b);
	void direc(Gamefield g);
	void bot(Gamefield g);
	char start_bot(string h);
	int get_stack();
	int checkt(Gamefield g);
	void get_s();
	int take_s();
	char check_dir(Gamefield g);
};