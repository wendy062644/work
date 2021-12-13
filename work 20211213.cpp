#include<iostream>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<iomanip>
using namespace std;
void Set(int x, int y);
void Calculate(string print){
	float num[5] = {0};
	int numfloat[5] = {0}, n = 0, count[8] = {0} , f = 1; // 1 = 除, 2 = 加, 3 = 乘 , 4 = 減 
	long long tt = 0;
	for(int a = 0; print.length() > a; a++)
	{
		if(f&&print[a] >= '0'&&print[a] <= '9'){
			num[n] = num[n]*10 + print[a]-48;
		}
		else if(!f&&print[a] >= '0'&&print[a] <= '9'){
			numfloat[n] = numfloat[n]*10 + print[a]-48;
		}
		else if(print[a] == '+'||print[a] == '-'||print[a] == '/'||print[a] == '*'){
			switch(print[a]){
				case 47:
					count[n] = 1; //除 
					break;
				case 43:
					count[n] = 2; //加 
					break;
				case 42:
					count[n] = 3; //乘 
					break;
				case 45:
					count[n] = 4; //減 
					break;
			}
			n++;
			f = 1;
		}
		else if(print[a] == '.'){
			f = 0;
		}
		if(a == print.length()-1){
			tt = num[0];
			for(int i = 0; n > i; i++)
			{
				if(count[i] == 1){
					tt = tt / num[i+1];
				}
				else if(count[i] == 2){
					tt = tt + num[i+1];
				}
				else if(count[i] == 3){
					tt = tt * num[i+1];
				}
				else if(count[i] == 4){
					tt = tt - num[i+1];
				}
			}
			Set(4, 2);
			cout << setw(15) << tt;
		}
	}
}
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
				case 46:
					print = print + '.';
					break;
				case 61:
					Calculate(print);
					break;
			}
			if(num != 61&&num != )
			{
				Set(4, 2);
				cout << setw(15) << print;
			}
		}
		Sleep(100);
	}
}
void Set(int x, int y){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(hOut, pos);
}
