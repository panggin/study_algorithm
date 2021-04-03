#include <iostream>
using namespace std;

const int MAX_N = 128;

int n, white = 0, blue = 0;
int paper[MAX_N][MAX_N] = {0,};

/* debugging function */
void printArr(int size, int r, int c)
{
    cout << "### start: (" << r << ", " << c << ")\n";
    for (int i=r; i<r+size; i++) {
        for (int j=c; j<c+size; j++) {
            cout << paper[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "----------------------\n";
}


// 특정 크기의 종이의 색깔이 모두 동일한지 확인하는 함수
int detectColor(int size, int r, int c)
{
    int color = paper[r][c]; // 시작점
    // printArr(size, r, c); // for debugging
    for (int i=r; i<r+size; i++) {
        for (int j=c; j<c+size; j++) {
            if (color != paper[i][j]) {
                return -1;
            }
        }
    }
    return color; // 0: white, 1: blue
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // 입력 처리
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> paper[i][j];
            if (paper[i][j] == 0) white += 1;
            else blue += 1;
        }
    }

    int size = 2;
    while (size <= n) {
        for (int row = 0; row < n; row += size) {
            for (int col = 0; col < n; col += size) {
                int colorResult = detectColor(size, row, col);
                if (colorResult == 0) {
                    white -= 3;
                } else if (colorResult == 1) {
                    blue -= 3;
                }
            }
        }
        size *= 2; // 색종이 크기 확장
    }

    cout << white << "\n" << blue << "\n";
    return 0;
}