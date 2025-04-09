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
const int N = 105;
bool mmp[N][N];
int n;
bool check_zifan()
{
    for (int i = 1; i <= n; i++)
    {
        if (!mmp[i][i])
        {
            return false;
        }
    }
    return true;
}
bool check_duichen()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mmp[i][j] != mmp[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
bool check_chuandi()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (mmp[i][j] && mmp[j][k] && !mmp[i][k])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
bool check()
{
    if (!check_zifan())
    {
        return false;
    }
    if (!check_duichen())
    {
        return false;
    }
    if (!check_chuandi())
    {
        return false;
    }
    return true;
}
std::vector<int> ans[N];
void init(){
    for(int i = 1; i <= n; i++){
        ans[i].push_back(i);
    }
    return;
}
void lianton(){
    init();
    for (int i = 1; i <= n;i++){
        for (int j = i + 1; j <= n;j++){
            if(mmp[i][j]){
                for(auto it : ans[j]){
                    ans[i].push_back(it);
                }
                ans[j].clear();
            }
        }
    }
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            scanf("%d", &x);
            mmp[i][j] = x == 1 ? true : false;
        }
    }
    if (!check())
    {
        printf("no\n");
        return 0;
    }
    printf("yes\n");
    lianton();
    for (int i = 1; i <= n; i++)
    {
        if (!ans[i].empty())
        {
            std::sort(ans[i].begin(), ans[i].end());
            for (auto it : ans[i])
            {
                printf("%d ", it);
            }
            printf("\n");
        }
    }
    return 0;
}