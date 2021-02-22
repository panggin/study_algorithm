#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n;
vector< pair<int,int> > points;

bool compare(pair<int,int> a, pair<int,int> b)
{
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main()
{
    // cin 속도 up
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // 입력 처리
    cin >> n;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x,y});
    }

    // 정렬
    sort (points.begin(), points.end(), compare);

    // 출력
    for (auto p : points) {
        cout << p.first << " " << p.second << "\n";
    }
}