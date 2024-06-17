#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> ksiazki(n);
    unordered_map<int, int> ksiazki_kopia;
    vector<int> k_numery;
    vector<int> wypisania;
    int counter = n - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> ksiazki[i];
        ksiazki_kopia[ksiazki[i]] = i;
    }

    deque<pair<int, int>> deq(ksiazki_kopia.begin(), ksiazki_kopia.end());
    sort(deq.begin(), deq.end());

    int input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        k_numery.push_back(input);
    }
    do
    {
        cin >> input;
        wypisania.push_back(input);
    } while (input != n);

    int wypis = 0;
    int current = 0;
    for (int i = 0; i < n; i++)
    {
        int ktora = k_numery[current] - 1;
        int index = deq.size() - ktora - 1;

        swap(ksiazki[ksiazki_kopia[deq[index].first]], ksiazki[counter]);

        ksiazki_kopia[ksiazki[ksiazki_kopia[deq[index].first]]] = ksiazki_kopia[deq[index].first];
        ksiazki_kopia[ksiazki[counter]] = counter;

        counter--;
        current++;
        deq.erase(deq.begin() + index);


        if (wypisania[wypis] == i + 1)
        {
            for (int x = 0; x < ksiazki.size(); x++)
            {
                cout << ksiazki[x] << " ";
            }
            cout << "\n";
            wypis++;
        }

    }
    return 0;
}



