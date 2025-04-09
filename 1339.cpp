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
const int N = 10;
int n;
int a[N][N];
int b[N][N];
int c[N][N];
int d[N][N];
void ReflexiveClosure()
{
    printf("Reflexive Closure:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            b[i][j] = a[i][j];
        }
        b[i][i] = 1;
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return;
}
void TransitiveClosure()
{
    printf("Transitive Closure:\n");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            b[i][j] = a[i][j];
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                b[i][j] = b[i][j] || (b[i][k] && b[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return;
}
void SymmetricClosure()
{
    printf("Symmetric Closure:\n");
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            b[i][j] = a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (b[i][j] == 1)
            {
                b[j][i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    ReflexiveClosure();
    SymmetricClosure();
    TransitiveClosure();
    return 0;
}