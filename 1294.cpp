#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 200;
int yxj[N];    // 运算符优先级
char stack[N]; // 保存运算符的栈
int top = 0;   // 栈顶指针

string change(string str)
{
    int len = str.size();
    string s = ""; // 保存后缀表达式
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            s += str[i];
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
    return s;
}
bool ans[N]; // 保存计算结果的栈
bool pqr[N];

bool jisuan(string s)
{
    memset(ans, 0, sizeof(ans));
    int mun = 0;
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans[mun++] = pqr[s[i] - 'a'];
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
bool yunhan(bool x, bool y)
{
    return !x | y;
}
bool k[N];
char c[N];
queue<int> q;
int main()
{
    yxj['!'] = 1;
    yxj['&'] = 2;
    yxj['|'] = 3;
    yxj['>'] = 4;
    yxj['-'] = 5;
    yxj['('] = 6;
    string str;
    cin >> str;
    int n = str.size();
    string s = change(str);
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (!k[str[i] - 'a'])
            {
                k[str[i] - 'a'] = 1;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (k[i])
        {
            c[tot++] = i + 'a';
        }
    }
    int m = 1 << tot;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < tot; j++)
        {
            pqr[c[j] - 'a'] = i >> (tot - j - 1) & 1;
        }
        if (jisuan(s))
        {
            q.push(i);
        }
    }
    while (q.size() > 1)
    {
        printf("m%d|", q.front());
        q.pop();
    }
    printf("m%d\n", q.front());
    return 0;
}