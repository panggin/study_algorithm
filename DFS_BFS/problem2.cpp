// 기출문제 2. 연구소
// 빈칸에 벽 3개를 세워 바이러스가 퍼지는 것을 막아보자
// 입력: 지도의 세로 크기 n, 가로 크기 m (n,m: 3~8)
//       지도 모양 (0: 빈칸, 1: 벽, 2: 바이러스 위치)
//                 (빈칸 개수: 3~, 바이러스 개수: 2~10)
// 출력: 안전 영역의 최대 크기

/*
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0 
0 1 0 0 0 0 0

27
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 8;

int n, m, result = 0;
int map[MAX_SIZE][MAX_SIZE]; // 입력된 맵
int tmpMap[MAX_SIZE][MAX_SIZE]; // 벽을 설치한 맵

// 상하좌우 x, y 이동
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

// 맵 상태 확인 함수
void displayMap()
{
    cout << "---- display map ----\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "------ finish ------\n";
}

// 바이러스가 퍼지는 함수
void virus(int x, int y)
{
    for (int i=0; i<4; i++) {
        // 이동
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 이동 가능한 공간
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (tmpMap[nx][ny] == 0) {
                tmpMap[nx][ny] = 2;
                virus(nx, ny); // 재귀호출
            }
        }
    }
}

int safeSpace()
{
    int count = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (tmpMap[i][j] == 0)
                count += 1;
        }
    }
    return count;
}

// DFS 탐색을 통해 울타리를 설치, 매번 안전 영역 크기 계산
void dfs(int count)
{
    // 울타리 3개가 모두 설치된 경우 - 재귀 종료 조건
    if (count == 3) {
        //  현재 맵 상태 복사
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                tmpMap[i][j] = map[i][j];
            }
        }
        // 바이러스 모두 퍼뜨리기
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (tmpMap[i][j] == 2)
                    virus(i,j);
            }
        }
        // 안전 영역 계산
        result = max(result, safeSpace());
        return;
    }
    // 빈 공간에 울타리 설치
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                count += 1;
                dfs(count);
                // 안전 공간 계산 후 값 복구
                map[i][j] = 0;
                count -= 1;
            }
        }
    }
}

int main()
{
    // 입력 처리
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    // 모든 경우의 안전 공간 개수 확인
    dfs(0);
    // 안전 공간 최대 개수 출력
    cout << result << "\n";
}