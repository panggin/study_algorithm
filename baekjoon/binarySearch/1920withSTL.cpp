#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n, m;
vector<int> arr;
vector<int> checkNum;

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
        if ( binary_search(arr.begin(), arr.end(), num) )
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}