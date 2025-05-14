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
ll jc(int k){
    ll ans = 1;
    for(int i = 1; i <= k; i++){
        ans *= i;
    }
    return ans;
}
ll combination(int m,int n){
    if(m<n) return 0;
    if(m==n) return 1;
    
    return jc(m) / (jc(n) * jc(m-n));
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << combination(n+m, n);
    return 0;
}