#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 1000001;
int arr[SIZE] = {0,}; // 최소 연산 횟수 저장

int main()
{
    int n;
    cin >> n;
    // 1 ~ n 까지 최소 연산 횟수 계산
    arr[2] = 1; arr[3] = 1;
    for (int i=4; i<=n; i++) {
        // 연산1: 1 더하기
        arr[i] = arr[i-1] + 1; 
        if (i%3 == 0) { // 연산2: 나누기 3
            arr[i] = min(arr[i], arr[i/3] + 1);
        }
        if (i%2 == 0) { // 연산3: 나누기 2
            arr[i] = min(arr[i], arr[i/2] + 1);
        } 
    }
    // n 일때의 최소 연산 횟수 출력
    cout << arr[n] << '\n';
}