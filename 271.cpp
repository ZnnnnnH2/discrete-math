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
const int N=1e5+5;
string s;
int n;
bool checkmun(char c){
    if(c>='0'&&c<='9')
        return true;
    return false;
}
void solve_string(){
    for (int i = 0; i < n;i++){
        if(s[i]>='a' and s[i]<='z'){
            s[i]=s[i]-'a'+'A';
        }
    }
    cout << s << endl;
    return;
}
void solve_double(){
    int mun = atoi(s.c_str());
    cout << mun << endl;
    return;
}
void solve_int(){
    int mun = atoi(s.c_str());
    cout << mun+1 << endl;
    return;
}
int solve(){
    int mun = atoi(s.c_str());
    return mun;
}
int main() {
    getline(cin,s);
    n=s.size();
    for (int i = 0; i < n;i++){
        if(s[i]=='-'){
            continue;
        }
        if(!checkmun(s[i])){
            if(s[i]=='.'){
                solve_double();
            }
            else{
                solve_string();
            }
            return 0;
        }
    }
    solve_int();
    return 0;
}