#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int checkNeg[10000001] = {0,};
int checkPos[10000001] = {0,};

int main()
{
    // cin 속도를 높이기 위함
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n, m, num;
    // 입력
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> num;
        if (num < 0) {
            checkNeg[abs(num)] += 1;
        } else {
            checkPos[num] += 1;
        }
    }

    // 조회
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> num;
        if (num < 0) {
            cout << checkNeg[abs(num)] << " ";
        } else {
            cout << checkPos[num] << " ";
        }
    }
}