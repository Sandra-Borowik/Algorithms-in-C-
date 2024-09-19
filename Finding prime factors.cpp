
#include <iostream>
#include <cmath>
using namespace std;

void factors(unsigned n){
    unsigned g, i;
    g = sqrt(n);

    for (i = 2; i <= g; i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }

        if (n == 1)
        {
            cout << endl;
            return;
        }
    }
    cout << n << endl;
}

int main()
{
    unsigned n;
    cin >> n;

    while (n != 0){
        factors(n);
        cin >> n;
    }
}