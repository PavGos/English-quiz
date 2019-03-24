#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <conio.h>

using namespace std;

string tab_polish[1000];
string tab_english[1000];
int amount = 0;

void input();
void database();
void exam();

void menu()
{
	char choise;
	
	while(true)
	{
		cout << "NAUCZ SIE JEZYKA ANGIELSKIEGO!" << endl;
		cout << "------------------------------------" << endl;
		cout << "1. Przeglad slowek" << endl;
		cout << "2. Dodawanie slowek" << endl;
		cout << "3. Usuwanie slowek" << endl;
		cout << "4. Test" << endl;
		cout << "5. Zamknij program" << endl;
		
		cout << endl;
		choise = getch();
		
		switch(choise)
		{
			case '1': database(); break;
			case '2': input(); break;
			case '3': cout << "Coming soon"; break;
			case '4': exam(); break;
			case '5': exit(0); break;
			case '6': cout << amount;
			default: cout << "Nie ma takiej opcji w menu"; break;
		}
		cout << endl;
		getchar(); getchar();
		system("cls");
	}
}

void input()
{
	int control, i;
	fstream english;
	fstream polish;
	char ATP;
	
	english.open("english.txt", ios::out | ios::app);
	polish.open("polish.txt", ios::out | ios::app);
	
	cout << "Ile slowek chcesz wprowadzic: ";
	cin >> control;
	if(control<=1000)
	{
		for(i=0; i<control; i++)
		{
			cout << "Po anglelsku: ";
			cin >> tab_english[i];
			english << tab_english[i] << endl;
			
			cout << "Polskie znaczenie: ";
			cin >> tab_polish[i];
			polish << tab_polish[i] << endl;
			cout << endl;
		}
		amount += control;
	}
	
	else if(control>1000)
	{
		cout << "Panie! Jele tych slowek!" << endl;
	}
	
	else
	{
		cout << "Panie, co ty mie tu wpisujesz?" << endl;
	}
	
	english.close();
	polish.close();
	
	cout << endl;

	
	for(i=0; i<control; i++)
	{
		cout << tab_english[i];
		cout << " - ";
		cout << tab_polish[i] << endl;
	}
	
	cout << endl;
	cout << "Wcisnij 'R' by wrocic do menu";
	
	ATP = getch();
	
	switch(ATP)
	{
		case 'R': system("cls"); menu(); break;
		default: cout << "'R' wcisnij pajacu!";
	}
	
}

void database()
{
	fstream english;
	fstream polish;
	
	english.open("english.txt", ios::in | ios::app);
	polish.open("polish.txt", ios::in | ios::app);
	
	string line_eng, line_pol;
	
        while(!english.eof() && !polish.eof())
        {
            getline(english, line_eng);
            getline(polish, line_pol);
            cout << line_eng << " - " << line_pol << endl; 
        }
        
        english.close();
        polish.close();
}

void test_1()
{
	fstream english;
	fstream polish;
	
	english.open("english.txt", ios::in);
	polish.open("polish.txt", ios::in);
}

void exam()
{
	char type;
	cout << "1. Z POLSKIEGO NA ANGIELSKI" << endl;
	cout << "2. Z ANGIELSKIEGO NA POLSKI" << endl;
	
	type = getch();
	switch(type)
	{
		case '1': cout << "case 1"; break;
		case '2': cout << "case 2"; break;
	}
}
 

int main()
{

	menu();
	
	return 0;
	system("pause");
}
