#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 10001;

vector<int> graph[MAX_N];
int n, m, v;

void dfs(int start, vector<bool> &visited)
{
    cout << start << " "; // 출력
    for (auto node : graph[start]) {
        if (!visited[node]) {
            visited[node] = true;
            dfs(node, visited);
        }
    }
}

void bfs(int start, vector<bool> &visited)
{
    queue<int> path;
    path.push(start);
    visited[start] = true;

    while(!path.empty()) {
        int curr = path.front();
        path.pop();
        cout << curr << " "; // 출력
        for (auto node : graph[curr]) {
            if (!visited[node]) {
                visited[node] = true;
                path.push(node);
            }
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int a, b;
    cin >> n >> m >> v;
    while(m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end(), less<int>());
    }

    vector<bool> visitedDFS(n, false); 
    visitedDFS[v] = true;
    vector<bool> visitedBFS(n, false); 
    visitedBFS[v] = true;

    dfs(v, visitedDFS);
    cout << "\n";
    bfs(v, visitedBFS);
    cout << "\n";
}