// 실전문제 1. 왕실의 나이트
// 입력: 8x8 좌표 상에 나이트의 위치 (ex.a1)
// 출력: 나이트가 이동할 수 있는 경우의 수
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void setStep(vector<pair<int,int>> &step) 
{
    step.push_back(make_pair(-2,-1));   // L L U
    step.push_back(make_pair(-2,1));    // L L D
    step.push_back(make_pair(2,-1));    // R R U
    step.push_back(make_pair(2,1));     // R R D
    step.push_back(make_pair(-1,-2));    // L U U
    step.push_back(make_pair(1,-2));    // R U U
    step.push_back(make_pair(-1,2));    // L D D
    step.push_back(make_pair(1,2));     // R D D
    
}

int main()
{
    vector<pair<int,int>> step;
    setStep(step);
    string pos;
    cin >> pos;
    char x = pos[0], y = pos[1];
    int count = 0;
    for (int i=0; i<step.size(); i++) {
        char tmpX = x, tmpY = y;
        tmpX += step[i].first;
        tmpY += step[i].second;
        if (tmpX >= 'a' && tmpX <= 'h' && tmpY >= '1' && tmpY <= '8')
            count++;
    }
    cout << count << endl;
}