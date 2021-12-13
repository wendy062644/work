#include<iostream>
#include<windows.h>

using namespace std;
void Set(int x, int y);
int main(){
	char p[3] = {'/', 'x', '-'}; 
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
	cout << " ---------------------" << endl;
	while(1)
	{
		
	}
}
void Set(int x, int y){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(hOut, pos);
}
