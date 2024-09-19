#include "pch.h"
#include<iostream>
using namespace std;

void sortowanie_przez_wstawianie(int n, int* tab)
{
	int pom, j;
	for (int i = 1; i < n; i++)
	{
		pom = tab[i];
		j = i - 1;

		while (j >= 0 && tab[j] > pom)
		{
			tab[j + 1] = tab[j];
			--j;
		}
		tab[j + 1] = pom;
	}
}

int main()
{
	int s;
	cout << "Wprowadz ilosc tablic:";
	cin >> s;

	for (int k = 0; k < s; k++)
	{
		int n, * tab;
		cout << endl << "Podaj ilosc wprowadzonych liczb: ";
		cin >> n;

		tab = new int[n];
		cout << endl << "Podaj elementy: " << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> tab[i];
		}

		sortowanie_przez_wstawianie(n, tab);

		cout << endl << "Wynik:" << endl;
		for (int i = 0; i < n; i++)
			cout << tab[i] << " ";

	}
	cin.ignore();
	cin.get();
	return 0;
}
