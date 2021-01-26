// 미로 탈출
// 입력: n, m (n x m 크기의 미로)
//       미로 정보(1: 길, 0: 벽)
// 출력: (1,1)에서 (n,m)까지 이동, 최소 이동 칸의 개수

// keypoint: 이동 횟수를 그래프에 저장하여 최소 이동 횟수 확인

#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

const int MAX_SIZE = 201;

int n, m;
int graph[MAX_SIZE][MAX_SIZE] = {0,};

int count_bfs()
{
    queue<pair<int,int>> bfsQueue;

    // 시작 노드 설정
    bfsQueue.push({1,1});

    while (!bfsQueue.empty())
    {
        // 큐의 맨 앞 노드를 현재 노드로 설정
        pair<int,int> node = bfsQueue.front();
        bfsQueue.pop();

        int x = node.first;
        int y = node.second;
        int count = graph[x][y]; // 이동한 칸 수를 그래프에 기록

        if (x == n && y == m)
            return count;

        // 이동 가능한 노드 큐에 삽입
        if (x+1 <= n && graph[x+1][y] == 1) 
        { // 아래쪽 이동
            bfsQueue.push({x+1,y});
            graph[x+1][y] = count + 1;
        } 
        if (y+1 <= m && graph[x][y+1] == 1)
        { // 오른쪽 이동
            bfsQueue.push({x,y+1});
            graph[x][y+1] = count + 1;
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            scanf("%1d", &graph[i][j]);

    int result = count_bfs();
    cout << result << "\n";

}