#include <iostream>
using namespace std;

int n, num, count = 0;

// 소수일 경우 1, 아닐 경우 0 return 함수
int checkNum()
{
    if (num == 1) {
        return 0;
    } else if (num == 2) {
        return 1;
    }
    for (int n=2; n<num; n++) {
        if (num % n == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    // 입력 처리
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> num;
        // 소수 판별
        int checker = checkNum();
        if (checker == 1) {
            count += 1;
        }
    }
    // 결과 출력
    cout << count << "\n";
}