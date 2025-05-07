#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef int *intt;
typedef char *charr;

const ll inf = 0x3f3f3f3f;
const ll N = 1005;
const ll p = 131;
const ll q = 137;
const ll n = p * q;
const ll n_square = n * n;
const ll g = n + 1;
const ll lambda = 8840;
const ll mu = 14855;
ll c_func(ll u)
{
    return (u - 1) / n;
}
ll mi(ll x, ll p, ll mod)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return x;
    ll t = mi(x, p / 2, mod);
    t = t * t % mod;
    if (p % 2 == 1)
        t = t * x % mod;
    return t % mod;
}
ll E_func(ll m)
{
    return mi(g, m, n_square);
}
ll u_func(ll c)
{
    return mi(c, lambda, n_square);
}
ll m_func(ll u)
{
    return c_func(u) * mu % n;
}
ll miwen[N];
bool use[N];

int main()
{
    int T;
    std::cin >> T;
    int tot = 0;
    while (T--){
        std::string s;
        do{
            std::cin>>s;
        }while(s.length()<=2);
        if(s=="UPLOAD"){
            ll m;
            std::cin>>m;
            tot++;
            miwen[tot] = E_func(m);
            use[tot] = true;
            printf("%d %lld\n", tot, miwen[tot]);
        }
        else if(s=="ADD"){
            ll a,b;
            std::cin>>a>>b;
            tot++;
            miwen[tot] = miwen[a] * miwen[b] % n_square;
            use[tot] = true;
            printf("%d %lld\n", tot, miwen[tot]);
        }
        else if(s=="MUL"){
            ll a, k;
            std::cin>>a>>k;
            tot++;
            miwen[tot] = mi(miwen[a],k,n_square) % n_square;
            use[tot] = true;
            printf("%d %lld\n", tot, miwen[tot]);
        }
        else if(s=="DELETE"){
            ll a;
            std::cin>>a;
            use[a] = false; 
            printf("%d %lld\n", a, miwen[a]);
        }
        else if(s=="AGGREGATE"){
            ll mi = 1;
            bool flag = false;
            for (int i = 1; i <= tot;i++){
                if(use[i]){
                    flag = true;
                    printf("%d ", i);
                    mi = mi * miwen[i] % n_square;
                }
            }
            if(!flag){
                printf("0");
            }
            else{
                printf("%lld", mi);
                ll u = u_func(mi);
                ll m = m_func(u);
                printf(" %lld", m);
            }
            printf("\n");
        }
    }
    return 0;
}