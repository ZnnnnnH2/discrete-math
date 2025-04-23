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
struct node
{
    ll x, y;
    bool operator<(const node &a) const
    {
        return x < a.x || (x == a.x && y < a.y);
    }
} line[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &line[i].x, &line[i].y);
    }
    std::sort(line, line + n);
    ll ans = 0;
    ll l = line[0].x, r = line[0].y;
    for (int i = 1; i < n; i++)
    {
        if (line[i].x > r)
        {
            ans += r - l;
            l = line[i].x;
            r = line[i].y;
        }
        else
        {
            r = std::max(r, line[i].y);
        }
    }
    ans += r - l;
    printf("%lld\n", ans);
    return 0;
}