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
const int N=15;
int n, k, m;
bool mapab[N][N], mapbc[N][N], mapac[N][N];

int main() {
    while(scanf("%d %d %d", &n, &k, &m) != EOF) {
        memset(mapab, 0, sizeof(mapab));
        memset(mapbc, 0, sizeof(mapbc));
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= k; j++){
                int x;
                scanf("%d", &x);
                mapab[i][j] = x==1? true : false;
            }
        }
        for(int i = 1; i <= k;i++){
            for (int j = 1; j <= m; j++){
                int x;
                scanf("%d", &x);
                mapbc[i][j] = x==1? true : false;
            }
        }
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= m;j++){
                for(int l = 1; l <= k;l++){
                    if(mapab[i][l] && mapbc[l][j]){
                        mapac[i][j] = true;
                        break;
                    }
                }
            }
        }
        for(int i = 1; i <= n;i++){
            for (int j = 1; j <= m;j++){
                if(mapac[i][j]){
                    printf("1 ");
                }else{
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}