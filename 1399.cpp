#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <sstream>

typedef long long ll;
typedef int *intt;
typedef char *charr;

const int inf = 0x3f3f3f3f;
const int N = 30;
int n, m;
int line[N];
int input, output;
bool in[N];
void AND(int in1, int in2, int out)
{
    line[out] = line[in1] & line[in2];
}
void OR(int in1, int in2, int out)
{
    line[out] = line[in1] | line[in2];
}
void NOT(int in1, int out)
{
    line[out] = !line[in1];
}
void XOR(int in1, int in2, int out)
{
    line[out] = line[in1] ^ line[in2];
}
std::vector<int> xx;
std::vector<int> yy;
int main()
{
    std::cin >> n >> m;
    std::cin >> input >> output;
    for (int i = 1; i <= m; i++)
    {
        line[i] = 0;
    }
    for (int i = 1; i <= input; i++)
    {
        std::cin >> line[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        xx.clear();
        yy.clear();
        for (int i = 1; i <= x; i++)
        {
            int in;
            std::cin >> in;
            xx.push_back(in);
        }
        for (int i = 1; i <= y; i++)
        {
            int out;
            std::cin >> out;
            yy.push_back(out);
        }
        std::string op;
        std::cin >> op;
        if (op == "AND")
        {
            AND(xx[0], xx[1], yy[0]);
        }
        else if (op == "OR")
        {
            OR(xx[0], xx[1], yy[0]);
        }
        else if (op == "NOT")
        {
            NOT(xx[0], yy[0]);
        }
        else if (op == "XOR")
        {
            XOR(xx[0], xx[1], yy[0]);
        }
    }
    for (int i = m - output + 1; i <= m; i++)
    {
        std::cout << line[i] << " ";
    }
    return 0;
}