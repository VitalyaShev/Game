#include "Model.h"

class Player;
using namespace std;


Gamefield::Gamefield() {
	N = 19;
	M = 27;
	ifstream f("field.txt");
	string s = "", s1;
	while (getline(f, s1))
		s += s1;
	int k = 0;
	field = new char* [N];
	for (int i = 0; i < N; i++) {
		field[i] = new char[M];
		for (int j = 0; j < M; j++) {
			field[i][j] = s[k];
			k++;
		}
	}
}


int Gamefield::update(Player& p, Gamefield g) {
	if (p.checkt(g) == 1)
		return 1;
	if (p.checkt(g) == 2)
	{
		p.get_s();
		return 0;
	}
	field[p.post.first][p.post.second] = 32;
	pair<int, int> new_pos = p.stept(g);
	field[new_pos.first][new_pos.second] = 127;
	return 1;
}
