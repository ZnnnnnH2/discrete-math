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
const int N = 1e5 + 5;
ll jc(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * jc(n - 1);
}
ll C(int m, int n)
{
    if (m < 0)
    {
        return 0;
    }
    ll t = 1;
    for (int i = m-n+1; i <= m; i++)
    {
        t *= i;
    }
    return t / jc(n);
}
int mi(int k)
{
    if (k == 0)
    {
        return 1;
    }
    return (-1) * mi(k - 1);
}
int x[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    ll ans = C(m + n - 1, n - 1);
    // printf("%lld\n", ans);
    int tot = 1 << n;
    for (int i = 1; i < tot; i++)
    {
        int mm = m;
        int geshu = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                geshu++;
                mm -= (x[j + 1]+1);
            }
        }
        if(mm<0){
            continue;
        }
        // printf("%d %lld\n", geshu, mi(geshu) * C(mm + n - 1, n - 1));
        ans += mi(geshu) * C(mm + n - 1, n - 1);
    }
    printf("%lld\n", ans);
    return 0;
}