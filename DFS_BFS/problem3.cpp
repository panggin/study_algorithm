// 기출문제 3. 경쟁적 전염
// 매초마다 상하좌우로 바이러스 증식, 번호가 낮은 바이러스가 먼저 증식
// 이미 어떠한 칸에 바이러스가 존재하다면 다른 바이러스가 증식 불가
// 입력: n, k (n x n 시험관, 1~k번의 바이러스)(n: 1~200, k: 1~1000)
//       시험관 정보
//       s, x, y
// 출력: s초 뒤의 (x,y)에 있는 바이러스 종류, 존재하지 않을 시 0 출력
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Virus {
    public:
        int type;
        int second;
        int vx;
        int vy;
    
    Virus(int type, int second, int r, int c) {
        this->type = type;
        this->second = second;
        this->vx = r;
        this->vy = c;
    }
    // 정렬 (type 숫자가 작은 순서대로)
    bool operator < (Virus &other) {
        return this->type < other.type;
    }
};

const int MAX_SIZE = 201;

int n, k, s, x, y;
int plate[MAX_SIZE][MAX_SIZE];

vector<Virus> viruses;

// 상하좌우 x, y 이동 정보
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

// 시험관 상태를 보여주는 함수
void display()
{
    cout << "----- display -----\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << plate[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "------ end -------\n";
}

// 상하좌우로 바이러스를 증식시키는 함수
void virus(int type, int r, int c)
{
    // 상하좌우 모든 방향으로 증식
    for (int i=0; i<4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        // 이동 가능
        if (nr > 0 && nr <=n && nc > 0 && nc <= n) {
            if (tmp[nr][nc] == 0) {
                tmp[nr][nc] = type;
            }
        }
    }

}

// 모든 종류의 바이러스를 증식시키는 함수
void test()
{
    // 모든 종류 - 증식
    for (int type=1; type<=k; type++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (plate[i][j] == type) {
                    virus(type, i, j);
                }
            }
        }
    }

}

int main()
{
    // clock_t start, end, time; // for checking time

    // 입력 처리
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> plate[i][j];
            if (plate[i][j] != )
        }
    }
    cin >> s >> x >> y;

    // start = clock(); // 시간 측정 시작
    

    // s초 동안 바이러스 증식
    for (int time=0; time<s; time++) {
        // 시험관 정보 복사 (plate -> tmp)
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                tmp[i][j] = plate[i][j];               
            }
        }

        // 바이러스 증식
        test();

        // 증식 결과 시험관 반영 (tmp -> plate)
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                plate[i][j] = tmp[i][j];               
            }
        }
        // display(); // for debugging
    }
    // end = clock();
    // time = (end - start) / CLOCKS_PER_SEC;

    // (x,y) 바이러스 종류 출력
    cout << plate[x][y] << "\n";
    // cout << "time: " << time << " s\n";
}