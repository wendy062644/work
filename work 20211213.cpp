#include<iostream>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<iomanip>
using namespace std;
void Set(int x, int y);
int main(){
	char p[3] = {'/', 'x', '-'};
	string print;
	int n = 7, m = 0;
	cout << " ---------------------" << endl;
	for(int i = 0; 3 > i; i++)
	{
		cout << " | ";
		if(!(i%2)){
			for(int j = 0; 17 > j; j++)
			{
				cout << "-";
			}
		}
		else{
			cout << "|               |";
		}
		cout << " |" << endl;
	}
	for(int i = 0; 9 > i; i++)
	{
		cout << " | ";
		if(i == 7){
			cout << "| 0 | . | = | + |";
		}
		else if(i%2)
		{
			for(int j = 0; 17 > j; j++)
			{
				if(!(j%4)){cout << "|";}
				else if(j == 14){cout << p[m]; m++;}
				else if(!((j+2)%4)){cout << n; n++;}
				else {cout << " ";}
			}
			n -= 6;
		}
		else{
			for(int j = 0; 17 > j; j++)
			{
				if(!(j%4)){cout << " ";}
				else{cout << "-";}
			}
		}
		cout << " |" << endl;
	}
	cout << " ---------------------" << endl << endl << " Press Space to Clear";
	while(1)
	{
		if(_kbhit())
		{
			char num = getch();
			if(print.length() >= 15){
				if(num == 32){print.clear(); Set(4, 2); cout << setw(15) << print; continue;}
				else{continue;}
			}
			switch(num){
				case 48:
					print = print + '0';
					break;
				case 49:
					print = print + '1';
					break;
				case 50:
					print = print + '2';
					break;
				case 51:
					print = print + '3';
					break;
				case 52:
					print = print + '4';
					break;
				case 53:
					print = print + '5';
					break;
				case 54:
					print = print + '6';
					break;
				case 55:
					print = print + '7';
					break;
				case 56:
					print = print + '8';
					break;
				case 57:
					print = print + '9';
					break;
				case 47:
					print = print + '/';
					break;
				case 43:
					print = print + '+';
					break;
				case 42:
					print = print + 'x';
					break;
				case 45:
					print = print + '-';
					break;
			}
			Set(4, 2);
			cout << setw(15) << print;
		}
		Sleep(100);
	}
}
void Set(int x, int y){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(hOut, pos);
}
