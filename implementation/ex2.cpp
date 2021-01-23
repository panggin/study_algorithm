// 예제 2. 시각
// 입력: 정수 n 입력(0~23)
// 출력: 00시 00분 00초부터 nn시 59분 59초까지 3이 포함되는 모든 경우의 수
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int h=0; h<=n; h++) { // hour
        for (int m=0; m<60; m++) { // minute
            for (int s=0; s<60; s++) { // second
                string time = to_string(h) + to_string(m) + to_string(s);
                int checker = time.find("3");
                if (checker != -1)
                    count++;
            }
        }
    }
    cout << count << endl;

}