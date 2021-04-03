#include <iostream>
using namespace std;

const int MAX_N = 1000;
const int NUM = 10007;

int n;
int dp[MAX_N + 1] = {0,};

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    int size = 0;
    dp[size] = 1;
    while (size < n) {
        if (size + 1 <= n) {
            dp[size + 1] += dp[size];
            dp[size + 1] %= NUM;
        }
        if (size + 2 <= n) {
            dp[size + 2] += dp[size];
            dp[size + 2] %= NUM;
        }
        size += 1;
    }
    cout << dp[n] << "\n";
    return 0;
}