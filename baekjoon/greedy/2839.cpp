#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 5000;
int n, result = MAX;

int main()
{
    cin >> n;

    int loop = n / 5;
    for (int i=0; i<=loop; i++) {
        int tmp = n - i*5;
        int count = (tmp / 3) + i;
        if (tmp % 3 == 0)
            result = min(result, count);
    }

    if (result == MAX)
        cout << -1 << "\n";
    else
        cout << result << "\n";
}