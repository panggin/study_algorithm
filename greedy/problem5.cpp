// 기출문제 5. 볼링공 고르기
// 입력: 볼링공의 개수 n, 공의 최대 무게 m
//       볼링공의 무게 n개 만큼 입력
// 출력: 두 사람이 볼링공을 고르는 경우의 수 (같은 무게로 2개는 고를 수 없음)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> weights;

int main()
{
    // 입력 받기
    int w;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> w;
        weights.push_back(w);
    }

    // 오름차순 정렬
    sort(weights.begin(), weights.end(), less<int>());

    // 무게 종류의 개수 구하기
    int result = 0;
    for (int i=0; i<n; i++)
    {
        int count = 0;
        int tmpWeight = weights[i];
        for (int j=i; j<n; j++)
        {
            if (tmpWeight != weights[j])
                count++;
        }
        result += count;
    }

    // 경우의 수 구하기
    cout << result << endl;
}