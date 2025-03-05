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
bool tuichu(bool x, bool y)
{
    return (!x) | y;
}
bool t[10];
int main()
{
    int tot = 0;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            printf("p=%d q=%d p>q=%d(%c%d) !p&q=%d(%c%d)\n", i, j, tuichu(i, j), tuichu(i, j) ? 'm' : 'M', i * 2 + j, !i | j, !i | j ? 'm' : 'M', i * 2 + j);
            if (tuichu(i, j))
            {
                t[i * 2 + j] = 1;
                tot++;
            }
        }
    }
    int tott = 4 - tot;
    printf("PDNF(p>q):");
    for (int i = 0; i < 4; i++)
    {
        if (tot == 1)
        {
            break;
        }
        if (t[i])
        {
            printf("%c%d∨", 'm', i);
            tot--;
        }
    }
    for (int i = 3; i >= 0; i--)
    {
        if (t[i])
        {
            printf("%c%d", 'm', i);
            break;
        }
    }
    printf("\n");
    printf("PCNF(p>q):");
    for (int i = 0; i < 4; i++)
    {
        if (tott == 1)
        {
            break;
        }
        if (!t[i])
        {
            printf("%c%d∧", 'M', i);
            tott--;
        }
    }
    for (int i = 3; i >= 0; i--)
    {
        if (!t[i])
        {
            printf("%c%d", 'M', i);
            break;
        }
    }
    printf("\nyes\n");
    return 0;
}