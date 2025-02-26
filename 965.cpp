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

int main()
{
    string s;
    getline(cin, s);
    int len = s.length();
    int left = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
            left++;
        else if (s[i] == ')')
        {
            if (left > 0)
                left--;
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (left == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}