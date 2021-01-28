// 기출문제 1. 럭키 스트레이트
// 점수를 반으로 나누어 (ex.123456 -> 123 456) 합이 같다면 사용 가능
// 입력: 점수 (10 ~ 99,999,999의 정수로 입력 - 항상 짝수 개의 숫자 입력)
// 출력: 럭키 스트레이트 사용 가능 - "LUCKY"
//       사용 불가 - "READY"
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<char> number;

// for debugging
void display()
{
    cout << "size: " << number.size() << "\n";
    for (int i=0; i<number.size(); i++)
        cout << number[i] << " ";
    cout << "\n";
}

int main()
{
    // 입력 받기
    char num = '0';
    while (1)
    {
        scanf("%1c", &num);
        if (num == '\n')
            break;
        number.push_back(num);
    }
    // display();

    int size = number.size();
    int half = size / 2;

    // 왼쪽 부분, 오른쪽 부분 합 구하기
    int cntLeft = 0, cntRight = 0;
    for (int i=0; i<half; i++)
        cntLeft += number[i];
    for (int j=half; j<size; j++)
        cntRight += number[j];

    // 두 부분 비교하여 출력
    if (cntLeft == cntRight)
        cout << "LUCKY\n";
    else
        cout << "READY\n";
}