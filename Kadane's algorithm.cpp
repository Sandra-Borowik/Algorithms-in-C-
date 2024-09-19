#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

string najdluzszyPodciag(string str1, string str2) {
	int n = str1.length();
	int m = str2.length();

	int** tab_pom = new int* [n + 1];

	for (int i = 0; i <= n; i++)
	{
		tab_pom[i] = new int[m + 1];
	}

	int wynik = 0, poz = 0;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				tab_pom[i][j] = 0;
			}
			else if (str1[i - 1] == str2[j - 1])
			{
				tab_pom[i][j] = tab_pom[i - 1][j - 1] + 1;
				if (tab_pom[i][j] > wynik)
				{
					wynik = tab_pom[i][j];
					poz = i;
				}
			}
			else
			{
				tab_pom[i][j] = 0;
			}
		}
	}

	string w = "";

	for (int i = wynik; i > 0; i--)
	{
		w += str1[poz - i];
	}

	for (int i = 0; i <= n; i++)
	{
		delete tab_pom[i];
	}

	delete tab_pom;
	return w;
}

int main() {

	int s;
	cout << "Wprowadz ilosc sprawdzan:";
	cin >> s;

	for (int k = 0; k < s; k++)
	{
		string str1, str2;
		cout << endl << "Podaj pierwsze slowo:" << endl;
		cin >> str1;
		cout << "Podaj drugie slowo:" << endl;
		cin >> str2;
		string w = najdluzszyPodciag(str1, str2);
		if (w == "") {
			cout << "Wyrazy nie maja wspolnej czesci";
		}
		else {
			cout << "Wynik: " << w << endl;
		}
	}
	system("pause");
	return 0;
}