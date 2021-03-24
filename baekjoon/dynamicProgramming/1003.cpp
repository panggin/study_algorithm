#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

const int SIZE = 41;

int t, n;
pair<int,int> result[SIZE];

void setResult() 
{
    result[0].first = 1; // 0
    result[1].second = 1; // 1
    // 2 ~ 40
    for (int i=2; i<SIZE; i++) {
        result[i].first = result[i-1].first + result[i-2].first;
        result[i].second = result[i-1].second + result[i-2].second;
    }
}

int main()
{
    // 0 ~ 40 까지 0,1 카운팅
    setResult();
    // 테스트 진행
    cin >> t;
    for (int i=0; i<t; i++) {
        scanf("%d", &n);
        cout << result[n].first << " " << result[n].second << "\n";
    }
}