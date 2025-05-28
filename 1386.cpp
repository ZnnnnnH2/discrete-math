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
const int N = 100;
int n;
int opg[N][N];
int m;
int opm[N][N];
int phi[N];
bool is_qun;

// Check if phi is a homomorphism
bool is_homomorphism()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Check if phi(a*b) = phi(a)*phi(b)
            if (phi[opg[i][j]] != opm[phi[i]][phi[j]])
            {
                return false;
            }
        }
    }
    return true;
}

// Check if phi is injective (单同态)
bool is_injective()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (phi[i] == phi[j])
            {
                return false;
            }
        }
    }
    return true;
}

// Check if phi is surjective (满同态)
bool is_surjective()
{
    bool used[N] = {false};
    for (int i = 0; i < n; i++)
    {
        used[phi[i]] = true;
    }
    for (int i = 0; i < m; i++)
    {
        if (!used[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Read input
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> opg[i][j];
        }
    }

    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> opm[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> phi[i];
    }

    // Check if phi is a homomorphism
    bool is_hom = is_homomorphism();
    std::cout << (is_hom ? "Yes" : "No") << std::endl;

    if (is_hom)
    {
        bool inj = is_injective();
        bool surj = is_surjective();
        bool iso = inj && surj;

        std::cout << "单同态:" << (inj ? "Yes" : "No") << std::endl;
        std::cout << "满同态:" << (surj ? "Yes" : "No") << std::endl;
        std::cout << "同构:" << (iso ? "Yes" : "No") << std::endl;
    }

    return 0;
}