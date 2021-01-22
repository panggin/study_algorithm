// 실전문제3. 1이 될 때까지
// 입력: n, k (2 <= n, k <= 100,000)
// 과정: 1. n - 1       2. n / k
// 출력: n이 1이 될 때까지의 과정의 최소 수행 횟수
#include <iostream>
using namespace std;

int main()
{
    int n, k, count = 0;
    cin >> n >> k;
    while (1) {
        if (n < k)
            break;
        int rest = n % k;
        count += rest;
        n /= k;
        count++;
    }
    count += (n-1);
    cout << count << endl;
}