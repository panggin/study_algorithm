#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int t, n, result = 0;
vector< pair<int,int> > scores;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}

int main()
{
    cin >> t;
    for (int i=0; i<t; i++) {
        // 테스트 케이스 입력 처리
        cin >> n;
        for (int j=0; j<n; j++) {
            int s1, s2;
            cin >> s1 >> s2;
            scores.push_back({s1,s2});
        }

        // 첫 번째 성적을 기준으로 오름차순 정렬
        // 두 번째 성적에서 내림차순에 어긋나는 지원자 제외
        sort(scores.begin(), scores.end(), compare);
        int prev = scores[0].second;
        for (auto s : scores) {
            if (prev >= s.second) {
                result += 1;
                prev = s.second;
            }
        }

        cout << result << "\n";

        scores.clear();
        result = 0;
    }
}