#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int MAX_STEP = 301;
int n, step = 1, result;

int stepInfo[MAX_STEP] = {0,};
queue<pair<int,int>> points; // 최대 점수 : {1칸이동 가능, 1칸이동 불가능}


int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // 입력 처리
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> stepInfo[i];
    }

    points.push({stepInfo[step],0}); // current point
    points.push({stepInfo[step+1],0}); // 1 step forward point
    points.push({0,0}); // 2 step forward point
    
    while (step < n) {
        pair<int,int> currPoint = points.front();
        points.pop();

        // cout << "step: " << step << " --> "; // for debugging
        // cout << currPoint.first << "," << currPoint.second << "\n"; // for debugging
        
        if (step + 1 <= n) { // 1 계단 이동 가능
            points.front().second = max(points.front().second, currPoint.first + stepInfo[step+1]);
        }
        if (step + 2 <= n) { // 2 계단 이동 가능
            points.back().first = max(points.back().first, currPoint.first + stepInfo[step+2]);
            points.back().first = max(points.back().first, currPoint.second + stepInfo[step+2]);
        }

        points.push({0,0}); // 2 step forward point
        step += 1;
    }

    result = max(points.front().first, points.front().second);
    // 출력
    cout << result << "\n";
    return 0;
}