// 예제 1. 거스름돈
// 입력 : 거슬러 줘야 할 돈
// 출력 : 거슬러 줘야 할 동전의 최소 개수 (500, 100, 50, 10 사용가능)
#include <iostream>
using namespace std;

int main()
{
    int coins[4] = {500, 100, 50, 10};
    int money, count = 0;
    cin >> money;
    for (int i=0; i<4; i++) {
        int coin = coins[i];
        count += money / coin;
        money = money % coin;
    }
    cout << count << endl;
}