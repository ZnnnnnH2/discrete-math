#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <random>

typedef long long ll;
typedef int *intt;
typedef char *charr;

const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
ll POW(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}
int t, u;
void init(int n)
{
    n -= 1;
    t = 0;
    while (!(n & 1))
    {
        n >>= 1;
        t++;
    }
    u = n;
}
long long aa[7] = {2,325,9375,28178,450775,9780504,1795265022};
int main()
{
    int n;
    std::cin >> n;
    std::mt19937 rng(n);
    std::uniform_int_distribution<int> dist(2, n - 2);
    init(n);
    printf("%d %d\n", t, u);
    for (int i = 0; i < 7; i++)
    {
        ll a = aa[i]%n;
        printf("%lld ", a);
        ll v = POW(a, u, n);
        printf("%lld ", v);
        if (v == 1)
        {
            printf("\n");
            continue;
        }

        bool flag = false;
        for (int i = 1; i <= t; i++)
        {
            if (v == n - 1)
            {
                flag = true;
                break;
            }
            v = v * v % n;
            printf("%lld ", v);
        }
        printf("\n");
        if (!flag)
        {
            printf("false\n");
            return 0;
        }
    }
    printf("true\n");
    return 0;
}