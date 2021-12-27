#include "Controller.h"
#include "Model.h"


Player::Player(int a, int b, string key, char l) {
	get_num(a);
	get_mod(b);
	k = key;
	w = l;
	if (mod == 2)
	{
		dir = start_bot("ULDR");
	}
	if (a == 0) {
		post.first = 11;
		post.second = 1;
	}
	else
	{
		post.first = 11;
		post.second = 25;
	}
}

void Player::get_num(int a) {
	num = a;
}

void Player::get_mod(int b) {
	mod = b;
}
void Player::direc(Gamefield g) {
	if (mod != 2) {
		if (GetAsyncKeyState(k[0]) && (dir != 'U')) {
			dir = 'U';
		}
		else
			if (GetAsyncKeyState(k[1]) && (dir != 'L')) {
				dir = 'L';
			}
			else
				if (GetAsyncKeyState(k[2]) && (dir != 'D')) {
					dir = 'D';
				}
				else
					if (GetAsyncKeyState(k[3]) && (dir != 'R')) {
						dir = 'R';
					}
					else
						if (GetAsyncKeyState(w))
							 stack = 1;
	}
	else
		bot(g);
}

pair<int, int> Player::stept(Gamefield g) {
	if (dir == 'U') {
		if (stack != 1)
			post.first--;
		else {
			post.first--;
			g.field[post.first + 1][post.second] = 42;
			stack = 0;
		}
	}
	else if (dir == 'L') {
		if (stack != 1)
			post.second--;
		else {
			post.second--;
			g.field[post.first][post.second + 1] = 42;
			stack = 0;
		}
	}
	else if (dir == 'D'){
		if (stack != 1)
			post.first++;
		else {
			post.first++;
			g.field[post.first - 1][post.second] = 42;
			stack = 0;
		}
}
	else if (dir == 'R') {
		if (stack != 1)
			post.second++;
		else {
			post.second++;
			g.field[post.first][post.second - 1] = 42;
			stack = 0;
		}
	}
	return post;
}
int Player::checkt(Gamefield g) {
	if ((dir == 'U') && (g.field[post.first - 1][post.second] != 32)) {
		if (g.field[post.first - 1][post.second] == 42)
			return 2;
		else
			return 1;
	}
	else 
		if ((dir == 'L') && (g.field[post.first][post.second - 1] != 32)) {
			if (g.field[post.first][post.second - 1] == 42)
				return 2;
			else
				return 1;
		}
	if ((dir == 'D') && (g.field[post.first + 1][post.second] != 32)) {
		if (g.field[post.first + 1][post.second] == 42)
			return 2;
		else
			return 1;
	}
	if ((dir == 'R') && (g.field[post.first][post.second + 1] != 32)) {
		if (g.field[post.first][post.second + 1] == 42)
			return 2;
		else
			return 1;
	}
	else 
	return 0;
}
int Player::get_stack() {
	return stack;
}
void Player::get_s() {
	 s = 1;
}
int Player::take_s() {
	return s;
}

char Player::start_bot(string h) {
	int a = rand() % 3;
	return h[a];
}
char Player::check_dir(Gamefield g)
{ 
	string str = "";
	int a = 0;
	if (dir == 'U')  {
		if (g.field[post.first][post.second + 1] == 32) {
			str.insert(0, 1, 'R');
			a++;
		}
			if (g.field[post.first][post.second - 1] == 32) {
				str.insert(1, 1, 'L');
				a++;
			}
			if (g.field[post.first + 1][post.second] == 32) {
				str.insert(2, 1, 'D');
				a++;
			}
	}
	else
		if (dir == 'L') {
			if (g.field[post.first][post.second + 1] == 32) {
				str.insert(0, 1, 'R');
				a++;
			}
			if (g.field[post.first - 1][post.second] == 32) {
				str.insert(1, 1, 'U');
				a++;
			}
			if (g.field[post.first + 1][post.second] == 32) {
				str.insert(2, 1, 'D');
				a++;
			}
		}
		else
			if (dir == 'D') {
				if (g.field[post.first][post.second + 1] == 32){
					str.insert(0, 1, 'R');
					a++;
			}
				if (g.field[post.first][post.second - 1] == 32) {
					str.insert(1, 1, 'L');
					a++;
				}
				if (g.field[post.first - 1][post.second] == 32) {
					str.insert(2, 1, 'U');
					a++;
				}
			}
			else
				if (dir == 'R') {
					if (g.field[post.first - 1][post.second] == 32) {
						str.insert(0, 1, 'U');
						a++;
					}
					if (g.field[post.first][post.second - 1] == 32) {
						a++;
						str.insert(1, 1, 'L');
					}
					if (g.field[post.first + 1][post.second] == 32) {
						str.insert(2, 1, 'D');
						a++;
					}
				}
	a = rand() % (a - 1);
	return str[a];
}
void Player::bot(Gamefield g)
{
	int chan;
	chan = rand() % 6 + 1;
	if ((dir == 'U') && (g.field[post.first - 1][post.second] != 32)){
		if (g.field[post.first - 1][post.second] == 42) {
			int a = rand() % 3 + 1;
			if (a == 2)
				dir = 'D';
		}
		else
			dir = check_dir(g);
	}
	else if ((dir == 'L') && (g.field[post.first][post.second - 1] !=32)) {
		if (g.field[post.first][post.second-1] == 42) {
			int a = rand() % 3 + 1;
			if (a == 2)
				dir = 'R';
		}
		else
			dir = check_dir(g);
	}
	else if ((dir == 'D') && (g.field[post.first + 1][post.second] != 32)) {
		if (g.field[post.first + 1][post.second] == 42) {
			int a = rand() % 3 + 1;
			if (a == 2)
				dir = 'U';
		}
		else
			dir = check_dir(g);
	}
	else if ((dir == 'R') && (g.field[post.first][post.second + 1] != 32)) {
		if (g.field[post.first][post.second + 1] == 42) {
			int a = rand() % 3 + 1;
			if (a == 2)
				dir = 'L';
		}
		else
			dir = check_dir(g);
	}
	else if (chan == 2)
		stack = 1;
}
