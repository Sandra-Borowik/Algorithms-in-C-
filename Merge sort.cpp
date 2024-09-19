#include <iostream>
using namespace std;
void Merge(int*, int, int, int);
int w;


void Merge(int* tab, int lewy, int prawy, int m)
{
    int i, j, k, c[50];

    i = lewy;
    k = lewy;
    j = m + 1;

    while (i <= m && j <= prawy) {
        if (tab[i] < tab[j]) {
            c[k] = tab[i];
            k++;
            i++;
        }
        else {
            c[k] = tab[j];
            k++;
            j++;
        }
    }
    while (i <= m) {
        c[k] = tab[i];
        k++;
        i++;
    }
    while (j <= prawy) {
        c[k] = tab[j];
        k++;
        j++;
    }
    for (i = lewy; i < k; i++) {
        tab[i] = c[i];
    }
}

void MergeSort(int* tab, int lewy, int prawy)
{
    w++;
    int m;
    if (lewy < prawy) {
        m = (lewy + prawy) / 2;
        MergeSort(tab, lewy, m);
        MergeSort(tab, m + 1, prawy);
        Merge(tab, lewy, prawy, m);
    }
}


int main()
{
    int tab[30], num, Z;

    cin >> Z;

    for (int j = 0; j < Z; j++) {
        cin >> num;

        for (int i = 0; i < num; i++) {
            cin >> tab[i];
        }
        w = 0;
        MergeSort(tab, 0, num - 1);

        for (int i = 0; i < num; i++)
        {
            cout << tab[i] << " ";
        }
        cout << "\nLiczba wywolan funkcji MargeSort = " << w << endl;
    }

    return 0;
}