#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vsit[1005];
int level[1005];
int par[1005];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vsit[source] = true;
    level[source] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        // cout << parent << endl;
        for (int child : v[parent])
        {
            if (vsit[child] == false)
            {
                q.push(child);
                vsit[child] = true;
                level[child] = level[parent] + 1;
                par[child] = parent;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int source, dest;
    cin >> source >> dest;
    memset(vsit, false, sizeof(vsit));
    memset(level, -1, sizeof(level));
    memset(par, -1, sizeof(par));
    bfs(source);
    int x = dest;
    vector<int> path;
    while (x != -1)
    {
        // cout << x << " ";
        path.push_back(x);
        x = par[x];
    }
    reverse(path.begin(), path.end());
    for (int val : path)
    {
        cout << val << " ";
    }
    return 0;
}