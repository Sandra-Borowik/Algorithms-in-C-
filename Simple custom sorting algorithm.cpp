#include <iostream>
#include <queue>
using namespace std;


int Wskaz(queue<int>& q, int sortedIndex){
    int min_indeks = -1;
    int min_wartosc = INT_MAX;
    int n = q.size();
    for (int i = 0; i < n; i++){
        int curr = q.front();
        q.pop();   
        if (curr <= min_wartosc && i <= sortedIndex){
            min_indeks = i;
            min_wartosc = curr;
        }
        q.push(curr);                        
    }
    return min_indeks;
}

void WstawMinNaKoniec(queue<int>& q, int min_index){
    int min_wartosc;
    int n = q.size();
    for (int i = 0; i < n; i++){
        int curr = q.front();
        q.pop();
        if (i != min_index) {
            q.push(curr);
        }
        else {
            min_wartosc = curr;
        }
    }
    q.push(min_wartosc);
}

void SortujKolejke(queue<int>& q)
{
    for (int i = 1; i <= q.size(); i++)
    {
        int min_indeks = Wskaz(q, q.size() - i);
        WstawMinNaKoniec(q, min_indeks);
    }
}

int main()
{
    int Z, liczba, ilosc;
    queue<int> q;
    cin >> Z;

    do {
        Z--;

        cin >> ilosc;
        for (int i = ilosc; i >= 1; i--) {
            cin >> liczba;

            q.push(liczba);
        }

        SortujKolejke(q);

        while (q.empty() == false)
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    } while (Z != 0);

    return 0;
}

