#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
const int MOD = 10000;
string str;
int n;
bool ismun(char c)
{
    return c >= '0' && c <= '9';
}
int tomun(string subs)
{
    return atoi(subs.c_str());
}
int getmun(int &i)
{
    string subs = "";
    while (i < n && ismun(str[i]))
    {
        subs += str[i];
        i++;
    }
    return tomun(subs);
}
int stack[N];
int top = 0;
int mul[N];
int tot = 0;
int main()
{
    int ans = 0;
    cin >> str;
    n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (ismun(str[i]))
        {
            int mun = getmun(i);
            stack[top++] = mun % MOD;
            i--;
        }
        else
        {
            if (str[i] == '*')
            {
                mul[tot++] = top;
            }
        }
    }
    // for(int i = 0; i < top; i++)
    // {
    //     cout << stack[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < tot; i++)
    {
        stack[mul[i]] *= stack[mul[i] - 1];
        stack[mul[i]] %= MOD;
        stack[mul[i] - 1] = 0;
    }
    // for(int i = 0; i < top; i++)
    // {
    //     cout << stack[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < top; i++)
    {
        ans += stack[i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}