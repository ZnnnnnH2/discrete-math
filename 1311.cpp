#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
 
typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf=0x3f3f3f3f;
const int N=30;
bool mmp[N][N];
int sta[N], top;
void op(int& l, int& r, string str){
    int len = str.size();
    if(r-l == 1){
        sta[top++] = str[l]-'a';
    }
    else{
        char c1 = str[l], c2 = str[r - 1];
        mmp[c1-'a'][c2-'a'] = 1;
    }
    r++;
    l = r;
    return;
}
bool trip(int x,int aim){
    if(x == aim){
        return 1;
    }
    for (int i = 0; i < N;i++){
        if(mmp[x][i] and trip(i, aim)){
            return 1;
        }
    }
    return 0;
}
bool travel(int aim){
    for (int i = 0; i < top;i++){
        if(trip(sta[i], aim)){
            return 1;
        }
    }
    return 0;
}
int main() {
    int T;
    cin >> T;
    while(T--){
        string str1, str2;
        cin >> str1 >> str2;
        memset(mmp, 0, sizeof(mmp));
        top = 0;
        memset(sta, 0, sizeof(sta));
        int l=0, r = 0, len = str1.size();
        while(r<len){
            if(str1[r] == ','){
                op(l, r, str1);
            }
            r++;
        }
        op(l, r, str1);
        if(travel(str2[0]-'a')){
            cout<<"Proved"<<endl;
        }
        else{
            cout<<"Not Proved"<<endl;
        }
    }
    return 0;
}