#include <iostream>
#include <vector>
#include <string>
#include <stack>


using namespace std;

bool chc(string x, string arg = "(){}[]") {
    vector<char> lista;
    for (int i = 0; i < x.length(); i++) {
        int poz = arg.find(x[i]);
            if (poz == string::npos)
            continue;
            if (poz % 2 == 0) {
            lista.push_back(arg[poz + 1]);
            }
            else {
                if (lista.size() == 0 || lista.back() != x[i]) {
                    return false;
                }

                lista.pop_back();
             }
    }
    return lista.size() == 0;
}

int main()
{
    int Z;
    cin >> Z;

    string x = "";
    getline(cin, x);

    do 
    {
        Z--;
        string x = "";
        getline(cin, x);
        bool x = chc(x);
        if (x == true) cout << "tak" << endl;
        else if (x == false) cout << "nie" << endl;
    } while (Z != 0);

    return 0;
}

