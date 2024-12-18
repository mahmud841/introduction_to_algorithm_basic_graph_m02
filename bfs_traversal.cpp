#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vsit[1005];
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vsit[source] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        cout << parent << endl;
        // for (int i = 0; i < v[parent].size(); i++)
        for (int child : v[parent])
        {
            // int child = v[parent][i];
            // cout << child << endl;
            if (vsit[child] == false)
            {
                q.push(child);
                vsit[child] = true;
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
    bfs(source);

    return 0;
}