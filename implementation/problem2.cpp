// 기출문제 2. 문자열 재정렬
// 입력: 문자열 입력 (길이: 1 ~ 10,000)
// 출력: 알파벳 오름차순 정렬 + 숫자 합
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    char inp;
    string alpha;
    int sumInt = 0;

    // 입력 받기
    while (1)
    {
        scanf("%1c", &inp);
        if (inp == '\n')
            break;
        if (inp >= '0' && inp <= '9')
        {// 입력이 숫자일 경우
            int tmp = inp - '0';
            sumInt += tmp;
        }
        else
        {// 입력이 문자일 경우
            alpha += inp;
        }
    }

    // 문자 정렬
    sort(alpha.begin(), alpha.end(), less<char>());

    // 출력
    cout << alpha << sumInt << "\n";
}