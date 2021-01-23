#include <iostream>
using namespace std;

const int MAX_SIZE = 50;
const int USER_INFO = 3;
const int DIRCETION = 4;

int main()
{
    int map[MAX_SIZE][MAX_SIZE] = {1,};
    int user[USER_INFO];
    // 북, 동, 남, 서 dx, dy
    int dx[DIRCETION] = {-1, 0, 1, 0};
    int dy[DIRCETION] = {0, 1, 0, -1};

    int row, col;
    cin >> row >> col;
    cin >> user[0] >> user[1] >> user[2];

    for (int r=0; r<row; r++)
        for (int c=0; c<col; c++)
            cin >> map[r][c];

    int count = 1, checker = 0;
    while (checker != -1) {
        checker = -1; // 이동 가능한 지역 없음
        for (int i=0; i<DIRCETION; i++) 
        {
            int x = user[0], y = user[1];
            map[x][y] = 2; // 현재 지역 방문 표시

            user[2] == 0? user[2]=3 : user[2]--; // 방향 설정
            
            int d = user[2];
            x += dx[d]; y += dy[d];

            // cout << d << " " << x << " " << y << " >> ";

            if (x>=0 && x<row && y>=0 && y<col && map[x][y]==0)
            { // 이동 가능한 지역 발견
                user[0] = x; user[1] = y;
                count++; checker = 0;
                // cout << "move\n";
                break;
            }
        }
    }
    cout << count << endl;

    // // 맵 확인
    // for (int r=0; r<row; r++) {
    //     for (int c=0; c<col; c++) {
    //         cout << map[r][c] << " ";
    //     }
    //     cout << "\n";
    // }

}