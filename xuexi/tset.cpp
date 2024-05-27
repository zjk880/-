#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
bool gameover = 0;
int score;
const int mx = 20;
const int my = 20;
int snakex,snakey;
int Ftime;
int fx, fy;
enum Move { STOP = 0, RIGHT, LEFT, UP, DOWN};
Move dir;
void Setup() {
	gameover = false;
	score = 0;
	Ftime = 20;
	fx = rand() % 18 + 1;
	fy = rand() % 18 + 1;
	snakex = mx / 2;
	snakey = my / 2;
}
void Draw() {
	cout << "score:" << score << endl << "_______________________" << endl;
	for (int y = 0;y < my;y++)
	{
		for (int x = 0;x < mx;x++)
		{
			if (x == 0 || y == 0 || x == mx - 1 || y == my - 1)
				cout << "#";
			else if (snakex == x && snakey == y)
				cout << "D";
			else if (x == fx && fy == y)
				cout << "f";
			else if ((snakex != x || snakey != y) && (x != fx || fy != y))
				cout << " ";

		}
		cout << endl;
	}
}
void Input() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case'a':
			dir = RIGHT;
			break;
		case'w':
			dir = UP;
			break;
		case'd':
			dir = LEFT;
			break;
		case's':
			dir = DOWN;
			break;
		case'p':
			dir = STOP;
			break;
		default:
			break;
		}
	}
}
void Run() {
	int prex, prey,t;
	switch (dir)
	{
	case RIGHT:
		snakex -= 1;
		break;
	case LEFT:
		snakex += 1;
		break;
	case UP:
		snakey -= 1;
		break;
	case DOWN:
		snakey += 1;
		break;
	}

}
void Furit() {
	if (snakex == fx && snakey == fy)
	{
		score += 1;
		fx = rand() % 18 + 1;
		fy = rand() % 18 + 1;
	}
}
void Logic() {
	if (snakex == 0 || snakex == 20 || snakey == 0 || snakey == 20)
		gameover = true;
		
}
int main() {
	Setup();
	while(!gameover)
	{
		Sleep(100);
		system("cls");
		Input();
		Run();
		Furit();
		Logic();
		Draw();
		
	}
	system("cls");
	cout << "gameover";
}