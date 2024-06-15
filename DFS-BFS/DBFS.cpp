#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& sasiedzi, int start, vector<bool> &visited)
{
    queue<int> que;
    visited.resize(sasiedzi.size(), false);

    visited[start] = true;
    que.push(start);
    while (!que.empty())
    {
        cout << que.front() << " ";
        int front = que.front();
        que.pop();
        for (int i = 0; i < sasiedzi[front].size(); i++)
        {
            if (visited[sasiedzi[front][i]] == false)
            {
                que.push(sasiedzi[front][i]);
                visited[sasiedzi[front][i]] = true;
            }

        }
    }
    cout << endl;
}

void dfs(vector<vector<int>>& sasiedzi, int start, vector<bool>& visited)
{
    visited[start] = true;
    cout << start << " ";

    for (int i = 0; i < sasiedzi[start].size(); i++)
    {
        if (visited[sasiedzi[start][i]] == false)
        {
            dfs(sasiedzi, sasiedzi[start][i], visited);
        }
    }
}

int main()
{
    int t, n, m, i, sasiad;
    cin >> t;
    vector<vector<int>> sasiedzi;
    vector<bool> visited;
    for (int y = 0; y < t; y++)
    {
        sasiedzi.clear();
        //wczytanie grafu i sasiadow
        cin >> n;
        sasiedzi.resize(n + 1);
        for (int s = 0; s < n; s++)
        {
            cin >> i;
            cin >> m;
            for (int x = 0; x < m; x++)
            {
                cin >> sasiad;
                sasiedzi[i].push_back(sasiad);
            }
        }

        int z1 = 2, z2 = 2;
        //wczytanie zapytan
        cout << "graph " << y + 1 << endl;
        while (z1 != 0 || z2 != 0)
        {
            cin >> z1;
            cin >> z2;
            visited.clear();
            if (z2 == 0 && z1 != 0)
            {
                visited.resize(sasiedzi.size(), false);
                dfs(sasiedzi, z1, visited);
                cout << endl;
            }
            else if (z2 == 1)
            {
                bfs(sasiedzi, z1, visited);
            }
        }
    }
    return 0;
}
