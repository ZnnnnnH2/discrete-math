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

int p, x, y, m;
ll k_cifang(ll g,ll k){
    ll ans = 1;
    while(k){
        if(k & 1) ans = ans * g % p;
        g = g * g % p;
        k >>= 1;
    }
    return ans;
}
struct miyao{
    ll p, g, h;
};
miyao getmiyao(int g, int x){
    miyao ans;
    ans.p = p;
    ans.g = g;
    ans.h = k_cifang(g,x) % p;
    return ans;
}
struct miwen{
    ll c1, c2;
};
miwen get_miwen(int y, int m, miyao my){
    miwen ans;
    ans.c1 = k_cifang(my.g, y) % my.p;
    ans.c2 = (m * k_cifang(my.h, y)) % my.p;
    return ans;
}
ll get_s_ni(int s){
    ll sn = k_cifang(s, p-2) % p;
    return sn;
}
miwen jiemi(miyao my, miwen mw){
    ll s = k_cifang(mw.c1, x) % my.p;
    ll s_ni = get_s_ni(s);
    miwen ans;
    ans.c1 = s;
    ans.c2 = s_ni;
    return ans;
}
bool check[N];
int tot = 0;
int get_g(int p){
        tot = 0;
        memset(check, 0, sizeof(check));
        for (int g = 1; g < p;g++){
            ll gg = 1;
            for (int k = 1; k < p;k++){
                gg = gg * g % p;
                if(check[gg]){
                    continue;
                }
                else{
                    check[gg] = 1;
                    tot++;
                }
            }
            if (tot == p - 1)
            {
                return g;
            }
        }
}
int main() {
    std::cin >> p >> x >> y >> m;
    ll g = get_g(p);
    miyao my = getmiyao(g, x);
    miwen mw = get_miwen(y, m, my);
    miwen ans = jiemi(my, mw);
    std::cout << g << " " << my.h << " " << mw.c1 << " " << mw.c2<<" ";
    std::cout << ans.c1 << " " << ans.c2 << std::endl;
    return 0;
}