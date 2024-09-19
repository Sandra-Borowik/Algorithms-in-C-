#include <iostream>
using namespace std;

int main()
{
    int input;                                      
    int n;                                         
    int k;                                         
    int c[10];                                      
    
    do {

        cin >> input;                               

        if (input != 0) {                           

            k = 0;                                 
            n = input;                              

            while (n > 0){                          
                c[k] = n % 10;                      
                n /= 10;                            
                k++;                                
            }

            cout << input << ":";                   

            for (int i = 0; i < k; i++)
            {
                cout << " " << c[i];                
            }

            cout << " #";                           

            for (int i = k - 1; i >= 0; i--)
            {
                cout << " " << c[i];                
            }

            cout << endl;                           
        }

    } while (input != 0);                           

    return 0;
}