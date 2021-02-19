#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> card;

int main()
{
    cin >> n; // 입력 처리
    for (int num=1; num<=n; num++) {
        card.push(num); // 카드 더미 만들기
    }

    while (card.size() > 1) {
        // 맨 위 카드 버리기
        card.pop();
        // 다음 카드 가장 아래로 옮기기
        int top = card.front();
        card.pop();
        card.push(top);
    }
    // 결과 출력
    cout << card.front() << "\n";
}