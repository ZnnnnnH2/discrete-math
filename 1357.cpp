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
const int N = 15 + 5;
int a[N];
bool vis[N][N];
std::vector<int> LUBs;
std::vector<int> GLBs;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] % a[i] == 0)
            {
                vis[i][j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vis[i][j])
            {
                for (int k = i + 1; k < j; k++)
                {
                    if (vis[i][k] && vis[k][j])
                    {
                        vis[i][j] = false;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vis[i][j])
            {
                printf("(%d,%d) ", a[i], a[j]);
            }
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        bool falg_max = true;
        bool falg_min = true;
        for (int j = 0; j < n; j++)
        {
            if (!(a[i] % a[j] == 0))
            {
                falg_max = false;
            }
            if (!(a[j] % a[i] == 0))
            {
                falg_min = false;
            }
        }
        if (falg_max)
        {
            LUBs.push_back(a[i]);
        }
        if (falg_min)
        {
            GLBs.push_back(a[i]);
        }
    }
    bool ans1 = false;
    bool ans2 = false;
    for (auto lub : LUBs)
    {
        bool flag = true;
        for (auto ub : LUBs)
        {
            if (ub % lub != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans1 = true;
            break;
        }
    }
    for (auto glb : GLBs)
    {
        bool flag = true;
        for (auto lb : GLBs)
        {
            if (glb % lb != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans2 = true;
            break;
        }
    }
    if (ans1 and ans2)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}