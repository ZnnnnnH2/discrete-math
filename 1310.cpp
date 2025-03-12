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
string change(string str)
{
    int yxj[200];  // 运算符优先级
    char stack[N]; // 保存运算符的栈
    memset(yxj, 0, sizeof(yxj));
    memset(stack, 0, sizeof(stack));
    int top = 0;   // 栈顶指针
    yxj['!'] = 1;
    yxj['&'] = 2;
    yxj['|'] = 3;
    yxj['>'] = 4;
    yxj['-'] = 5;
    yxj['('] = 6;
    int len = str.size();
    string s = ""; // 保存后缀表达式
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            s += str[i];
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
                while (top > 0 and yxj[stack[top - 1]] <= yxj[str[i]])
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
bool ans[N]; // 保存计算结果的栈
bool pqr[4]; // 保存p q r的真值

bool jisuan(string s)
{
    memset(ans, 0, sizeof(ans));
    int mun = 0;
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans[mun++] = pqr[s[i] - 'p'];
        }
        else
        {
            switch (s[i])
            {
            case '!':
                ans[mun - 1] = !ans[mun - 1];
                break;
            case '&':
                ans[mun - 2] = ans[mun - 1] & ans[mun - 2];
                mun--;
                break;
            case '|':
                ans[mun - 2] = ans[mun - 1] | ans[mun - 2];
                mun--;
                break;
            case '>':
                ans[mun - 2] = !ans[mun - 2] | ans[mun - 1];
                mun--;
                break;
            case '-':
                ans[mun - 2] = ans[mun - 2] == ans[mun - 1];
                mun--;
                break;
            }
        }
    }
    return ans[0];
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        string str1, str2;
        cin>>str1>>str2;
        string s1 = change(str1);
        string s2 = change(str2);
        for (int i = 0; i <= 3;i++){
            pqr[0] = i & 1;
            pqr[1] = (i >> 1) & 1;
            if(jisuan(s1)){
                if(!jisuan(s2)){
                    cout << "Invalid" << endl;
                    goto end;
                }
            }
        }
        cout<<"Valid"<<endl;
    end:;
    }
    return 0;
}