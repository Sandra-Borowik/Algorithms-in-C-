
#include <iostream>

using namespace std;

int pot(int x, int n) {
	int y = 1;

	for (int i = 0; i < n; i++) {
		y = y * x;
	}
	return y;
}

int wielomian1(int n, int x, int a[]) {
	int w = 0;
	for (int i = 0; i < n + 1; i++) {
		w += a[i] * pot(x, i);
	}
	return w;
}

int wielomian2(int n, int x, int a[]) {
	int w = 0;
	for (int i = n; i >= 0; i--) {
		w = w * x + a[i];
	}
	return w;
}


int main()
{
	int n, x;
	int a[11];
	int lm1, lm2;

	cin >> n;
	cin >> x;

	lm1 = ((n + 1) * n) / 2;
	lm2 = n;

	for (int i = 0; i < n + 1; i++) {
		cin >> a[i];
	}


	cout << "Wersja 1: W(x) = " << wielomian1(n, x, a) << ", liczba mnozen = " << lm1 << endl;
	cout << "Wersja 2: W(x) = " << wielomian2(n, x, a) << ", liczba mnozen = " << lm2 << endl;
	return 0;
}

