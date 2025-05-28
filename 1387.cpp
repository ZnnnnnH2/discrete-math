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
bool is_relatively_prime(int a, int b) {
    return std::__gcd(a, b) == 1;
}
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        if (is_relatively_prime(i, n)) {
            printf("%d ", i);
        }
    }
    return 0;
}