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
const int N = 2e2 + 5;
int map[N];
int sta[N], top = 0;
int dengji[N];
string str;
int tot = 0;
bool iscc[N];
string eval(int l, int r)
{
    if (str[l] == '(')
    {
        l++;
    }
    if (str[r] == ')')
    {
        r--;
    }
    if (str[l] == 'f')
    {
        string s = "";
        s += eval(l + 2, l + 2);
        s += "+";
        s += eval(l + 4, l + 4);
        return s;
    }
    else if (str[l] == 'g')
    {
        string s = "";
        s += eval(l + 2, l + 2);
        s += "*";
        s += eval(l + 4, l + 4);
        return s;
    }
    else if (str[l] == 'F')
    {
        string s = "(";
        int index;
        for (int i = l + 1; i <= map[l + 1]; i++)
        {
            if (dengji[l + 1] == dengji[i] && str[i] == ',')
            {
                index = i;
                break;
            }
        }
        s += eval(l + 1, index - 1);
        s += "=";
        s += eval(index + 1, map[l] - 1);
        s += ")";
        return s;
    }
    else if (str[l] == 'x' || str[l] == 'y' || str[l] == 'z')
    {
        if (iscc[str[l]])
        {
            return str.substr(l, 1);
        }
        else
        {
            return to_string(str[l] - 'x' + 1);
        }
    }
    else
    {
        return "0";
    }
}
int main()
{
    // str = "(F(f(x,a),y))";
    cin >> str;
    int i = 0;
    int length = str.length();
    memset(iscc, 0, sizeof(iscc));
    while (str[i] == 'V' || str[i] == 'E')
    {
        cout << str[i];
        i++;
        iscc[str[i]] = 1;
        cout << str[i];
        i++;
    }
    for (int j = i; j < length; j++)
    {
        if (str[j] == '(')
        {
            sta[top++] = j;
            dengji[j] = top;
        }
        else if (str[j] == ')')
        {
            dengji[j] = top;
            top--;
            map[sta[top]] = j;
        }
        else
        {
            dengji[j] = top;
        }
    }
    cout << eval(i, map[i]) << endl;
    return 0;
}