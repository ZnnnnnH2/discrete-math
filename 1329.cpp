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
std::string str;
int getmun(int &l, int &r)
{
    for (; l < r; l++)
    {
        if (str[l] >= '0' and str[l] <= '9')
        {
            int mun = 0;
            while (str[l] >= '0' and str[l] <= '9')
            {
                mun = mun * 10 + str[l] - '0';
                l++;
            }
            return mun;
        }
    }
    return -1;
}
int n = 0;
int munbers[N];
bool dfs(int l,int r,int k){
    if(k == n - 1){
        if(l == r){
            return true;
        }
        else {
            return false;
        }
    }
    return dfs(l+munbers[k],r,k+1) || dfs(l,r+munbers[k],k+1);
}
int main() {
    std::getline(std::cin, str);
    int l = 0;
    int len = str.size();
    while(l<len){
        munbers[n]=getmun(l,len);
        if(munbers[n-1]==-1) break;
        n++;
    }
    if(dfs(0,0,0)){
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    return 0;
}