// diverse_pt_bac.cpp
// Pur si simplu rulezi functile exercitilor in main.

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("bac.txt");

void suma(int n, int& s)
{
    s = 0;
    int f[11] = { 0 };
    while (n != 0)
    {
        f[n % 10]++;
        n = n / 10;
    }
    for (int i = 2; i <= 8; i+= 2)
    {
        if (f[i] > 0)
            s = s + i;
    }
}

void doi_main()
{
    char s[101][101] = { '\0' };
    int n, k;
    cin >> n >> k;
    k--;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        cin.get(s[i], 100);
        cin.get();
    }
    for (int i = 0; i < n; i++)
    {
        if (strstr(s[k], s[i]) == s[k])
            if (k != i)
                cout << s[i] << " ";
    }
}

void trei_main()
{
    int n, nr = 0, ult = 0, c = 0;
    while (fin >> n)
    {
        if (n % 10 == 0)
            nr++;
        else
        {
            if (nr > ult)
            {
                ult = nr;
                c = 1;
            }
            else if (nr == ult)
                c++;
            nr = 0;
        }
    }
    cout << ult << " " << nr;

}

int main()
{
    /*int n = 67638825, nr;
    suma(n, nr);
    cout << nr;*/
    //doi_main();
    trei_main();
}

