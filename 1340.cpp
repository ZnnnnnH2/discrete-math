#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
 
typedef long long ll;
typedef int *intt;
typedef char *charr;

const int inf=0x3f3f3f3f;
const int N=1e3+5;
int ans = 0;
int k,n;
std::vector<int> a[N];

void dfs(int index,int mun){
    if(mun >=k){
        if(index == n-1){
            ans++;
        }
        return;
    }
    for (auto i:a[index]){
        dfs(i,mun+1);
    }
}
int main() {
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= m;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
    }
    scanf("%d", &k);
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}