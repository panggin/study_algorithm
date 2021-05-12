#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_NUM = 100000;

int n, k, result;
vector<bool> visited(MAX_NUM+1, false); // 중복 방문 방지

int bfs(int start, int end)
{
    queue<pair<int,int>> path; // pair<position, time>
    path.push({start,0});

    pair<int,int> curr;
    while(!path.empty()) {
        curr = path.front();
        path.pop();
        if (!visited[curr.first]) {
            visited[curr.first] = true;
            if (curr.first == end) return curr.second;
            if (curr.first-1 >= 0) path.push({curr.first-1, curr.second+1});
            if (curr.first+1 <= MAX_NUM) path.push({curr.first+1, curr.second+1});
            if (curr.first*2 <= MAX_NUM) path.push({curr.first*2, curr.second+1});
        }
    }
    return -1;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> k;
    result = bfs(n, k);
    cout << result << "\n";
}