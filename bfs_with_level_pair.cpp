#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vsit[1005];
void bfs(int source, int dest)
{
    queue<pair<int,int>> q;
    q.push({source,0});
    vsit[source] = true;
    bool peyechi=false;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int parent =p.first;
        int parent_level= p.second;
        if(parent==dest)
        {
            cout<<parent_level<<endl;
            peyechi=true;
        }
        for (int child : v[parent])
        {
            if (vsit[child] == false)
            {
                q.push({child,parent_level+1});
                vsit[child] = true;
        
            }
        }
    }
    if(peyechi==false)
    {
        cout<< -1<<endl;
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
    bfs(source,9);
    bfs(source,0);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " " << endl;
    // }

    return 0;
}