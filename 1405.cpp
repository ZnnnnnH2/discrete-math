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
const int N = 105;
int n, m;
bool t[N][N];
std::vector<int> a1;
std::vector<int> a2;
bool has_max(int x, int y)
{
    a1.clear();
    for (int i = 1; i <= n; i++)
    {
        if (t[x][i] && t[y][i])
        {
            a1.push_back(i);
        }
    }
    for (int v : a1)
    {
        bool flag = true;
        for (int u : a1)
        {
            if (!t[v][u] and v != u)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return true;
        }
    }
    return false;
}
bool has_min(int x, int y)
{
    a2.clear();
    for (int i = 1; i <= n; i++)
    {
        if (t[i][x] && t[i][y])
        {
            a2.push_back(i);
        }
    }
    for (int v : a2)
    {
        bool flag = true;
        for (int u : a2)
        {
            if (!t[u][v] and v != u)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    std::cin >> n >> m;
    memset(t, 0, sizeof(t));
    for (int j = 1; j <= m; j++)
    {
        int x, y;
        std::cin >> x >> y;
        t[x][y] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        t[i][i] = true; // Ensure reflexivity
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                if (t[i][k] && t[k][j])
                {
                    t[i][j] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (!has_max(i, j))
            {
                printf("NO\n");
                return 0;
            }
            if (!has_min(i, j))
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (!t[j][i])
            {
                continue;
            }
            bool flag = true;
            for (int k = 1; k <= n; k++)
            {
                if (t[j][k] && t[k][i] && k != i && k != j)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                printf("%d COVERS %d\n", i, j);
            }
        }
    }
    return 0;
}