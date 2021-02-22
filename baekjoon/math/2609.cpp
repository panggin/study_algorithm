#include <iostream>
#include <algorithm>
using namespace std;

int a, b;
int num1, num2;

int main()
{   // 입력 처리
    cin >> a >> b;

    // 최대공약수 구하기
    num1 = min(a,b);
    while (num1 > 1) {
        if (a%num1 == 0 && b%num1 == 0)
            break;
        num1--;
    }
    // 최소공배수 구하기
    num2 = num1 * (a/num1) * (b/num1);

    // 결과 출력
    cout << num1 << "\n" << num2 << "\n";
}