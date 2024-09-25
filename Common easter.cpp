#include <iostream>
#include <vector>
#include <string>
using namespace std;


string gregorian_calendar_easter(int year)
{
	//zmienne potrzebne do obliczenia algorytmu
	int a, b, c, d, e, f, g, h, i, k, l, m, p;
	int day;
	int month;

	//modulo to dzielenie z reszta
	//dzielenie calkowite jest bez reszty

	a = year % 19; // rok dzielimy przez modulo 19
	b = year / 100;  // rok dzielimy calkowicie przez 100
	c = year % 100; // rok dzielimy modulo 100
	d = b / 4;  // zmienna b dzielona calkowicie przez 4
	e = b % 4; // zmienna b dzielona przez modulo 4
	f = (b + 8) / 25; // dodajemy b + 8 i dzielimy to calkowicie przez 25
	g = (b - f + 1) / 3; // odejmujemy b od f, dodjaemy 1 i dzielimy calosc calkowicie przez 3
	h = (19 * a + b - d - g + 15) % 30; // mnozymy a przez 19 , dodjaemy b , odejmujemy d i g i dodajemy 15 , calosc dzielona przez modulo 30
	i = (c / 4); // dzielimy c przez 4 calkowicie
	k = c % 4; // c dzielimy przez modulo 4
	l = (32 + (2 * e) + (2 * i) - h - k) % 7; // 32 dodajemy do 2 * e , dodajemy 2 * i  , odejmujemy od tego h i k , calosc dzielimy przez modulo 7
	m = (a + (11 * h) + (22 * l)) / 451; // mnozymy 11 * h i 22 * l ,dodajemy to  plus dodatkowo doddajemy  zmienna a , calosc dzielona calkowicie przez 451
	month = ((h + l - (7 * m) + 114) / 31 ) ; // mnozymy 7 * m dodajemy do tego 114 , h + l dodajemy i odejmujemy od tego rezultat 7*m , calosc dzielona calkowicie przez 31
	day = ((h + l - (7 * m) + 114) % 31) + 1;

	string easterDate = to_string(year) + '.' + to_string(day) + '.' + to_string(month); // budujemy otrzymana date poprzez konkatenacje stringow (dodawanie)
															//funkcja to_string zamienia konwertuje int --> string

	return easterDate;
}

string julian_calendar_easter(int year)
{
	//zmienne potrzebne do realizacji algorytmu
	int a, b, c, d, e;
	int result;
	int day;
	int month;

	a = year % 4;
	b = year % 7;
	c = year % 19;
	d = (19 * c + 15) % 30;
	e = (2 * a + 4 * b - d + 34) % 7;
	month = (d + e + 114) / 31;
	day = ((d + e + 114) % 31) + 14;

	if (month == 3) // jesli miesiac to marzec
	{
		if (day > 31) // i dzien wiekszy od 31
		{
			month++; // zwiekszamy miesiac o 1 czyli bedize kwiecien
			day -= 31; //odejmujemy 31 dni
		}
	}

	if (month == 4) // jesli miesiac to kwiecien 
	{
		if (day >= 31) //  i dzien jest wiekszy rowny 31
		{
			month++; // zwiekszamy miesiac o 1 czyli bedzie maj
			day -= 30; // odejmujemy 30 dni (aby uwzglednic date 1 maj) jesli odejmiemy 31 to zamiast 1 maja bylby 31 kwiecien
		}
	}



	string easterDate = to_string(year) + '.' + to_string(day) + '.' + to_string(month);

	return easterDate;
}


//algorytmy z ktorych korzystalem
//https://en.wikipedia.org/wiki/Computus
//http://mahadevaastro.com/astro/jean_meeus_astronomical_algorithms.pdf

int main()
{

	int number_of_tests = 0;
	cin >> number_of_tests;
	if (number_of_tests < 1 || number_of_tests > 1000) // warunek sprawdzajacy czy podana lczba testow jest prawidlowa
	{
		cout << "Nieprawidlowa liczba testow\n";
	}

	vector<int> tests_values; // wektor przechowujacy wartosci testowe
	int year = 0;
	while (number_of_tests--)
	{
		cin >> year;
		if (year < 1600 || year > 2690)
		{
			cout << "Wartosc spoza zakresu [1600 - 2690]\n";
		}
		else
		{
			tests_values.push_back(year);
		}
	}


	vector<string> results; // wektor przechowujacy wynik
	for (int i = 0; i < tests_values.size(); i++)
	{
		int year = tests_values[i];
			for (int j = year; j < 2690; j++)
			{
				string gregorianEasterDate = gregorian_calendar_easter(j);
				string julianEasterDate = julian_calendar_easter(j);
				if (gregorianEasterDate == julianEasterDate)
				{
					string string_year = gregorianEasterDate.substr(0, 4); // wyciagamy substringa z rokiem
					int largerYear = stoi(string_year);
					if (largerYear > year) // sprawdzamy czy rok w ktorym daty sa rowne jest wiekszy od aktualnego
					{
						results.push_back(string_year); //wstawiamy wynik do wektora
						break; // przerywamy petle
					}
					else
						continue;
				}
			}
	}


	for (auto elem : results)
	{
		cout << elem << '\n';
	}

	
}

