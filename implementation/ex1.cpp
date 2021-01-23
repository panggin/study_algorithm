// 예제 1. 상하좌우
// 입력: 공간 크기(N)
//    L, R, U, D (왼쪽, 오른쪽, 위쪽, 아래쪽)
// 출력: 도착 좌표 (시작점: 1,1 / 가장 오른쪽 아래 좌표: N, N)
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar(); // '\n' 처리

    int x=1, y=1;
    char direct = 'A';
    while (direct != '\n') {
        direct = getchar();
        switch(direct) {
            case 'L':
                if (y == 1) break;
                y--; break;
            case 'R':
                if (y == n) break;
                y++; break;
            case 'U':
                if (x == 1) break;
                x--; break;
            case 'D':
                if (x == n) break;
                x++; break;
            default:
                break; // 공백 처리
        }
    }
    cout << x << " " << y << endl;
}