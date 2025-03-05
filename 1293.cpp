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
const int N = 100;
string str[N];
bool vis[N];
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int mun = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] <= 'Z' and s[i] >= 'A'){
            if(!vis[s[i] - 'A']){
                vis[s[i] - 'A'] = true;
                mun++;
            }
        }
    }
    for (int i = 0; i < mun; i++)
    {
        cin >> str[i];
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] <= 'Z' and s[i] >= 'A')
        {
            ans += str[s[i] - 'A'];
        }
        else
        {
            ans += s[i];
        }
    }
    cout << ans << endl;
    return 0;
}