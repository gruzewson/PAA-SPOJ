#include <iostream>
#include <vector>
using namespace std;

struct podzbior
{
    char znak;
    int i;
    int j;
};

int main()
{
    string napis2, napis1;
    int n, k, r;
    cin >> n;

    for (int x = 0; x < n; x++)
    {
        vector<podzbior> podz;
        cin >> r;
        cin >> napis1;

        cin >> k;
        cin >> napis2;

        int** tab = new int* [r + 1];
        for (int a = 0; a < r + 1; a++)
        {
            tab[a] = new int[k + 1];
        }

        //znajdywanie dlugosci najdluzszego podciagu
        for (int i = 0; i <= r; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (i == 0 || j == 0)
                    tab[i][j] = 0;
                else if (napis1[i - 1] == napis2[j - 1])
                {
                    tab[i][j] = tab[i - 1][j - 1] + 1;
                }
                else
                    tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
            }
        }

        // Zapisywanie treœci najd³u¿szego podci¹gu
        int r2 = r, k2 = k;
        while (r2 > 0 and k2 > 0)
        {
            if (tab[r2][k2] == tab[r2][k2 - 1])
            {
                k2 -= 1;
            }
            else if (tab[r2][k2] == tab[r2 - 1][k2])
            {
                r2 -= 1;
            }
            else if (tab[r2][k2] >= tab[r2 - 1][k2 - 1])
            {
                podz.push_back({ napis1[r2 - 1], r2, k2 });
                r2 -= 1;
                k2 -= 1;
            }
        }

        if (tab[r][k] > 0)
        {
            cout << "case " << x + 1 << " " << "Y" << endl;
            cout << tab[r][k] << endl;
            for (int y = podz.size() - 1; y >= 0; y--)
                cout << podz[y].znak << " " << podz[y].i << " " << podz[y].j << endl;
        }
        else
            cout << "case " << x + 1 << " " << "N" << endl;

        for (int i = 0; i <= r; i++)
        {
            delete[] tab[i];
        }
        delete[] tab;
    }

    return 0;
}
