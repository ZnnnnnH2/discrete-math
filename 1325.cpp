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
const int inf = 0x3f3f3f3f;
const int N = 1e3 + 5;
int sta_kuohuao[N];
int top_kuohuao = 0;
string changestr(string str)
{
    int length = str.length();
    string s = "";
    for (int i = 0; i < length;i++){
        if(str[i]=='x' || str[i] == 'y' || str[i] == 'a'){
            s += str[i];
        }
        else if(str[i] == ')'){
            int index = sta_kuohuao[--top_kuohuao];
            s += str[index];
        }
        else if(str[i] == 'f'){
            sta_kuohuao[top_kuohuao++] = i;
        }
        else if(str[i] == 'F'){
            sta_kuohuao[top_kuohuao++] = i;
        }
        else if(str[i] == 'G'){
            sta_kuohuao[top_kuohuao++] = i;
        }
        else if(str[i] == 'L'){
            sta_kuohuao[top_kuohuao++] = i;
        }
    }
    return s;
}
int xy[] = {0, 0};
int valxy[] = {0, 0};
bool eval(string s){
    int sta[N];
    int top = 0;
    int len = s.length();
    for (int i = 0; i < len;i++){
        if(s[i] == 'x' || s[i] == 'y'){
            sta[top++] = valxy[s[i] - 'x'];
        }
        else if(s[i] == 'a'){
            sta[top++] = 2;
        }
        else if(s[i] == 'f'){
            int ans = sta[top - 1];
            if(ans == 2){
                ans = 3;
            }
            else if(ans == 3){
                ans = 2;
            }
            sta[top - 1] = ans;
        }
        else if(s[i] == 'F'){
            int ans = sta[top - 1];
            if(ans == 2){
                ans = 0;
            }
            else if(ans == 3){
                ans = 1;
            }
            sta[top - 1] = ans;
        }
        else if(s[i] == 'G'){
            if(sta[top - 1] == 3 and sta[top -2] ==3){
                sta[top - 2] = 0;
                top--;
            }
            else{
                sta[top - 2] = 1;
                top--;
            }
        }
        else if(s[i] == 'L'){
            if(sta[top - 1] == 2 and sta[top - 2] == 2 || sta[top - 1] == 3 and sta[top - 2] == 3){
                sta[top - 2] = 1;
                top--;
            }
            else{
                sta[top - 2] = 0;
                top--;
            }
        }
    }
    return sta[0];
}
int main()
{
    string s;
    cin >> s;
    // cout << s << endl;
    int i = 0;
    while(s[i] == 'V' || s[i] == 'E'){
        if(s[i] == 'V'){
            xy[s[i + 1] - 'x'] = 1;
        }
        else{
            xy[s[i + 1] - 'x'] = -1;
        }
        i+=2;
    }
    string str = changestr(s.substr(i));
    int ans = inf;
    for (int x = 2; x <= 3;x++){
        int fin = inf;
        valxy[0] = x;
        if(xy[1] == 0){
            fin = eval(str);
        }
        else{
            for (int y = 2; y <= 3;y++){
                valxy[1] = y;
                int temp = eval(str);
                if(fin == inf){
                    fin = temp;
                }
                else if(xy[1] == 1){
                    fin = fin & temp;
                }
                else{
                    fin = fin | temp;
                }
            }
        }
        if(ans == inf){
            ans = fin;
        }
        else {
            if(xy[0] == 1){
                ans = ans&fin;
            }
            else{
                ans = ans | fin;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

//G(L(x,F(a)),f(x))