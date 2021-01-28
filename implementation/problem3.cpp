// 기출문제 3. 뱀
// 시작위치: (1,1), 처음 이동은 오른쪽(R)을 향함
// 사과를 먹을 시 뱀의 길이가 늘어남
// 기어다니다 벽 또는 자기 자신의 몸에 부딪히면 게임이 끝남
// 입력: 보드의 크기 n (n x n 보드판) (n: 2 ~ 100)
//       사과의 개수 k (k: 0 ~ 100)
//       사과의 위치 (행, 열) -- > (1,1)에는 사과가 없음
//       뱀의 방향 전환 횟수
//       뱀의 방향 전환 정보 (게임 시작 후 x초 후 전환, 이동방향(LRUD))

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int MAX_SIZE = 101;

int n, k, cnt; // 보드판 크기, 사과의 개수, 방향 전환 횟수
int map[MAX_SIZE][MAX_SIZE] {0,}; // 뱀, 사과 위치 정보 저장
char info[MAX_SIZE] = {0,}; // 방향 전환 정보 저장

void display()
{
    for (int i=0; i<n+2; i++)
    {
        for (int j=0; j<n+2; j++)
            cout << map[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void move(char direction, pair<int, int> &pos)
{
    switch(direction)
    {
        case 'R':
            pos.second += 1;
            break;
        case 'L':
            pos.second -= 1;
            break;
        case 'U':
            pos.first -= 1;
            break;
        case 'D':
            pos.first += 1;
            break;
    }
}

int playGame()
{
    queue<pair<int, int>> snack;
    snack.push({1,1});
    map[1][1] = 0;

    char d = 'R';
    int time = 0;

    while(1)
    {
        // 1. 머리를 다음 칸에 위치
        pair<int, int> head = snack.back();
        move(d, head);
        snack.push(head);
        
        int checker = map[head.first][head.second];
        // 1-1. 게임 종료
        if (checker == 0)
            return time;
        // 2. 사과(2)가 있다면 꼬리 이동 X
        if (checker == 1)
        { // 3. 사과가 없다면(1) 꼬리가 위치한 칸 비우기
            pair<int, int> tail = snack.front();
            map[tail.first][tail.second] = 1;
            snack.pop();
        }
        // 머리가 이동한 칸 채우기
        map[head.first][head.second] = 0;

        // 시간 update
        time += 1;

        // 방향 update
        if (info[time] != 0)
            d = info[time];

        cout << "time: " << time << " d: " << d << "\n";
        cout << "head: (" << snack.back().first << "," << snack.back().second << ")  "
             << "tail: (" << snack.front().first << "," << snack.front().second << ")\n";
        display();
    }
}

int main()
{
    // 입력 처리
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            map[i][j] = 1; // 이동 가능한 칸 1로 표현
    
    for (int i=0; i<k; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 2; // 사과 2로 표현
    }
    
    cin >> cnt;
    for (int i=0; i<cnt; i++)
    {
        int t; char d;
        cin >> t >> d;
        info[t] = d;
    }

    int time = playGame();
    cout << time << "\n";
}