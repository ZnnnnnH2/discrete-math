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
void op(int p, int q, string str){
    int len = str.size();
    if(str[p]<'a' or str[p]>'z'){
        p++;
    }
    if(str[q-1]<'a' or str[q-1]>'z'){
        q--;
    }
    cout<<str.substr(p, q-p)<<" ";
    return;
}
int main() {
    string str;
    cin >> str;
    int l = 0, r = 0, len = str.size();
    while(r<len){
        if(str[r] == '&' && str[r+1] == '(' && str[r-1] == ')'){
            op(l, r, str);
            r++;
            l = r;
        }
        else if(str[r] == '>' && str[r+1] == '(' && str[r-1] == ')'){
            op(l, r, str);
            cout << endl;
            op(r + 1, len, str);
            break;
        }
        else{
            r++;
        }
    }
    return 0;
}