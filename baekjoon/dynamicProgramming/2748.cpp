#include <iostream>
using namespace std;

int n;
long long int fibo[91] = {0,};

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    fibo[1] = 1;
    for (int i=2; i<=n; i++) {
        fibo[i] = fibo[i-2] + fibo[i-1];
    }
    cout << fibo[n] << '\n';
}