// 음료수 얼려 먹기
// 입력: 세로 n 가로 m
//       얼음 틀 형태 주어짐(구멍: 0, 막힘: 1)
// 출력: 한 번에 만들 수 있는 얼음 개수

// keypoint: 그래프의 모든 노드를 dfs/bfs로 탐색하여 연결 여부 확인

#include <iostream>
#include <cstdio>
#include <utility>
using namespace std;

const int MAX_SIZE = 1000;

int n, m;
int graph[MAX_SIZE][MAX_SIZE];

int dfs(int r, int c)
{
    // 재귀 함수 종료 조건: 그래프 범위를 벗어남
    if (r<0 || r>=n || c<0 || c>=m)
        return 0;

    // 현재 노드 방문 여부 확인
    if (graph[r][c] == 0)
    {
        graph[r][c] = 1; // 방문 처리
        dfs(r-1, c); // 상
        dfs(r+1, c); // 하
        dfs(r, c-1); // 좌
        dfs(r, c+1); // 우
        return 1;
    }
    return 0; // 현재 노드가 이미 방문한 노드
}

int main()
{
    // 입력 받기
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    int count = 0;
    // 각각의 노드를 dfs 수행
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if(dfs(i,j) == 1)
                count++;

    // 출력
    printf("%d", count);
}