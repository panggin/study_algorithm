#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 1001;

int n, m, result = 0;
vector<int> graph[MAX_N];

void bfs(vector<bool> &visited, int start)
{
    queue<int> bfsQueue;
    bfsQueue.push(start);
    visited[start] = true;

    while (!bfsQueue.empty()) {
        int currNode = bfsQueue.front();
        bfsQueue.pop();
        for (auto neighbor : graph[currNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                bfsQueue.push(neighbor);
            }
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    int node1, node2;
    while (m--) { // make graph
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    vector<bool> visited(n+1, false);
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            result += 1;
            bfs(visited, i);
        }
    }

    cout << result << "\n";
}