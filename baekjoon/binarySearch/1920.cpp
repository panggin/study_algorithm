#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n, m;
vector<int> arr;
vector<int> checkNum;

int binarySearch(int num)
{
    int first = 0;
    int last = arr.size() - 1;
    while (first <= last) {
        int mid = (first + last) / 2;
        // cout << "pivot: " << arr[mid] << ", num: " << num << "\n";
        if (num == arr[mid]) {
            return 1;
        } else if (num < arr[mid]) {
            last = mid - 1;
        } else if (num > arr[mid]) {
            first = mid + 1;
        }
    }
    return 0;
}

int main()
{
    // 입력 처리
    int inp;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> inp;
        arr.push_back(inp);
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> inp;
        checkNum.push_back(inp);
    }

    // 배열 정렬
    sort(arr.begin(), arr.end(), less<int>());

    // 이분 탐색
    for (auto num : checkNum) {
        int checker = binarySearch(num);
        cout << checker << "\n";
    }
}