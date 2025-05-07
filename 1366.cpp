#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Matrix multiplication with modulo
vector<vector<long long>> multiply(const vector<vector<long long>> &a, const vector<vector<long long>> &b, int n)
{
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] = (result[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    return result;
}

// Matrix exponentiation by squaring
vector<vector<long long>> matrixPower(vector<vector<long long>> matrix, int n, int power)
{
    // Initialize result as identity matrix
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        result[i][i] = 1;
    }

    while (power > 0)
    {
        if (power & 1)
        {
            result = multiply(result, matrix, n);
        }
        matrix = multiply(matrix, matrix, n);
        power >>= 1;
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    // Read input matrix
    vector<vector<long long>> matrix(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Calculate matrix power
    vector<vector<long long>> result = matrixPower(matrix, n, m);

    // Output result
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j];
            if (j < n - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
