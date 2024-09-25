#include <iostream>
#include <set>
#include <vector>
using namespace std;

int Square(int n) // funkcja wykonujaca obliczenia 
{
	int result = 0;
	while (n)
	{
		result += (n % 10) * (n % 10);
		n /= 10;
	}
	return result;
}
bool isHappyNumber(int n)//funkcja sprawdzajaca czy liczba jest wesola
{
	std::set<int> st;
	while (1)
	{
		n = Square(n);
		if (n == 1)
			return true;
		if (st.find(n) != st.end())
			return false;
		st.insert(n);
	}
}
int main()
{
	int number_of_tests = 0; // zmienna przechowujaca liczbe testow
	cin >> number_of_tests;
	if (number_of_tests < 1 || number_of_tests > 1000) //sprawdzenie czy liczba testow nie przekracza wartosci
	{
		cout << "Nieodpowiednia liczba testow\n";
	}
	vector<int> tests; // wektor ktory przechowuje liczby do testowania
	int test_value = 0; // zmienna przechowujaca wartosc ktora testujemy
	while (number_of_tests--) // while wykonuje sie dopoki number_of_tests nie osiagnie wartosci 0
	{
		cin >> test_value;
		if (test_value < 0 || test_value > 1000000) // sprawdzamy czy podana wartosc miesci sie w odpowiednim zakresie
		{
			cout << "Wartosc spoza zakresu [0 - 10^6]\n";
			break; // jezli nie przerywamy petle i wypisujemy komunikat
		}
		else
		{
			tests.push_back(test_value); // wstawiamy wartosc do wektora
		}
	}

	vector<pair<int, int>> results; //wektor przechowujacy pary wynikow
	for (int i = 0; i < tests.size(); i++)
	{
		int number = tests[i];
		for (number; number < 1000000; number++)
		{
			if (isHappyNumber(number) && isHappyNumber(number + 1)) // jesli aktualna i kolejna liczba jest wesola 
			{

				results.push_back(make_pair(number, number + 1)); // wstawiamy pare tych liczb do wektora
				break;
			}
		}
	}	

	for (auto elem : results) // wypisujemy pary liczb ktore spelnialy zalozenia
	{
		cout << elem.first << " " << elem.second << '\n';
	}
}