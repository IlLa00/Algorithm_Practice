#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int N, M, V;

void dfs(int start) 
{
    visited[start] = true;
    cout << start << " ";

    for (int next_node : adj[start]) 
    {
        if (!visited[next_node]) 
            dfs(next_node);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) 
    {
        int current_node = q.front();
        q.pop();
        cout << current_node << " ";

        for (int next_node : adj[current_node]) 
        {
            if (!visited[next_node]) 
            {
                q.push(next_node);
                visited[next_node] = true;
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> V;

    adj.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; ++i) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) 
        sort(adj[i].begin(), adj[i].end());

    dfs(V);
    cout << "\n";

    fill(visited.begin(), visited.end(), false);

    bfs(V);
    cout << "\n";

    return 0;
}