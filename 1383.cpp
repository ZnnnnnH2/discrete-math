#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>

typedef long long ll;
typedef int *intt;
typedef char *charr;

const int inf=0x3f3f3f3f;
const int N=100;
int a[N];
int n;
int relationship[N][N];
int interaction[N];
int get_ans_index(int i, int j) {
    int ans = relationship[i][j];
    return interaction[ans];
}
int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        interaction[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> relationship[i][j];
            if (!interaction[relationship[i][j]]) {
                std::cout << "NOT CLOSED" << std::endl;
                return 0;
            }
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            for (int k = 1; k <= n;k++){
                int ans1_index = get_ans_index(i, j);
                int ans2_index = get_ans_index(ans1_index, k);

                int ans1_intdex_2 = get_ans_index(j, k);
                int ans2_intdex_2 = get_ans_index(i, ans1_intdex_2);
                if(ans2_index != ans2_intdex_2){
                    std::cout << "NOT ASSOCIATIVE" << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << "SEMIGROUP" << std::endl;
    return 0;
}