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
const int N=1e3+5;
string s[N];
int top = 0;
int main() {
    string str;
    cin >> str;
    int l = 0, r = 0, len = str.size();
    while(r<len and l+1<len){
        if(str[r] == ')'){
            while(str[l] == '(' && str[l+1]=='('){
                l++;
            }
            s[top++] = str.substr(l+1, r - l-1);
            l = r + 2;
        }
        r++;
    }
    for(int i=0;i<top-2;i++){
        cout << "(" << s[i] << ")&";
    }
    cout << "(" << s[top - 2] << ")>(" << s[top - 1] << ")" << endl;
    cout << "!(";
    for (int i = 0; i < top - 1;i++){
        cout<<'('<<s[i]<<")&";
    }
    cout << "!(" << s[top - 1] << "))" << endl;
    return 0;
}