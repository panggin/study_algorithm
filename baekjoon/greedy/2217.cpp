#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, result = 0;
vector<int> weight;

int main()
{
    // 입력 처리
    cin >> n;
    for (int i=0; i<n; i++) {
        int w;
        cin >> w;
        weight.push_back(w);
    }

    // 중량이 큰 순서로 정렬
    sort( weight.begin(), weight.end(), greater<int>() );

    // 1개부터 n개까지 사용했을 때 최대 중량
    int cnt = 1;
    for (auto w : weight) {
        result = max(result, w*cnt);
        cnt++;
    }

    // 최대 중량(결과) 출력
    cout << result << "\n";
}