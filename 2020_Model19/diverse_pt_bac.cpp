// diverse_pt_bac.cpp
// Pur si simplu rulezi functile exercitilor in main.

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("bac.txt");

void paritate(int n, int& nr)
{
    nr = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && i % 2 == n % 2)
            nr++;
    }
}

void doi_main()
{
    int n, m, k, da = 0, a[101][101];
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        if (i == k - 1) continue;
        int c = 1;
        for (int j = 0; j < m; j++)
            if (a[i][j] == a[k][j])
                c = 0;
        if (c == 1)
        {
            da = 1;
            i = m;
        }
    }
}

void trei_main()
{
    int n, ult = -1, a = -1;
    while (fin >> n) {
        if (n != ult)
        {
            if (ult % 2 == 0)
                cout << ult << " ";
            ult = n;
        }
    }
}

int main()
{
    /*int n = 20, nr;
    paritate(n, nr);
    cout << nr;*/
    //doi_main();
    trei_main();
}

