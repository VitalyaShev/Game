#include "Model.h"
#include "Controller.h"


using namespace std;

int main() {
	int a;
	Player t1(0, 0, "WASD", 'C');
	cout << "Print mode: 1-Player, 2-Bot\n";
	cin >> a;
	Player t2(1, a, "IJKL", 'M');
	Gamefield g;
	while (g.update(t1,g) && g.update(t2,g)) {
		g.display();
		t1.direc(g);
		t2.direc(g);
		Sleep(100);
	}
	g.gameover(t1, t1);
}