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
bool prime[N];
int allPrimes[N];
int allPrimesNum = 0;
void getPrime(int end)
{
    memset(prime, 0, sizeof(prime));
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= end; i++)
    {
        if (!prime[i])
        {
            for (int j = i * i; j <= end; j += i)
            {
                prime[j] = 1;
            }
        }
    }

    for(int i = 2; i <= end; i++)
    {
        if(!prime[i])
        {
            allPrimes[allPrimesNum++] = i;
        }
    }
}
int ol(int n)
{
    double ans = n;
    for (int i = 0; i < allPrimesNum; i++)
    {
        if (allPrimes[i] > n || n == 1)
            break;
        if (n % allPrimes[i] == 0)
        {
            ans *= (1.0 - 1.0 / allPrimes[i]);
            while (n % allPrimes[i] == 0)
            {
                n /= allPrimes[i];
            }
        }
    }
    return ans;
}
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    getPrime(n);
    for (int i = m; i <= n; i++)
    {
        if(i == 1)
        {
            printf("1 ");
            continue;
        }
        printf("%d ", ol(i));
    }
    return 0;
}