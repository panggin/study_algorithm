// 실전문제 1. 큰 수의 법칙
// 입력: 배열크기, 더할 개수, 연속가능횟수
//         배열 입력
// 출력: 위의 법칙에 따라 구한 가장 큰 수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 1000;

void display(vector<int> arr, int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// my solution
int main()
{
    int n, m, k; // 배열크기, 더할 개수, 연속가능횟수
    vector<int> arr;

    cin >> n >> m >> k;
    for (int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), greater<int>()); // 내림차순 정렬
    display(arr, n);

    int checker = 0, result = 0;
    while (m > 0) {
        int selectNum = arr[0]; // 가장 큰 수
        if (checker == k) { // 연속 가능 횟수 초과
            selectNum = arr[1]; // 두 번째로 큰 수
            checker = 0;
        }
        result += selectNum;
        checker++;
        m--;
    }
    cout << result << endl;
}

/* 미리 더할 횟수 계산하여 합 구하기
int main()
{
    int n, m, k; // 배열크기, 더할 개수, 연속가능횟수
    vector<int> arr;

    // input
    cin >> n >> m >> k;
    for (int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), greater<int>()); // 내림차순 정렬

    // calculate
    // (가장 큰 수 * k + 두 번째로 큰 수) 패턴 반복
    int first = arr[0];
    int second = arr[1];

    int cntPattern = m / (k+1); // 패턴 횟수 계산
    int rest = m % (k+1); // 나머지 계산

    int result = cntPattern*(first*k + second) + rest*first;
    cout << result << endl;
}
*/