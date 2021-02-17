#include <iostream>
using namespace std;

int money, result = 0;
int coins[6] = {500, 100, 50, 10, 5, 1};

int main()
{
    cin >> money;
    money = 1000 - money;
    for (auto coin : coins) {
        if (money == 0)
            break;
        result += (money / coin);
        money %= coin;
    }
    cout << result << "\n";
}