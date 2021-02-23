#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n;
set<int> s;
set<int> allS = {
    1,2,3,4,5,6,7,8,9,
    10,11,12,13,14,15,
    16,17,18,19,20
};

int main()
{
    // cin 속도 up
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // 입력 처리
    cin >> n;
    string cmd; int x;
    for (int i=0; i<n; i++) {
        cin >> cmd;
        // 커멘드 처리
        if (cmd == "all") {
            s = allS;
        }
        else if (cmd == "empty") {
            s.clear();
        } else {
            cin >> x;
            if (cmd == "add") {
                s.insert(x);
            }
            else if (cmd == "remove") {
                if (s.find(x) != s.end())
                    s.erase(s.find(x));
            }
            else if (cmd == "check") {
                cout << s.count(x) << "\n";
            }
            else if (cmd == "toggle") {
                if (s.find(x) != s.end())
                    s.erase(s.find(x));
                else
                    s.insert(x);
            }
        }
    }

}