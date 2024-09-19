#include "pch.h"
#include<iostream>
#include<cstdlib>

using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++)
	{
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

int main()
{
	int s;
	cout << "Wprowadz ilosc tablic:";
	cin >> s;

	for (int k = 0; k <= s; k++)
	{
		cout << "Wprowadz ilosc wprowadzonych liczb: ";
		int l;
		cin >> l;
		int* arr = new int[l];
		cout << "Wprowadz liczby: ";
		for (int i = 0; i < l; i++) {
			cin >> arr[i];
		}
		int max_sum = maxSubArraySum(arr, l);
		cout << endl << max_sum << " " << "";

		delete[] arr;
	}
	system("PAUSE");
	return 0;
}
