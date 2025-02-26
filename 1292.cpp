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
const int N = 1e5 + 5;
bool yunhan(bool a, bool b)
{
    return !a || b;
}
bool op1(bool a, bool b, bool c, bool d, bool e)
{
    return (a || b || c) && (yunhan(d, e));
}
bool op2(bool a, bool b, bool c, bool d, bool e)
{
    return (a && d) || (b && e) || (c && d);
}
int main()
{
    int a, b, c, d, e;
    for (a = 0; a <= 1; a++)
    {
        for (b = 0; b <= 1; b++)
        {
            for (c = 0; c <= 1; c++)
            {
                for (d = 0; d <= 1; d++)
                {
                    for (e = 0; e <= 1; e++)
                    {
                        if (!(op1(a, b, c, d, e) && op2(a, b, c, d, e)))
                        {
                            cout << "不等价" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "等价" << endl;
    return 0;
}