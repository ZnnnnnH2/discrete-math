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
const int N=1e5+5;
int phi[N];
int top = 0;
int ans[N];
int top_ans = 0;
int m;
bool vis[N];
bool check(int x)
{
    int k = 1;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m;i++){
        k *= x;
        k %= m;
        vis[k] = true;
    }
    for (int i = 0; i < top;i++){
        if (!vis[phi[i]]){
            return false;
        }
    }
    return true;
}
int main() {
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        if (std::__gcd(i, m) == 1) {
            phi[top++] = i;
            printf("%d ", i);
        }
    }
    printf("\n");
    for (int i = 0; i < top;i++){
        if (check(phi[i])) {
            ans[top_ans++] = phi[i];
        }
    }
    if (top_ans == 0) {
        printf("N\n");
    } else {
        printf("Y\n");
        for (int i = 0; i < top_ans;i++){
            printf("%d ", ans[i]);
        }
    }
    return 0;
}