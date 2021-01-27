// 기출문제 4. 만들 수 없는 금액
// 입력: 동전 개수
//       각 동전의 화폐 단위
// 출력: 주어진 동전들로 만들 수 없는 양의 정수 금액 중 최솟값

// keypoint: 출력값이 만들 수 없는 최솟값이므로 1 ~ (최솟값-1)까지는 모두 만들 수 있다

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // 동전 개수
vector<int> coins;

int main()
{
    // 입력 받기
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    // 동전 오름차순 정렬
    sort(coins.begin(), coins.end(), less<int>());
    
    int result = 1;
    for (int i=0; i<n; i++)
    {
        if (result < coins[i]) // 현재 가진 동전으로 만들 수 없는 수
            break;
        result += coins[i]; // 만들 수 없는 수 update
    }

    cout << result << endl;
}