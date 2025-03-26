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
std::string ans[50000];
char c[30];

int main() {
    std::string str;
    std::getline(std::cin, str);
    int len = str.length();
    for (int i = 0; i < len;i++){
        c[i] = str[i];
    }
    std::sort(c, c + len);
    int end = 1 << len;
    for (int i = 1; i <= end;i++){
        std::string temp;
        for (int j = 0; j < len;j++){
            if(i&(1<<j)){
                temp += c[j];
            }
        }
        ans[i] = temp;
    }
    std::sort(ans + 1, ans + end);
    for (int i = 1; i < end;i++){
        std::cout << ans[i] << std::endl;
    }
    return 0;
}