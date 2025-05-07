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
int muns[N];
int main() {
    std::string s;
    std::cin >> s;
    int len = s.length();
    int n = 0;
    for(int i=0;i<len;i++) {
        if(s[i]>='0'&&s[i]<='9') {
            int flag = 1;
            if(s[i-1]=='-') {
                flag = -1;
            }
            int num = 0;
            while(s[i]>='0'&&s[i]<='9'&&i<len) {
                num = num * 10 + s[i] - '0';
                i++;
            }
            muns[n] = num * flag;
            n++;
        }   
    }
    for(int i=0;i<n;i++) {
        muns[i+n]=muns[i];
    }
    // for(int i=0;i<2*n;i++) {
    //     printf("%d ",muns[i]);
    // }
    // printf("\n");
    int ans = -inf;
    for(int i=0;i<n;i++) {
        int sum = 0;
        for (int j = 0; j < n;j++){
            sum += j * muns[i + j];
        }
        // printf("%d\n",sum);
        ans = std::max(ans, sum);
    }
    printf("%d",ans);
    return 0;
}