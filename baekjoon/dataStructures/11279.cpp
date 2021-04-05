#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, x;
priority_queue<int, vector<int>, less<int>> pq;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
}