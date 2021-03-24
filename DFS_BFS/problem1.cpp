// 기출문제 1. 특정 거리의 도시 찾기
// 입력: 도시의 개수 n, 도로의 개수 m, 거리 정보 k,  출발 도시의 번호 x
//       그래프 연결 정보
// 출력: 최단 거리가 k인 도시 번호 출력 (존재하지 않을 시 -1 출력)
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 300001;

int n, m, k, x;
vector<int> map[MAX_SIZE];

void searchPath(vector<int> &depth)
{
    // BFS 활용하여 최단 거리 구하기
    queue<int> nodes;

    // 시작 노드 설정
    nodes.push(x);
    depth[x] = 0;

    while(!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();

        int size = map[node].size();
        for (int i=0; i<size; i++) {
            int tmp = map[node][i];
            nodes.push(tmp);
            // 현재 노드 값과 (이전 노드값 + 1) 중 작은 값 저장
            depth[tmp] = min(depth[tmp], depth[node] + 1);
        }
    }
}

int main()
{
    // 입력 처리
    cin >> n >> m >> k >> x;
    for (int i=0; i<m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        map[v1].push_back(v2);
    }

    // 전체 노드의 최단거리 값 구하기
    vector<int> depth(n+1, INT_MAX); // 노드 깊이(최단 거리)
    searchPath(depth);

    // 최단 거리 값이 k와 같은 노드 출력
    int checker = -1;
    for (int i=1; i<=n; i++) {
        if (depth[i] == k) {
            cout << i << "\n";
            checker = 0;
        }
    }
    if (checker == -1)
        cout << checker << "\n";
}