// 기출문제 1. 모험가 길드
// 공포도가 x인 모험가는 반드시 x명과 그룹을 이루어야 함
// 입력: 모험가 수
//       모험가의 공포도
// 출력: 여행을 떠날 수 있는 그룹 수의 최댓값
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> states;

void display(int n)
{
    for (int i=0; i<n; i++)
        cout << states[i] << " ";
    cout << "\n";
}

int main()
{
    // 입력 받기
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int state;
        cin >> state;
        states.push_back(state);
    }

    sort(states.begin(), states.end(), less<int>()); // 오름차순 정렬
    // display(n);

    int count = 0, maxState, result = 0;
    for (int i=0; i<n; i++)
    {
        count += 1; // 현재 그룹 인원 1 추가
        maxState = states[i]; // 현재 그룹 내 최고 공포도 (updtate)

        if (count == maxState) { // 그룹 인원 = 최고 공포도
            count = 0; // 그룹 인원 리셋
            result++; // 그룹 수 1 추가
        }
    }

    cout << result << endl;
}