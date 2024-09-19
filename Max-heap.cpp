#include <stdio.h> 
#include <limits.h> 
#include <iostream>

using namespace std;

bool isHeap(int tab[], int i, int n)
{

    if (i > (n - 2) / 2) {
        return true;
    }

    if (tab[i] >= tab[2 * i + 1] && tab[i] >= tab[2 * i + 2] &&
       isHeap(tab, 2 * i + 1, n) && isHeap(tab, 2 * i + 2, n))
        return true;

    return false;
}


int main()
{
    int Z, n;
    int* tab;

    cin >> Z;

    do {
        Z--;

        cin >> n;

        tab = new int[n];

        for (int i = 0; i < n; i++) {
            cin >> tab[i];
        }

        int l = sizeof(tab) / sizeof(int) - 1;

        isHeap(tab, 0, n) ? printf("TAK") : printf("NIE");
        cout << endl;
    } while (Z>0);

    return 0;
}