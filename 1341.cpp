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
const int M = 15;
int m;
matrix mtt(matrix a, matrix b)
{
    matrix c(m, std::vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
                if (c[i][j] > 1)
                {
                    c[i][j] = 1;
                    break;
                }
            }
        }
    }
    return c;
}
matrix fmut(int n,matrix t)
{
    if(n == 1)
    {
        return t;
    }
    if(n % 2 == 1)
    {
        return mtt(t, fmut(n - 1,t));
    }
    else
    {
        matrix c = fmut(n / 2,t);
        return mtt(c, c);
    }
}
int main()
{
    int n;
    scanf("%d%d", &m, &n);
    matrix a(m, std::vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    matrix c = fmut(n,a);
    for(auto i:c){
        for(auto j:i){
            printf("%d ", j>0? 1 : 0);
        }
        printf("\n");
    }
    return 0;
}