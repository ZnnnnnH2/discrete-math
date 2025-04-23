#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef int *intt;
typedef char *charr;

const int inf = 0x3f3f3f3f;
const int N = 105 + 5;
int a[N];
bool vis[N][N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] % a[i] == 0)
            {
                vis[i][j] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (vis[i][j])
            {
                for (int k = i+1; k < j; k++)
                {
                    if (vis[i][k] and vis[k][j])
                    {
                        vis[i][j] = false;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (vis[i][j])
            {
                printf("%d %d\n", a[i], a[j]);
            }
        }
    }
    return 0;
}