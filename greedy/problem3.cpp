// 기출문제 3. 문자열 뒤집기
// 입력: 0과 1로 이루어진 문자열 (문자열 길이 < 100만)
// 출력: 다솜이가 해야 하는 행동의 최소 횟수
#include <iostream>
using namespace std;

int main()
{
    string numArr;
    cin >> numArr;

    int count01[2] = {0,};
    int start = -1, tmp;
    for (int i=0; i<numArr.size(); i++)
    {
        tmp = numArr[i] - '0';
        if (start != tmp)
        {
            start = tmp;
            count01[start] += 1;
        }
    }

    int result;
    if (count01[0] == 0 || count01[1] == 0)
        result = 0;
    else if (count01[0] < count01[1])
        result = count01[0];
    else
        result = count01[1];

    cout << result << endl;
}