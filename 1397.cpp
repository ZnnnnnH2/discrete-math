#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
typedef long long ll;
typedef int *intt;
typedef char *charr;

const int inf = 0x3f3f3f3f;
const int N = 25;
int op[N][N];
int child[N];
int n, m;
std::vector<int> get_left_company_group(int a)
{
    std::vector<int> group;
    for (int i = 0; i < m; i++)
    {
        int left = op[a][child[i]];
        group.push_back(left);
    }
    sort(group.begin(), group.end());
    return group;
}
std::vector<int> get_right_company_group(int a)
{
    std::vector<int> group;
    for (int i = 0; i < m; i++)
    {
        int right = op[child[i]][a];
        group.push_back(right);
    }
    sort(group.begin(), group.end());
    return group;
}
bool is_equal(std::vector<int> &a, std::vector<int> &b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
bool is_correct_group()
{
    for (int i = 0; i < n; i++)
    {
        std::vector<int> left_group = get_left_company_group(i);
        std::vector<int> right_group = get_right_company_group(i);
        if (!is_equal(left_group, right_group))
        {
            return false;
        }
    }
    return true;
}
std::set<int> divide_group;
void get_divide_group()
{
    for (int i = 0; i < n; i++)
    {
        if (divide_group.find(i) == divide_group.end())
        {
            std::vector<int> left_group = get_left_company_group(i);
            printf("{");
            for (int j = 0; j < m - 1; j++)
            {
                divide_group.insert(left_group[j]);
                printf("%d,", left_group[j]);
            }
            printf("%d}\n", left_group[m - 1]);
            divide_group.insert(left_group[m - 1]);
        }
    }
}
int main()
{

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> op[i][j];
        }
    }
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        std::cin >> child[i];
    }
    if (!is_correct_group())
    {
        std::cout << "No" << std::endl;
        return 0;
    }
    std::cout << "Yes" << std::endl;
    get_divide_group();
    return 0;
}