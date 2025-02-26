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
const int N = 250;
int mt[N], ljc[N];
char ljcb[] = {'!', '&', '|', '>', '-'};
int inljcb(char c)
{
    for (int i = 0; i < 5; i++)
    {
        if (c == ljcb[i])
            return i;
    }
    return -1;
}
int main()
{
    string str;
    getline(cin, str);
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        int index = inljcb(str[i]);
        if (index != -1)
        {
            ljc[index]++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            mt[str[i] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        if (mt[i])
        {
            printf("%d%c ", mt[i], c);
        }
    }
    putchar('\n');
    for (int i = 0; i < 5; i++)
    {
        if (ljc[i])
        {
            printf("%d%c ", ljc[i], ljcb[i]);
        }
    }
    return 0;
}