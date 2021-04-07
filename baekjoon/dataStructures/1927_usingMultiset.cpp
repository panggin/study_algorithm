#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n, inp;
multiset<int, less<int>> number; // multiset으로 최소 힙 구현

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
                auto iter = number.begin();
                cout << *iter << "\n";
                number.erase(iter);
            }
        }
        else {
            number.insert(inp);
        }
    }
}