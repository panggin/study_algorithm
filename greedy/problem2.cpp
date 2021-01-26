// 기출문제 2. 곱하기 혹은 더하기
// 입력: 여러 개의 숫자로 구성된 하나의 문자열 (길이: 1 ~ 20)
// 출력: 만들 수 있는 가장 큰 수
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string numArr;
    cin >> numArr;
    int result = 0;
    for (int i=0; i<numArr.size(); i++)
    {
        char tmp = numArr[i];
        int num = tmp - '0';
        if (result == 0)
            result += num;
        else if (num == 0 || num == 1)
            result += num;
        else
            result *= num;
    }
    cout << result << "\n";
}