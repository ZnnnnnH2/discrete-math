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
int sta_op[N];
int sta_mun[N];
int top_op = 0;
int top_mun = 0;
int main()
{
    string str;
    cin >> str;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'V' || str[i] == 'E')
        {
            if (str[i + 1] < 'a' || str[i + 1] > 'z')
            {
                printf("no\n");
                return 0;
            }
            i++;
            sta_op[top_op++] = 1;
        }
        else if (str[i] == '!')
        {
            sta_op[top_op++] = 1;
        }
        else if (str[i] == '&' || str[i] == '|' || str[i] == '>' || str[i] == '-')
        {
            sta_op[top_op++] = 2;
        }
        else
        {
            top_mun++;
            while (top_op > 0 && sta_op[top_op - 1] <= top_mun)
            {
                if (sta_op[top_op - 1] == 1)
                {
                    top_op--;
                }
                else
                {
                    top_op--;
                    top_mun--;
                }
            }
        }
    }
    if (top_op == 0 && top_mun == 1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}