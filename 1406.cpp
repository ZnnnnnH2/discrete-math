#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef int *intt;
typedef char *charr;

const int inf = 0x3f3f3f3f;
const int N = 15;
int ans[N];
int final_ans[1000000][N];
int top = 0;
bool used[N];
int n;
void permutaion(int index)
{
    if (index > n)
    {
        for (int i = 1; i <= n; i++)
        {
            final_ans[top][i] = ans[i];
        }
        top++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i] and i != index)
        {
            used[i] = true;
            ans[index] = i;
            permutaion(index + 1);
            used[i] = false;
        }
    }
}
int main()
{
    std::cin >> n;
    permutaion(1);
    std::cout << top << std::endl;
    for (int i = 0; i < top; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << final_ans[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}