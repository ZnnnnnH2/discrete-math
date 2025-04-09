#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef int *intt;
typedef char *charr;
typedef std::vector<std::vector<int>> matrix;

const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
int n;
bool zifan(matrix a)
{
    for (int i = 0; i < n; i++)
    {
        if (!a[i][i])
        {
            return false;
        }
    }
    return true;
}
bool fanzifan(matrix a)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i][i])
        {
            return false;
        }
    }
    return true;
}
bool duichen(matrix a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != a[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
bool fanduichen(matrix a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (a[i][j] and a[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
bool chuandi(matrix a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (a[i][j] and a[j][k]){
                    if(!a[i][k]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    matrix a(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d %d %d %d %d\n", zifan(a)?1 : 0, fanzifan(a) ? 1 : 0, duichen(a) ? 1 : 0, fanduichen(a) ? 1 : 0, chuandi(a) ? 1 : 0);
    return 0;
}