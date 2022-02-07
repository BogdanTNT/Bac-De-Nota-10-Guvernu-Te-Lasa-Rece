// 2019_simulare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void inserare(int& n)
{
    int cn = 0, ult = -1, pen = -1;
    while (n != 0) {
        ult = n % 10;
        if (pen != -1) {
            if (pen > ult)
                cn = cn * 10 + pen - ult;
            else
                cn = cn * 10 + ult - pen;
        }
        pen = ult;
        cn = cn * 10 + pen;
        n = n / 10;
    }
    while (cn != 0) {
        n = n * 10 + cn % 10;
        cn = cn / 10;
    }
}

void doi_main()
{
    char s[101] = { '\0' }, nou[101] = { '\0' };
    cin.get(s, 100);
    char* p = strtok(s, " ,.");
    while (p != NULL) {
        if (strstr("COLEGIUL", p) != NULL)
            strcat(nou, "COLEGIUL");
        else if (strstr("LICEUL", p) != NULL)
            strcat(nou, "LICEUL");
        else if (strstr("NATIONAL", p) != NULL)
            strcat(nou, "NATIONAL");
        else if (strstr("TEORETIC", p) != NULL)
            strcat(nou, "TEORETIC");
        else
            strcat(nou, p);

        strcat(nou, " ");
        p = strtok(NULL, " .,");
    }

    cout << nou;
 
}

int trei_main()
{
    int v[3] = { 0 }, nr, p_max = 0, i_max = 0, p_min = 999999, i_min = 999999, n;
    ifstream fin("bac.txt");
    fin >> n;
    while (fin >> nr) 
    {
        if (n > 0) 
        {
            if (nr % 2 == 0) 
            {
                v[0]++;
                if (nr > p_max)
                    p_max = nr;
            }
            else 
            {
                v[1]++;
                if (i_max < nr)
                    i_max = nr;
            }
            n--;
        }
        else {
            if (nr % 2 == 0) {
                v[0]--;
                if (p_min > nr)
                    p_min = nr;
            }
            else {
                v[1]--;
                if (i_min > nr)
                    i_min = nr;
            }
        }
    }

    if (v[0] == 0)
        cout << "Da";
    else if (v[0] < 0) {
        if (p_max < i_min)
            cout << "Da";
        else
            cout << "Nu";
    }
    else if (v[0] > 0) {
        if (i_max < p_min)
            cout << "Da";
        else
            cout << "Nu";
    }
    else
        cout << "Nu";
}

int main()
{
    int n = 7255;
    inserare(n);
    cout << n;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
