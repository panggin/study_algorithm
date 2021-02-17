#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n, result = 0;
vector< pair<int, int> > meetings; 

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    // 입력 처리
    cin >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        meetings.push_back({a,b});
    }

    // 회의 정보 정렬 - 끝나는 시간이 작은 순서대로
    sort(meetings.begin(), meetings.end(), compare);

    // 회의의 최대 개수 계산
    int end = meetings[0].second;
    result += 1;
    for (int i=1; i<n; i++) {
        if (end <= meetings[i].first) {
            end = meetings[i].second;
            result += 1;
        }
    }
    
    // 결과 출력
    cout << result << "\n";
}