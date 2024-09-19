#include<iostream>

using namespace std;


int max_liczba(int tablica[], int s)
{
	int max = tablica[0];
	for (int i = 1; i < s; i++)
	{
		if (max < tablica[i])
			max = tablica[i];
	}
	return max;
}

void SortC(int A[], int B[], int k, int s)
{
	int i;
	int* C = new int[k + 1];
	for (i = 0; i <= k; i++)
		C[i] = 0;
	for (i = 0; i < s; i++)
		C[(A[i])]++;
	for (i = 1; i <= k; i++)
		C[i] += C[i - 1];
	for (i = s - 1; i >= 0; i--)
	{
		B[(C[(A[i])]) - 1] = A[i];
		C[(A[i])]--;
	}
	delete[] C;
}

int main()
{
	int Z, n, i;
	cin >> Z;

	while (Z--)
	{
		cout << endl;
		cin >> n;
		cout << endl;
		int* tab = new int[n];
		int* tabw = new int[n];

		for (i = 0; i < n; i++)
		{
			cin >> tab[i];
		}

		int k = max_liczba(tab, n);
		SortC(tab, tabw, k, n);
		cout << endl;
		for (i = 0; i < n; i++)
			cout << tabw[i] << " ";
		cout << endl;

		delete[] tab;
		delete[] tabw;
	}

	return 0;
}