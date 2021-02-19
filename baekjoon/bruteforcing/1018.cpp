#include <iostream>
#include <string>
#include <vector>
using namespace std;

string boardW[8] = { // W 부터 시작되는 체스판
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string boardB[8] = { // B 부터 시작되는 체스판
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int n, m, result = 2500;
vector<string> board;

int main()
{
    // 입력 처리
    cin >> n >> m;
    getchar();
    for (int i=1; i<=n; i++) {
        string inp;
        getline(cin, inp);
        board.push_back(inp);
    }

    int lastX = n-7, lastY = m-7;
    for (int x=0; x<lastX; x++) {
        for (int y=0; y<lastY; y++) {
            // 8x8 보드 가져오기
            int endX = x+8, endY = y+8; 
            int countW = 0, countB = 0; // 칠해야하는 개수
        
            // 8x8 보드와 비교 체스판을 비교, count
            int by = 0;
            for (int i=x; i<endX; i++) {
                int bx = 0;
                for (int j=y; j<endY; j++) {
                    if (board[i][j] != boardW[bx][by]) // W 체스판과 비교
                        countW++;
                    if (board[i][j] != boardB[bx][by]) // B 체스판과 비교
                        countB++;
                    bx++;
                }
                by++;
            }

            int count = min(countW, countB);
            result = min (result, count);       
        }
    }
    // 결과 출력
    cout << result << "\n";
}