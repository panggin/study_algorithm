// 기출문제 4. 치킨 배달
// 입력: n(도시 크기 n x n) m(가장 큰 수익을 낼 수 있는 치킨집의 최대 개수)
// 출력: 폐업시키지 않을 치킨집을 최대 m개 골랐을 때 도시의 치킨 거리의 최솟값
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;

const int MAX_SIZE = 51;

int n, m;
vector<pair<int,int>> chickens; // 전체 치킨짐
vector<pair<int,int>> houses; // 전체 일반집


// 치킨 거리의 합을 계산하는 함수
int getSum(vector<pair<int, int>> candidates) {
    int result = 0;
    // 모든 집에 대하여
    for (int i = 0; i < houses.size(); i++) {
        int hx = houses[i].first;
        int hy = houses[i].second;
        // 가장 가까운 치킨 집을 찾기
        int temp = INT_MAX;
        for (int j = 0; j < candidates.size(); j++) {
            int cx = candidates[j].first;
            int cy = candidates[j].second;
            temp = min(temp, abs(hx - cx) + abs(hy - cy));
        }
        // 가장 가까운 치킨 집까지의 거리를 더하기
        result += temp;
    }
    // 치킨 거리의 합 반환
    return result;
}

int main()
{
    // 입력 처리
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            int inp;
            cin >> inp;
            if (inp == 1)
                houses.push_back({i,j});
            else if (inp == 2)
                chickens.push_back({i,j});
        }
    }

    // m개의 치킨집 선택 --> 선택 여부 저장
    vector<bool> selected(chickens.size(), false);
    fill(selected.end() - m, selected.end(), true);

    int result = INT_MAX;
    do {
        vector<pair<int,int>> candidates; // 선택된 치킨집 좌표 저장
        for (int i=0; i<chickens.size(); i++)
        {
            if (selected[i])
                candidates.push_back(chickens[i]);
        }
        result = min(result, getSum(candidates));

    } while(next_permutation( selected.begin(), selected.end() ));

    cout << result << "\n";

}