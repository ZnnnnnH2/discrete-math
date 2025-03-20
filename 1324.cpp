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
const int N=1e2;
string change(string str)
{
    int yxj[200];  // 运算符优先级
    char stack[N]; // 保存运算符的栈
    memset(yxj, 0, sizeof(yxj));
    memset(stack, 0, sizeof(stack));
    int top = 0; // 栈顶指针
    yxj['V'] = 1;
    yxj['E'] = 1;
    yxj['!'] = 1;
    yxj['&'] = 4;
    yxj['|'] = 5;
    yxj['>'] = 6;
    yxj['-'] = 7;
    yxj['('] = 8;
    int len = str.size();
    string s = ""; // 保存后缀表达式
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'V' || str[i] == 'E'){
            if(str[i+1] <'a' || str[i+1] > 'z'){
                printf("no\n");
                exit(0);
            }
        }
        if (str[i] == ' ')
        {
            continue;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z' && str[i] != 'V' && str[i] != 'E')
        {
            s += str[i];
        }
        else if(str[i]>='a' && str[i]<='z'){
            if(str[i-1]=='V' || str[i-1]=='E'){
                continue;
            }
            else{
                printf("no\n");
                exit(0);
            }
        }
        else if (str[i] == '(')
        {
            stack[top++] = str[i];
        }
        else if (str[i] == ')')
        {
            for (int j = top - 1; j >= 0; j--)
            {
                if (stack[j] == '(')
                {
                    top = j;
                    break;
                }
                s += stack[j];
            }
        }
        else
        {
            if (top == 0)
            {
                stack[top++] = str[i];
            }
            else
            {
                while (top > 0 and yxj[stack[top - 1]] < yxj[str[i]])
                {
                    s += stack[--top];
                }
                stack[top++] = str[i];
            }
        }
    }
    for (int i = top - 1; i >= 0; i--)
    {
        s += stack[i];
    }
    return s;
}
bool checks(string s){
    int length = s.size();
    int sta[N];
    int top = 0;
    for (int i = 0; i < length;i++){
        if(s[i]>='A' && s[i]<='Z' && s[i]!='V' && s[i]!='E'){
            sta[top++] = 0;
        }
        else if(s[i] == 'V'){
            if(top == 0){
                return 0;
            }
            sta[top - 1] = 1;
        }
        else if(s[i] == 'E'){
            if(top == 0){
                return 0;
            }
            sta[top - 1] = 2;
        }
        else if(s[i] == '!'){
            if(top == 0){
                return 0;
            }
            sta[top - 1] = !sta[top - 1];
        }
        else if(s[i] == '&'){
            if(top < 2){
                return 0;
            }
            top--;
            sta[top - 1] = sta[top - 1] && sta[top];
        }
        else if(s[i] == '|'){
            if(top < 2){
                return 0;
            }
            top--;
            sta[top - 1] = sta[top - 1] || sta[top];
        }
        else if(s[i] == '>'){
            if(top < 2){
                return 0;
            }
            top--;
            sta[top - 1] = !sta[top - 1] || sta[top];
        }
        else if(s[i] == '-'){
            if(top < 2){
                return 0;
            }
            top--;
            sta[top - 1] = sta[top - 1] == sta[top];
        }
    }
    if(top != 1){
        return 0;
    }
    return 1;
}
int main()
{ // !A&B|C>D-!F|G&H>I-J|K!
    string str;
    cin >> str;
    string s = change(str);
    cout << s << endl;
    if (checks(s)){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;
}