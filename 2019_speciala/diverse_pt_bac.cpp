// diverse_pt_bac.cpp
// Pur si simplu rulezi functile exercitilor in main.

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("bac.txt");

int Egal(int n)
{
    int c = 0;
    while (n != 0) {
        if (n % 2 == 1) {
            if (c == 0)
                c = n % 10;
            else if (n % 10 != c)
                return 0;
        }
        n = n / 10;
    }
    return 1;
}

void doi_main()
{
    char sir[10];
    int n, gasit = 0;
    cin.get(sir, 101);
    cin.get();
    cin >> n;
    char* p = strtok(sir, " .,");
    while (p != NULL) {
        if (strlen(p) == n) {
            cout << p << " ";
            gasit = 1;
        }
        p = strtok(NULL, " .,");
    }
    if (gasit == 0)
        cout << "nu exista";
}

int x, y, z;
int functie(int n)
{
    if (n == 1) return x;
    if (n == 2) return y;
    if (n == 3) return z;
    return functie(n - 1) + functie(n - 2) - functie(n - 3);
}

void trei_main()
{
    int n;
    cin >> n >> x >> y >> z;
    ofstream fout("bac.txt");
    for (int i = n; i > 3; i--)
        fout << functie(i) << " ";
    if (n >= 3)
        fout << z << " " << y << " " << x;
    else if (n == 2)
        fout << y << " " << x;
    else if (n == 1)
        fout << x;
}

int main()
{
    //doi_main();
    //trei_main();
}

