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
const int N=1e4+5;
const ll MOD = 10000000000002137;
const int M = 1e5 + 5;
const int P = 1e5;
const ll base = 31;
ll get_one(char c){
    if(c >= 'a' && c <= 'z'){
        return c - 'a';
    }else if(c >= 'A' && c <= 'Z'){
        return c - 'A' + 26;
    }else if(c >= '0' && c <= '9'){
        return c - '0' + 52;
    }else{
        return (ll)(c);
    }
}
ll hash(std::string s) {
    ll ans = s.size()*base%MOD;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        ans = (ans * base + get_one(s[i])) % MOD;
    }
    return ans;
}
ll hash_ans[N];
std::vector<ll> ans[M];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        hash_ans[i] = hash(s);
    }
    int tot = 0;
    for (int i = 0; i < n;i++){
        int index = hash_ans[i] % P;
        for(ll str_hash : ans[index]){
            if(str_hash == hash_ans[i]){
                goto END;
            }
        }
        ans[index].push_back(hash_ans[i]);
        tot++;
    END:;
    }
    printf("%d\n", tot);
    return 0;
}