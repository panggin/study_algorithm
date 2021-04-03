#include <iostream>
using namespace std;

const int MAX_N = 11;
int t, n;
int dp[MAX_N + 1] = {0,};

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    n = 0;
    dp[n] = 1;
    while (n < MAX_N) {
        if (n+1 <= MAX_N) dp[n+1] += dp[n];
        if (n+2 <= MAX_N) dp[n+2] += dp[n];
        if (n+3 <= MAX_N) dp[n+3] += dp[n];
        n += 1;
        // debugging
        // for (auto cnt : dp) {
        // cout << cnt << " ";
        // } cout << "\n";
        // end of debugging
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}