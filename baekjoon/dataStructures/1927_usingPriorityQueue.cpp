#include <iostream>
#include <queue>
using namespace std;

int n, inp;
priority_queue<int, vector<int>, greater<int>> number; // 우선순위 큐로 최소 힙 구현

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> inp;
        if (inp == 0) {
            if (number.empty()) {
                cout << "0\n";
            } else {
                cout << number.top() << "\n";
                number.pop();
            }
        } else {
            number.push(inp);
        }
    }
}