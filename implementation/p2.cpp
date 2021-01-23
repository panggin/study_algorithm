// 실전문제 2. 게임 개발
// 입력:  n n  // n r n 맵 생성
//     시작 좌표, 바라보는 방향(0:북, 1:동, 2:남, 3:서)
//     n r n 맵 구성 (1:바다, 0:육지)
// 출력: 이동을 마친후 캐릭터가 방문한 칸의 수
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int MAX_SIZE = 50;
const int USER_INFO = 3;

int map[MAX_SIZE][MAX_SIZE] = {1,};
int user[USER_INFO];
vector<pair<int, int>> searchLoop;

void initDirecttion(vector<pair<int, int>>& sLoop)
{
    // 이동 방향별 dx, dy
    sLoop.push_back(make_pair(-1,0)); // 북
    sLoop.push_back(make_pair(0,1)); // 동
    sLoop.push_back(make_pair(1,0));  // 남
    sLoop.push_back(make_pair(0,-1));  // 서
}

int searchPath(int row, int col, int &count)
{
    for (int i=0; i<4; i++) 
    {
        int r = user[0], c = user[1]; // 현재 위치
        user[2] == 0 ? user[2]=3 : user[2]--; // 회전

        int dx = searchLoop[user[2]].first;
        int dy = searchLoop[user[2]].second;
        r += dx; c += dy; // 위치 이동
        // cout << r << " " << c << " >> "; // for debugging

        if (r >= 0 && r <row && c >= 0 && c < col && map[r][c] == 0) 
        { // 이동 가능함
            count++;
            map[r][c] = 2;
            user[0] = r; user[1] = c;
            // cout << "\ngo\n"; // for debugging
            return 0;
        }
    }
    return -1;
}

int main()
{
    initDirecttion(searchLoop);
    int count = 1;

    int row, col;
    cin >> row >> col;
    cin >> user[0] >> user[1] >> user[2];
    for (int r=0; r<row; r++) {
        for (int c=0; c<col; c++) {
            cin >> map[r][c];
        }
    }

    int checker = 0;
    while (checker != -1) {
        checker = searchPath(row, col, count);
    }
    cout << count << endl;
}