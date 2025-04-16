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
int price[N];
std::vector<std::pair<int, int>> ans;

int main() {
    int target, n;
    scanf("%d %d", &target, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    int l = 0, r = n - 1;
    bool flag = false;
    for (; l < r;l++){
        while(l < r && price[l] + price[r] > target) {
            r--;
        }
        if (l < r && price[l] + price[r] == target) {
            ans.push_back(std::make_pair(price[l], price[r]));
            flag = true;
        }
    }
    if(!flag) {
        printf("[]\n");
    }
    else {
        int ans_size = ans.size();
        for(int i = 0; i < ans_size; i++) {
            std::pair<int, int> ans_pair = ans[i];
            if(i-1>=0 and ans_pair == ans[i-1]){
                continue;
            }
            printf("[%d,%d]\n", ans_pair.first, ans_pair.second);
        }
    }
    return 0;
}