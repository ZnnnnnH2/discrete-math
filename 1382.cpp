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
int a, b, c, q;
int test[200];

int main()
{
    std::cin >> a >> b >> c >> q;
    test[a] = 1;
    for (int i = a + 1; i <= 100; i++)
    {
        if (test[i - b] == 1)
        {
            test[i] = 1;
        }
        if (test[i / c] == 1 and i % c == 0)
        {
            test[i] = 1;
        }
    }
    if (test[q] == 1)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    return 0;
}