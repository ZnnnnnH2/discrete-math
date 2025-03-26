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

int main()
{
    int ans = 0;
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            for (int k = 0; k <= 5; k++)
            {
                if (0 <= 10 - i - j - k and 10 - i - j - k <= 5)
                {
                    ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}