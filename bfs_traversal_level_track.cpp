#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vsit[1005];
int level[1005];
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
            // int child = v[parent][i];
            // cout << child << endl;
            if (vsit[child] == false)
            {
                q.push(child);
                vsit[child] = true;
                level[child] = level[parent] + 1;
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
    int source;
    cin >> source;
    memset(vsit, false, sizeof(vsit));
    memset(level, -1, sizeof(level));
    bfs(source);
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << level[i] << endl;
    }

    return 0;
}