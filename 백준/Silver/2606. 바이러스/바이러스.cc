#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
vector<int> adj[101]; 
bool visited[101];   

void dfs(int current) 
{
    visited[current] = true;

    for (int i = 0; i < adj[current].size(); i++) 
    {
        int next = adj[current][i];

        if (!visited[next]) 
        {
            answer++;       
            dfs(next);      
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1);

    cout << answer;

    return 0;
}