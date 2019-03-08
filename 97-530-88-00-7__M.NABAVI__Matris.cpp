//University of Qom
//Faculty of Engineering
//Department of Computer and Information Technology

//Student: Mortaza Nabavi	ID: 97 530 88 00 7
//Prof: M.A. Ahmadi

//Introduction: This Program recives a matris which the user will determine number of columns and rows
//Then the matris will sorted twice, Horizontaly and Verticaly.
//First user should enter the size of matris, then program asks to enter the indexs.
//The user can edit the matris.

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void print(string s, int r, int sl) {
	string border = "    ______________________________________________\n   |                                              |\n   |                                              |\n   |                                              |\n   |______________________________________________|\n";
	for (int i = 1; i <= r; i++) {
		cout << s;
		Sleep(sl);
		system("cls");
		cout << border;
		Sleep(sl);
		system("cls");
	}
}

void intro() {
	string uni = "    ______________________________________________\n   |              University of Qom               |\n   |            Faculty of Engineering            |\n   |  Department of Computer and IT Engineering   |\n   |______________________________________________|\n";
	string me = "    ______________________________________________\n   |              Prof: M.A. Ahmadi               |\n   |           Student: Mortaza Nabavi            |\n   |           STU. ID: 97 530 88 00 7            |\n   |______________________________________________|\n";
	string border = "    ______________________________________________\n   |                                              |\n   |                                              |\n   |                                              |\n   |______________________________________________|\n";
	for (int i = 0; i < uni.length(); i++) {
		cout << uni[i];
		Sleep(30);
	}

	Sleep(2000);
	system("cls");
	print(uni, 15, 40);
	system("cls");
	for (int i = 0; i < 15; i++) {
		system("cls");
		cout << border;
		Sleep(20);
		system("cls");
		cout << uni;
		Sleep(20);
		system("cls");
		cout << me;
	}
	system("cls");
	print(me, 15, 40);
	cout << me;
}

int main() {
	char ch;

	intro();
	string wait = "\n\nEnter any key to continue ...";
	for (int i = 0; i < wait.length(); i++) {
		cout << wait[i];
		Sleep(60);
	}
	getch();
	while (true != !true) {
	start_over:
		system("cls");
		cout << "A matris is needed. I need number of Columns ans Rows.\n";
	enter_r:
		cout << "Enter Number of ROW: ";
		int r;
		cin >> r;

		if (r < 1) {
			system("cls");
			cout << "Error! you should enter integer number which is more than 0.\nTry again.\n";
			goto enter_r;
		}

		system("cls");
	enter_c:
		cout << "Cool!\nYou entered " << r << " as number of Rows.\nNow enter Number of Column: ";
		int c;
		cin >> c;

		if (c < 1) {
			system("cls");
			cout << "Error! you should enter integer number which is more than 0.\nTry again.\n";
			goto enter_c;
		}

		double arr[r][c];

		system("cls");
		cout << "Thats Great. everything is going well.\n" << r << "*" << c << " matris is created.\nNow I need the items and indexes.\n";

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				cout << "Pleas Enter index: [" << i + 1 << "," << j + 1 << "] :";
				cin >> arr[i][j];
				system("cls");
			}

		system("cls");
	ch6:
		cout << "The matris is:\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cout << arr[i][j] << "\t";
			cout << endl;
		}

	ch3:
		cout << "\n\nChoose Option:\n1. Matris is OK and continue.\n2. I want to change the matris.\n";
		cin >> ch;
		if (ch == '1') {}
		else if (ch == '2') {
			system("cls");
		ch2:
			cout << "\n\nChoose Option:\n1. Change the whole matris.\n2. Change some indexes.\n";
			cin >> ch;
			if (ch == '1')
				goto start_over;
			else if (ch == '2')
				while (1) {
				ch4:
					cout << "You should order in this way: Row, Column, New Value.\nFor example for changing value for [1,1] enter this: 1 1 5. Value of that index will change to 5.";
					int x, y, z;
					cin >> x >> y >> z;
					if (x > r || y > c) {
						cout << "That index is not existed. Try Again:";
						goto ch4;
					}
					else
						arr[x - 1][y - 1] = z;
					cout << "Done! [" << x << "," << y << "] = " << z << "\n\nTo continue press 1 to exit enter other key.";
					cin >> ch;
					if (ch != '1')
						goto ch6;
				}
			else {
				cout << "Enter Correct Option. Try again:\n";
				goto ch2;
			}
		}
		else {
			cout << "Enter Correct Option. Try again:\n";
			goto ch3;
		}

		double arr1[r][c];
		double arr2[r][c];

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				arr1[i][j] = arr[i][j];
				arr2[i][j] = arr[i][j];
			}

		system("cls");

		cout << "The matris is:\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cout << arr[i][j] << "\t";
			cout << endl;
		}

		ch = '1';
	ch7:

		if (ch == '1')
			cout << "\nThe Martis is Sorted Ascending, Horiznotaly:\n";
		if (ch == '2')
			cout << "\nThe Martis is Sorted Decending, Horiznotaly:\n";

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				for (int k = 0; k < c; k++)
				{
					if (ch == '1') {
						if (arr1[i][j] <= arr1[i][k]) {
							double a = arr1[i][k];
							arr1[i][k] = arr1[i][j];
							arr1[i][j] = a;
						}
					}
					else
						if (arr1[i][j] >= arr1[i][k]) {
							double a = arr1[i][k];
							arr1[i][k] = arr1[i][j];
							arr1[i][j] = a;
						}
				}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cout << arr1[i][j] << "\t";
			cout << endl;
		}

		if (ch == '1') {
			ch = '2';
			goto ch7;
		}

		ch = '3';
	ch8:

		if (ch == '3')
			cout << "\nThe Martis is Sorted Ascending, Verticaly:\n";
		if (ch == '4')
			cout << "\nThe Martis is Sorted Decending, Verticaly:\n";

		for (int i = 0; i < c; i++)
			for (int j = 0; j < r; j++)
				for (int k = 0; k < r; k++) {
					if (ch == '3') {
						if (arr2[j][i] <= arr2[k][i]) {
							double a = arr2[j][i];
							arr2[j][i] = arr2[k][i];
							arr2[k][i] = a;
						}
					}
					else
						if (arr2[j][i] >= arr2[k][i]) {
							double a = arr2[j][i];
							arr2[j][i] = arr2[k][i];
							arr2[k][i] = a;
						}
				}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cout << arr2[i][j] << "\t";
			cout << endl;
		}

		if (ch == '3') {
			ch = '4';
			goto ch8;
		}

		cout << "\n\nTo try another matris press 1. to exit press other keys. ";
		cin >> ch;
		if (ch == '1')
			goto start_over;
		else break;
	}
	system("cls");
	cout << "Prof.: M. A. Ahmadi  ma.ahmadi@qom.ac.ir\nStudent: Mortaza Nabavi\nID: 97 530 88 00 7\nnabavi.mrtz@gmail.com";
	Sleep(10000);
}
