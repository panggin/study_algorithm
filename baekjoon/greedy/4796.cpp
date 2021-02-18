#include <iostream>
#include <cstdio>
using namespace std;

int caseCnt = 0;
int l, p, v; // 연속하는 p일 중 l일동안 사용가능, 휴가는 총 v일

int main()
{
    while (1) {
        // 입력 처리
        cin >> l >> p >> v;
        caseCnt += 1;
        if (l == 0 && p == 0 && v == 0)
            return 0;
        
        // 최대 사용 가능 일수 계산
        int result = l*(v/p);
        int rest = v % p;
        if (rest > l) {
            result += l;
        } else {
            result += rest;
        }

        // 결과 출력
        printf("Case %d: %d\n", caseCnt, result);
    }
}