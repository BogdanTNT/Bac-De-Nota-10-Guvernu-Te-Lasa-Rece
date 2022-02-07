// diverse_pt_bac.cpp
// Pur si simplu rulezi functile exercitilor in main.

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("bac.txt");

void Impare(int& n)
{
    int cn = 0, p = 1;
    while (n != 0) {
        if (n % 2 == 0)
            cn = (n % 10) * p + cn;
        else
            cn = (n % 10 - 1) * p + cn;
        p = p * 10;
        n = n / 10;
    }
    n = cn;
}

void doi_main()
{
    int a[101][101], n, m, valid = 1;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n / 2; j++)
            if (a[i][j] != a[i][n - 1 - j])
                valid = 0;

    if (valid == 1)
        cout << "Da";
    else
        cout << "Nu";
}

void trei_main()
{
    int n, maxima = 0; 
    ifstream fin("bac.txt");
    while (fin >> n) {
        if (n >= maxima) {
            cout << n << " ";
            maxima = n;
        }
    }
    // shiiiiiii broke
}

int main()
{
    /*int n = 15690;
    Impare(n);
    cout << n;*/
    //doi_main();
    //trei_main();
}

