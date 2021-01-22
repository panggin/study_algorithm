// 실전문제 2. 숫자 카드 게임
// 입력: 카드를 놓은 행, 열
//     각 카드에 적힌 숫자 배열
// 출력: 각 행에서 뽑은 가장 작은 수 중 가장 큰 수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100;

void display(vector<vector<int>> arr, int row, int col)
{
    for (int r=0; r<row; r++) {
        for (int c=0; c<col; c++) {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // input
    vector<vector<int>> cards; // 2차원 벡터 생성
    int row, col;
    cin >> row >> col;

    for (int r=0; r<row; r++) {
        vector<int> tmp;
        for (int c=0; c<col; c++) {
            int num;
            cin >> num;
            tmp.push_back(num);
        }
        cards.push_back(tmp);
    }
    //display(cards, row, col);
    
    // calculate
    vector<int> minNums;
    for (int r=0; r<row; r++) {
        vector<int> tmp = cards[r];
        // sort(tmp.begin(), tmp.end());
        // int min = tmp[0];
        int min = *min_element(tmp.begin(), tmp.end()); // 최솟값 찾기
        minNums.push_back(min);
    }
    // sort(minNums.begin(), minNums.end(), greater<int>());
    // cout << minNums[0] << endl;
    int max = *max_element(minNums.begin(), minNums.end()); // 최댓값 찾기
    cout << max << endl;
    return 0;
}