#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char s[100000] = {0};
    int a[100000] = {0};
    char b[100000] = {0};
    int i = 0;
    char ch = 0;
    do
    {
        scanf("%d", &a[i]);
        a[i] %= 10000;
        ch = getchar();
        b[i] = ch;
        i++;
    } while (ch != EOF);
    for (int j = 0; j < i - 1; j++)
    {
        if (b[j] == '*')
        {
            a[j + 1] = a[j] * a[j + 1];
            a[j + 1] %= 10000;
            a[j] = 0;
        }
    }
    int res = 0;
    for (int j = 0; j < i; j++)
    {
        res += a[j];
    }
    cout << (res % 10000);
    return 0;
}