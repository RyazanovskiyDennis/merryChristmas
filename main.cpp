#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;
/*
	merry
	christmas

	 __  __   _______   ______   ______  __    __
	|  \/  | |  _____| |  __  \	|  __  \ \ \  / /
	|      | | |____   | |__| |	| |__| |  \ \/ /
	| |\/| | |  ____|  |  ____/	|  ____/   |  |
	| |  | | | |_____  |  __ \	|  __ \    |  |
	|_|  |_| |_______| |_|  \_| |_|  \_|   |__|

	 ______   __   __   ______   ______   ______   ______   __  __   ______   ______ 
	/ _____| |  | |  | |  __  \ |_    _| /   ___| |_    _| |  \/  | |  __  | /   ___|
	| |      |  |_|  | | |__| |   |  |   |  |__     |  |   |      | | |__| | |  |__   
	| |		 |   _   | |  ____/   |  |   \___  \    |  |   | |\/| | |  __  | \___  \ 
	| |____	 |  | |  | |  __ \	 _|  |_   ___|  |   |  |   | |  | | | |  | |  ___|  |
	\______| |__| |__| |_|  \_| |______| |_____/    |__|   |_|  |_| |_|  |_| |_____/ 


*/
void writeTree(HANDLE h, int a)
{
	cout << "  ";
	if (a < 10)
	{
		for (int i(a); i < 13; i++) cout << ' ';
		for (int i(0); i < 2 * a + 1; i++)
		{
				SetConsoleTextAttribute(h, rand() % 15 + 1);
				cout << '*';
		}
		for (int i(a); i < 13; i++) cout << ' ';
    }
	else
		{
		   SetConsoleTextAttribute(h, 2);
		   cout << "           |||||           ";
		}
	cout << "  ";
}
int main(int argc, char*argv[])
{
	COORD pos = {0, 10};
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	string mc[13] = {
	" __  __   _______   ______   ______  __    __",
	"|  \\/  | |  _____| |  __  \\ |  __  \\ \\ \\  / /",
	"|      | | |____   | |__| | | |__| |  \\ \\/ /",
	"| |\\/| | |  ____|  |  ____/ |  ____/   |  |",
	"| |  | | | |_____  |  __ \\  |  __ \\    |  |",
	"|_|  |_| |_______| |_|  \\_| |_|  \\_|   |__|",
	"",
	" ______   __   __   ______   ______   ______   ______   __  __   ______   ______",
	"/ _____| |  | |  | |  __  \\ |_    _| /   ___| |_    _| |  \\/  | |  __  | /   ___|",
	"| |      |  |_|  | | |__| |   |  |   |  |__     |  |   |      | | |__| | |  |__",
	"| |      |   _   | |  ____/   |  |   \\___  \\    |  |   | |\\/| | |  __  | \\___  \\",
	"| |____  |  | |  | |  __ \\   _|  |_   ___|  |   |  |   | |  | | | |  | |  ___|  |",
	"\\______| |__| |__| |_|  \\_| |______| |_____/    |__|   |_|  |_| |_|  |_| |_____/"
	};

	
	int a;
	while (!_kbhit())
	{
		SetConsoleCursorPosition(hConsole, pos);
		for (int i(0); i < 13; i++) 
		{
			writeTree(hConsole, i);
			SetConsoleTextAttribute(hConsole, rand()%15+1);
			cout << mc[i] << endl; 
		}
		Sleep(200);
	}
	return 0;
}