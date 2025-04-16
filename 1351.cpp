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
int getmun(int &index, int length, std::string str)
{
    int mun = 0;
    while (index < length and (str[index] < '0' or str[index] > '9'))
    {
        index++;
    }
    for (; index < length; index++)
    {
        if (str[index] >= '0' and str[index] <= '9')
        {
            mun = mun * 10 + (str[index] - '0');
        }
        else
        {
            break;
        }
    }
    if (index >= length)
    {
        return -1;
    }
    return mun;
}
std::vector<std::pair<int, int>> v;
bool cmp(std::pair<int, int> a, std::pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}
int main()
{
    std::string str;
    getline(std::cin, str);
    int n = str.length();
    int index = 0;
    int top = 0;
    for (; index < n; index++)
    {
        int x = getmun(index, n, str);
        int y = getmun(index, n, str);
        if (x == -1 or y == -1)
        {
            break;
        }
        index--;
        v.push_back(std::make_pair(std::min(x, y), std::max(x, y)));
        top++;
    }
    std::sort(v.begin(), v.end(), cmp);
    int ans = 0;
    int total = 1;
    for (int i = 1; i < top; i++)
    {
        // printf("%d %d\n", v[i].first, v[i].second);
        if (v[i] == v[i - 1])
        {
            total++;
        }
        else
        {
            ans += (total * (total - 1)) / 2;
            total = 1;
        }
    }
    ans += (total * (total - 1)) / 2;
    std::cout << ans << std::endl;
    return 0;
}