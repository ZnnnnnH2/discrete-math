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
    int l, r;
    node()
    {
        l = r = 0;
    }
    bool operator<(const node &a) const
    {
        if (l == a.l)
            return r < a.r;
        return l < a.l;
    }
};
node interval[N];
std::string str;
int getmun(int &l, int &r)
{
    for (; l < r; l++)
    {
        if (str[l] >= '0' and str[l] <= '9')
        {
            int t = 1;
            if(str[l-1] == '-'){
                t = -1;
            }
            int mun = 0;
            while (str[l] >= '0' and str[l] <= '9')
            {
                mun = mun * 10 + str[l] - '0';
                l++;
            }
            return mun*t;
        }
    }
    return -inf;
}
int main()
{
    std::getline(std::cin, str);
    int l = 0;
    int len = str.size();
    int top = 0;
    while (l < len)
    {
        interval[top].l = getmun(l, len);
        interval[top].r = getmun(l, len);
        if (interval[top].l == -inf or interval[top].r == -inf)
        {
            break;
        }
        top++;
    }
    std::sort(interval, interval + top);
    int left = interval[0].l;
    int right = interval[0].r;
    printf("[");
    for (int i = 1; i < top; i++)
    {
        if(interval[i].l <= right)
        {
            right = std::max(right, interval[i].r);
        }
        else
        {
            printf("[%d,%d],", left, right);
            left = interval[i].l;
            right = interval[i].r;

        }
    }
    printf("[%d,%d]]\n", left, right);
    return 0;
}