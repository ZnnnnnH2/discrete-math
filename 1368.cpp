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
ll mod;
ll mi(ll x, ll p){
    if(p == 0) return 1;
    if(p == 1) return x;
    ll t = mi(x, p/2);
    t = t * t % mod;
    if(p % 2 == 1) t = t * x % mod;
    return t%mod;
}
int main() {
    ll x, p;
    std::cin>>x>>p;
    mod = p;
    std::cout<<mi(x, p-2)<<std::endl;
    return 0;
}