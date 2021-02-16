#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, result = 0;
vector<int> coins;

int main()
{
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int c;
        cin >> c;
        coins.push_back(c);
    }

    sort(coins.begin(), coins.end(), greater<int>());

    for (auto coin : coins) {
        result += (k / coin);
        k %= coin;
    }

    cout << result << "\n";
}