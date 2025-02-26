#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
bool yunhan(bool a, bool b)
{
    return !a || b;
}
int main()
{
    int True = 0, False = 0;
    int A, B, C, D, E;
    for (A = 0; A <= 1; A++)
    {
        for (B = 0; B <= 1; B++)
        {
            for (C = 0; C <= 1; C++)
            {
                for (D = 0; D <= 1; D++)
                {
                    for (E = 0; E <= 1; E++)
                    {
                        if (yunhan(A && B, (C || (D && E)) && (!A || !B) && (yunhan(D, E && A))))
                        {
                            True++;
                        }
                        else
                        {
                            False++;
                        }
                    }
                }
            }
        }
    }
    if (True == 0)
    {
        cout << "矛盾式" << endl;
    }
    else if (False == 0)
    {
        cout << "永真式" << endl;
    }
    else
    {
        cout << "可满足式" << endl;
    }
    return 0;
}