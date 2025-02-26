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
const int N = 200;
string str;
int len;
char stack[N];
int top = 0;
int yxj[N];
string s;
int js[N];

void change()
{
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            s += str[i];
            js[str[i]]++;
        }
        else if (str[i] == '(')
        {
            stack[top++] = str[i];
        }
        else if (str[i] == ')')
        {
            for (int j = top - 1; j >= 0; j--)
            {
                if (stack[j] == '(')
                {
                    top = j;
                    break;
                }
                s += stack[j];
            }
        }
        else
        {
            if (top == 0)
            {
                stack[top++] = str[i];
            }
            else
            {
                while (top > 0 and yxj[stack[top - 1]] <= yxj[str[i]])
                {
                    s += stack[--top];
                }
                stack[top++] = str[i];
            }
        }
    }
    for (int i = top - 1; i >= 0; i--)
    {
        s += stack[i];
    }
    // cout << s << endl;
}
int zongshu = 0;
char zimu[26];
int zhenzhi[26];
bool ans[N];

bool jisuan()
{
    memset(ans, 0, sizeof(ans));
    int mun = 0;
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans[mun++] = zhenzhi[js[s[i]]];
        }
        else
        {
            switch (s[i])
            {
            case '!':
                ans[mun - 1] = !ans[mun - 1];
                break;
            case '&':
                ans[mun - 2] = ans[mun - 1] & ans[mun - 2];
                mun--;
                break;
            case '|':
                ans[mun - 2] = ans[mun - 1] | ans[mun - 2];
                mun--;
                break;
            case '>':
                ans[mun - 2] = !ans[mun - 2] | ans[mun - 1];
                mun--;
                break;
            case '-':
                ans[mun - 2] = ans[mun - 2] == ans[mun - 1];
                mun--;
                break;
            }
        }
    }
    return ans[0];
}
int main()
{
    yxj['!'] = 1;
    yxj['&'] = 2;
    yxj['|'] = 3;
    yxj['>'] = 4;
    yxj['-'] = 5;
    yxj['('] = 6;
    getline(cin, str);
    len = str.length();
    change();
    for (int i = 0; i < 125; i++)
    {
        if (js[i])
        {
            zimu[zongshu++] = i;
        }
    }
    for (int i = 0; i < zongshu; i++)
    {
        js[zimu[i]] = i;
        printf("%c ", zimu[i]);
    }
    cout << str << endl;
    int t = 1 << zongshu;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < zongshu; j++)
        {
            zhenzhi[zongshu - j - 1] = (i >> j) & 1;
        }
        for (int j = 0; j < zongshu; j++)
        {
            printf("%d ", zhenzhi[j]);
        }
        printf("%d\n", jisuan() ? 1 : 0);
    }
    return 0;
}