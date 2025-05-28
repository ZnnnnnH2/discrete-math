#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate(int n, int zeros, int ones, string current, vector<string> &result)
{
    if (zeros == n && ones == n)
    {
        result.push_back(current);
        return;
    }

    // 保证字典序，先加0再加1
    if (zeros < n)
    {
        generate(n, zeros + 1, ones, current + '0', result);
    }
    if (ones < zeros)
    {
        generate(n, zeros, ones + 1, current + '1', result);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> result;
    generate(n, 0, 0, "", result);
    printf("%d\n", (int)result.size());
    for (const string &s : result)
    {
        cout << s << endl;
    }

    return 0;
}