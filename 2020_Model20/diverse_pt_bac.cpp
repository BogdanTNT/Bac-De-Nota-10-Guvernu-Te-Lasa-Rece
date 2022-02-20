// diverse_pt_bac.cpp
// Pur si simplu rulezi functile exercitilor in main.

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("bac.txt");

int transformareBaza10(int b, int n)
{
    int s = 0, k = 1;
    s = n % 10 * 1;
    n = n / 10;
    while (n != 0)
    {
        k = k * b;
        s = s + k * (n % 10);
        n = n / 10;
    }
    return s;
}

void doi_main()
{
    char sir[101] = { '\0' }, nou[101] = { '\0' };
    cin.get(sir, 100);
    char* p = strtok(sir, " ");
    while (p != NULL)
    {
        if (strstr(",", p) != NULL)
        {
            char cop[101];
            strcpy(p, cop);
            int s = strlen(p) - strlen(strstr(",", p));
            for (int i = 0; i < s; i++)
                nou[strlen(nou)] = cop[i];
        }
        else
            strcat(nou, p);
        strcat(nou, " ");
        p = strtok(NULL, " ");
    }
    strcpy(nou, sir);
    cout << sir;
}

void trei_main()
{
    int suma = 0, ult = 0, n, p = -1;
    while (fin >> n)
    {
        if (n % 2 != p)
        {
            p = n % 2;
            if (suma > ult)
                ult = suma;
            suma = n;
        }
        else
            suma = suma + n;
    }
    if (ult < suma)
        ult = suma;
    cout << ult;

}

int main()
{
    //cout << transformareBaza10(2, 10010);
    //doi_main();
    //trei_main();
}

