// Lab 1-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iomanip>
using namespace std;
//check win
int win(int[6][7], int&);
//display
void display(int[6][7]);
//set turn player1
void turn_p1(int[6][7], int& x, int& y, int& a);
//set turn player2
void turn_p2(int[6][7], int& s, int& x, int& y, int& a);
//set colum and row
const int colum = 7, row = 6;

int main()
{
    std::cout << "Hello World!\n";


	//set variable
	int x, y, s = 1;
	int n[row][colum] = {};
	int a = 5;
	//create table
	display(n);
	do {
		//turn player1
		turn_p1(n, x, y, a);

		//show game table 
		display(n);

		//check is win before player2 start
		win(n, s);
		//if not win s=1,but win s=0.
		//and if not win turn player2
		turn_p2(n, s, x, y, a);
		//display game table
		display(n);
		//check win 
		win(n, s);

	} while (s == 1);


	system("pause");

	return 0;

}

int win(int n[6][7], int& s) {
	int P1 = 0, P2 = 0;
	P1 = P2 = 0;
	cout << endl;
	//Horizontal conditions
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= 5; j++) {
			//if n[j][i] == 1 in 4 time player1 win and return s=0
			if (n[j][i] == 1) {
				P2 = 0;
				P1++;
				if (P1 == 4) {
					cout << "************************************" << endl;
					cout << "----------- Player1 win ------------" << endl;
					return s = 0;
				}
			}
			//if n[j][i] == 2 in 4 time player2 win and return s=0
			else if (n[j][i] == 2) {
				P1 = 0;
				P2++;
				if (P2 == 4) {
					cout << "************************************" << endl;
					cout << "----------- Player2 win ------------" << endl;
					return s = 0;
				}
			}
			else {
				P1 = P2 = 0;
			}
		}
	}
	P1 = P2 = 0;
	//Vertical conditions
	//if player1 ==1 4 time in vertical player1 win and return s=0
	for (int k = 0; k < 7; k++) {
		for (int l = 0; l < 6; l++) {
			if (n[k][l] == 1) {
				if (n[k][l + 1] == 1)
					if (n[k][l + 2] == 1) {
						if (n[k][l + 3] == 1) {
							cout << "************************************" << endl;
							cout << "----------- Player1 win ------------" << endl;
							return s = 0;
						}
					}
			}
			//for player2
			else if (n[k][l] == 2) {
				if (n[k][l + 1] == 2) {
					if (n[k][l + 2] == 2) {
						if (n[k][l + 3] == 2) {
							cout << "************************************" << endl;
							cout << "----------- Player2 win ------------" << endl;
							return s = 0;
						}
					}
				}
			}
		}
	}
	//Right Oblique conditions
	//if player1 ==1 4 time in right oblique player1 win and return s=0
	for (int t = 0; t < 7; t++) {
		for (int u = 0; u < 6; u++) {
			if (n[t][u] == 1) {
				if (n[t - 1][u + 1] == 1 && t - 1 >= 0 && u + 1 <= 7) {
					if (n[t - 2][u + 2] == 1 && t - 2 >= 0 && u + 2 <= 7) {
						if (n[t - 3][u + 3] == 1 && t - 3 >= 0 && u + 3 <= 7) {
							cout << "************************************" << endl;
							cout << "----------- Player1 win ------------" << endl;
							return s = 0;
						}
					}
				}
			}
			//for player2
			else if (n[t][u] == 2) {
				if (n[t - 1][u + 1] == 2 && t - 1 >= 0 && u + 1 <= 7) {
					if (n[t - 2][u + 2] == 2 && t - 1 >= 0 && u + 1 <= 7) {
						if (n[t - 3][u + 3] == 2 && t - 1 >= 0 && u + 1 <= 7) {
							cout << "************************************" << endl;
							cout << "----------- Player2 win ------------" << endl;
							return s = 0;
						}
					}
				}
			}
		}
	}
	//Left oblique conditions
	//if player1 ==1 4 time in left oblique player1 win and return s=0
	for (int t = 0; t < 7; t++) {
		for (int u = 0; u < 6; u++) {
			if (n[t][u] == 1) {
				if (n[t + 1][u + 1] == 1 && t + 1 >= 0 && u + 1 <= 7) {
					if (n[t + 2][u + 2] == 1 && t + 2 >= 0 && u + 2 <= 7) {
						if (n[t + 3][u + 3] == 1 && t + 3 >= 0 && u + 3 <= 7) {
							cout << "************************************" << endl;
							cout << "----------- Player1 win ------------" << endl;
							return s = 0;
						}
					}
				}
			}
			//for player2
			else if (n[t][u] == 2) {
				if (n[t + 1][u + 1] == 2 && t + 3 >= 0 && u + 3 <= 7) {
					if (n[t + 2][u + 2] == 2 && t + 3 >= 0 && u + 3 <= 7) {
						if (n[t + 3][u + 3] == 2 && t + 3 >= 0 && u + 3 <= 7) {
							cout << "************************************" << endl;
							cout << "----------- Player2 win ------------" << endl;
							return s = 0;

						}
					}
				}
			}
		}
	}
}

void display(int n[6][7]) {
	//create table

	for (int j = 0; j <= 5; j++) {
		for (int i = 0; i <= 6; i++) {
			//if n[i][j] = 0 ,show space.
			if (n[j][i] == 0) {
				cout << setw(3) << "[" << " " << "]";

			}
			//if n[i][j] = 1 ,show * ,It is player 1
			else if (n[j][i] == 1) {
				cout << setw(3) << "[" << "*" << "]";

			}
			//if n[i][j] = 2 ,show # ,It is player 2
			else {
				cout << setw(3) << "[" << "#" << "]";

			}
		}
		cout << endl;
	}
	//set show display for beautiful.
	cout << "----------------------------------------" << endl;
	cout << setw(4) << "1" << setw(5) << "2" << setw(5) << "3" << setw(5) << "4" << setw(5) << "5" << setw(5) << "6" << setw(5) << "7";
	cout << endl;


}

void turn_p2(int n[6][7], int& s, int& x, int& y, int& a) {
	//if not win s=1,but win s=0.
	if (s == 1) {
		//set check1 for check is row full for player1
		int check2 = 1;
		while (check2 == 1) {
			cout << "Player 2  play : ";
			//get colum
			cin >> y;
			//get true colum
			x = y - 1;
			// a = row
			a = 5;
			//if row on top = 0 do it!
			if (n[0][x] == 0) {
				//if n[a][x] = 0 get # and set new check2
				if (n[a][x] == 0) {
					n[a][x] = 2;
					check2 = 0;
				}
				else {
					while (a >= 0) {
						//loop row search for n[a][x] = 0 and set new check2
						if (n[a - 1][x] == 0) {
							n[a - 1][x] = 2;
							check2 = 0;
							break;
						}
						a--;
					}
				}
			}
			else {
				cout << "Column  is full !! Pls try again..." << endl;
			}

		}
	}


}
void turn_p1(int n[6][7], int& x, int& y, int& a) {

	//set check1 for check is row full for player1
	int check1 = 1;
	while (check1 == 1) {

		cout << "Player 1  play : ";
		//get colum
		cin >> y;
		// set true colum
		x = y - 1;
		//a = row
		a = 5;
		//if n[0][x] = 0  do it
		if (n[0][x] == 0) {
			//if n[a][x] = 0 get * and set new check1
			if (n[a][x] == 0) {
				n[a][x] = 1;
				check1 = 0;
			}
			else {
				while (a >= 0) {
					//loop row search for n[a][x] = 0 and set new check1
					if (n[a - 1][x] == 0) {
						n[a - 1][x] = 1;
						check1 = 0;
						break;
					}
					a--;
				}

			}

		}
		//else that row is full 
		else {
			cout << "Column  is full !! Pls try again..." << endl;

		}

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
